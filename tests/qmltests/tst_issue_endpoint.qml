import QtTest 1.14

TestCase {
    id: root

    function test_getIssue_data() {
        var tests = createTemporaryQmlObject("import CuteMockServer 0.5; CuteFile { }", root);
        tests.openFile(":/data/issue/test_issue.json");
        return JSON.parse(tests.data);
    }

    function test_getIssue(testData) {
        var jiraServer = createTemporaryQmlObject("import CuteMockServer 0.5; CuteMockServer { }", root);
        var jiraClient = createTemporaryQmlObject("import Jira 1.0; Jira { }", root);
        var errorSpy = createTemporaryQmlObject("import QtTest 1.14; SignalSpy { }", root);
        errorSpy.target = jiraClient;
        errorSpy.signalName = "networkErrorDetails";
        jiraServer.listen(8080);
        jiraServer.setHttpRoute("GET", "/rest/api/2/issue/" + testData["issue"], testData["statusCode"], testData["contentType"], testData["content"], true);
        jiraClient.server = "http://localhost:8080/";
        var callback = function cb(status, issue) {
            compare(status.success, testData["success"]);
            compare(status.errors.length, testData["errors"]);
            if (testData["fields"] !== undefined) {
                var fieldCount = 0;
                for (var field in issue.fields) fieldCount++
                compare(fieldCount, testData["fieldCount"]);
            }
            if (testData["expand"] !== undefined && testData["expandField"] !== undefined)
                verify(issue.expandedFields[testData["expandField"]] !== undefined);

            jiraServer = null;
        };
        if (testData["fields"] === undefined)
            jiraClient.issue(callback).getIssue(testData["issue"], "", "", "", false);
        else if (testData["expand"] === undefined)
            jiraClient.issue(callback).getIssue(testData["issue"], testData["fields"], "", "", false);
        else
            jiraClient.issue(callback).getIssue(testData["issue"], testData["fields"], testData["expand"], "", false);
        tryVerify(function() {
            return jiraServer === null;
        }, 500);
        compare(errorSpy.count, 0);
    }

    name: "[Issue Endpoint]"
}
