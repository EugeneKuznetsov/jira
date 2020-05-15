import QtTest 1.14

TestCase {
    id: root

    function test_login_data() {
        var tests = createTemporaryQmlObject("import CuteMockServer 0.5; CuteFile { }", root);
        tests.openFile(":/data/login/test_login.json");
        return JSON.parse(tests.data);
    }

    function test_login(testData) {
        var jiraServer = createTemporaryQmlObject("import CuteMockServer 0.5; CuteMockServer { }", root);
        var jiraClient = createTemporaryQmlObject("import Jira 1.0; Jira { }", root);
        var errorSpy = createTemporaryQmlObject("import QtTest 1.14; SignalSpy { }", root);
        errorSpy.target = jiraClient;
        errorSpy.signalName = "networkErrorDetails";
        jiraServer.listen(8080);
        jiraServer.setHttpRoute("POST", "/rest/auth/1/session", testData["statusCode"], testData["contentType"], testData["content"]);
        jiraClient.options.server = "http://localhost:8080/";
        jiraClient.session(function(status) {
            compare(status.success, testData["success"]);
            compare(status.errors.length, testData["errors"]);
            jiraServer = null;
        }).login(testData["username"], testData["password"]);
        tryVerify(function() {
            return jiraServer === null;
        }, 500);
        compare(errorSpy.count, 0);
    }

    function test_issue_data() {
        var tests = createTemporaryQmlObject("import CuteMockServer 0.5; CuteFile { }", root);
        tests.openFile(":/data/issue/test_issue.json");
        return JSON.parse(tests.data);
    }

    function test_issue(testData) {
        var jiraServer = createTemporaryQmlObject("import CuteMockServer 0.5; CuteMockServer { }", root);
        var jiraClient = createTemporaryQmlObject("import Jira 1.0; Jira { }", root);
        var errorSpy = createTemporaryQmlObject("import QtTest 1.14; SignalSpy { }", root);
        errorSpy.target = jiraClient;
        errorSpy.signalName = "networkErrorDetails";
        jiraServer.listen(8080);
        jiraServer.setHttpRoute("GET", "/rest/api/2/issue/" + testData["issue"], testData["statusCode"], testData["contentType"], testData["content"], true);
        jiraClient.options.server = "http://localhost:8080/";
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
            jiraClient.issue(callback).getIssue(testData["issue"]);
        else if (testData["expand"] === undefined)
            jiraClient.issue(callback).getIssue(testData["issue"], testData["fields"]);
        else
            jiraClient.issue(callback).getIssue(testData["issue"], testData["fields"], testData["expand"]);
        tryVerify(function() {
            return jiraServer === null;
        }, 500);
        compare(errorSpy.count, 0);
    }

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

    function test_user_data() {
        var tests = createTemporaryQmlObject("import CuteMockServer 0.5; CuteFile { }", root);
        tests.openFile(":/data/user/test_user.json");
        return JSON.parse(tests.data);
    }

    function test_user(testData) {
        var jiraServer = createTemporaryQmlObject("import CuteMockServer 0.5; CuteMockServer { }", root);
        var jiraClient = createTemporaryQmlObject("import Jira 1.0; Jira { }", root);
        var errorSpy = createTemporaryQmlObject("import QtTest 1.14; SignalSpy { }", root);
        errorSpy.target = jiraClient;
        errorSpy.signalName = "networkErrorDetails";
        jiraServer.listen(8080);
        jiraServer.setHttpRoute("GET", "/rest/api/2/user" + testData["query"], testData["statusCode"], testData["contentType"], testData["content"]);
        jiraClient.options.server = "http://localhost:8080/";
        jiraClient.user(function(status, user) {
            compare(status.success, testData["success"]);
            compare(status.errors.length, testData["errors"]);
            if (testData["success"])
                compare(user.name, testData["username"]);
            else
                compare(user, null);
            jiraServer = null;
        }).getUserResource(testData["username"]);
        tryVerify(function() {
            return jiraServer === null;
        }, 500);
        compare(errorSpy.count, 0);
    }

    name: "[Jira]"
}
