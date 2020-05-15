import QtTest 1.14

TestCase {
    id: root

    function test_search_data() {
        var tests = createTemporaryQmlObject("import CuteMockServer 0.5; CuteFile { }", root);
        tests.openFile(":/data/search/test_search.json");
        return JSON.parse(tests.data);
    }

    function test_search(testData) {
        var jiraServer = createTemporaryQmlObject("import CuteMockServer 0.5; CuteMockServer { }", root);
        var jiraClient = createTemporaryQmlObject("import Jira 1.0; Jira { }", root);
        var errorSpy = createTemporaryQmlObject("import QtTest 1.14; SignalSpy { }", root);
        errorSpy.target = jiraClient;
        errorSpy.signalName = "networkErrorDetails";
        jiraServer.listen(8080);
        jiraServer.setHttpRoute("POST", "/rest/api/2/search", testData["statusCode"], testData["contentType"], testData["content"], true);
        jiraClient.options.server = "http://localhost:8080/";
        var callback = function cb(status, issues, total) {
            compare(status.success, testData["success"]);
            compare(status.errors.length, testData["jiraErrors"]);
            if (testData["expectedTotal"] !== undefined)
                compare(total, testData["expectedTotal"]);

            if (testData["expectedListSize"] !== undefined)
                compare(issues.length, testData["expectedListSize"]);

            if (testData["expectedLastIssueKey" !== undefined])
                compare(issues[issues.length - 1].key === testData["expectedLastIssueKey"]);

            if (testData["expectedFields"] !== undefined)
                verify(issues[0].fields[testData["expectedFields"]] !== undefined);

            if (testData["unexpectedFields"] !== undefined)
                verify(issues[0].fields[testData["unexpectedFields"]] === undefined);

            if (testData["expectedExpand"] !== undefined)
                verify(issues[0].expandedFields[testData["expectedExpand"]] !== undefined);

            if (testData["unexpectedExpand"] !== undefined)
                verify(issues[0].expandedFields[testData["unexpectedExpand"]] === undefined);

            jiraServer = null;
        };
        jiraClient.search(callback).search(testData["query"],
                                           (testData["startAt"] === undefined) ? 0 : testData["startAt"],
                                           (testData["maxResults"] === undefined) ? 50 : testData["maxResults"],
                                           (testData["fields"] === undefined) ? "*navigable" : testData["fields"],
                                           (testData["expand"] === undefined) ? "" : testData["expand"]);
        tryVerify(function() {
            return jiraServer === null;
        }, 500);
        compare(errorSpy.count, 0);
    }

    name: "[Search Endpoint]"
}
