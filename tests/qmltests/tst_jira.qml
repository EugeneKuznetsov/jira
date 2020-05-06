import QtTest 1.14

TestCase {
    id: root

    function test_loginWithInvalidCallback() {
        var jiraClient = createTemporaryQmlObject("import Jira 1.0; Jira { }", root);
        compare(jiraClient.login(null), false);
    }

    function test_loginWithNetworkError_data() {
        var tests = createTemporaryQmlObject("import CuteMockServer 0.5; CuteFile { }", root);
        tests.openFile(":/data/login/test_loginWithNetworkError.json");
        return JSON.parse(tests.data);
    }

    // ToDo: Make reusable code for other Jira endpoints (issue, search, user),
    // since other networkError tests are doing exactly the same things
    function test_loginWithNetworkError(testData) {
        var jiraServer = createTemporaryQmlObject("import CuteMockServer 0.5; CuteMockServer { }", root);
        var jiraClient = createTemporaryQmlObject("import Jira 1.0; Jira { }", root);
        var errorSpy = createTemporaryQmlObject("import QtTest 1.14; SignalSpy { }", root);
        var callbackExecuted = false;
        errorSpy.target = jiraClient;
        errorSpy.signalName = "networkErrorDetails";
        jiraServer.listen(testData["serverPort"], testData["secureServer"]);
        jiraServer.setHttpRoute("POST", "/rest/auth/1/session", testData["statusCode"], "", "");
        jiraClient.options.server = testData["server"];
        verify(jiraClient.login(function(status) {
            compare(status.success, testData["loginSuccess"]);
            compare(status.errors.length, testData["jiraErrors"]);
            callbackExecuted = true;
        }));
        tryVerify(function() {
            return (callbackExecuted || errorSpy.count);
        }, 3000);
        compare(callbackExecuted, testData["callbackExecuted"]);
        compare(errorSpy.count, testData["networkErrorCount"]);
    }

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
        jiraClient.options.username = testData["username"];
        jiraClient.options.password = testData["password"];
        verify(jiraClient.login(function(status) {
            compare(status.success, testData["success"]);
            compare(status.errors.length, testData["errors"]);
            jiraServer = null;
        }));
        tryVerify(function() {
            return jiraServer === null;
        }, 500);
        compare(errorSpy.count, 0);
    }

    function test_issueWithInvalidCallback() {
        var jiraClient = createTemporaryQmlObject("import Jira 1.0; Jira { }", root);
        compare(jiraClient.issue(null, ""), false);
    }

    function test_issueWithNetworkError_data() {
        var tests = createTemporaryQmlObject("import CuteMockServer 0.5; CuteFile { }", root);
        tests.openFile(":/data/issue/test_issueWithNetworkError.json");
        return JSON.parse(tests.data);
    }

    // ToDo: Make reusable code for other Jira endpoints (login, search, user),
    // since other networkError tests are doing exactly the same things
    function test_issueWithNetworkError(testData) {
        var jiraServer = createTemporaryQmlObject("import CuteMockServer 0.5; CuteMockServer { }", root);
        var jiraClient = createTemporaryQmlObject("import Jira 1.0; Jira { }", root);
        var errorSpy = createTemporaryQmlObject("import QtTest 1.14; SignalSpy { }", root);
        var callbackExecuted = false;
        errorSpy.target = jiraClient;
        errorSpy.signalName = "networkErrorDetails";
        jiraServer.listen(testData["serverPort"], testData["secureServer"]);
        jiraServer.setHttpRoute("POST", "/rest/auth/1/session", testData["statusCode"], "", "");
        jiraClient.options.server = testData["server"];
        verify(jiraClient.issue(function(status) {
            compare(status.success, testData["loginSuccess"]);
            compare(status.errors.length, testData["jiraErrors"]);
            callbackExecuted = true;
        }, ""));
        tryVerify(function() {
            return (callbackExecuted || errorSpy.count);
        }, 3000);
        compare(callbackExecuted, testData["callbackExecuted"]);
        compare(errorSpy.count, testData["networkErrorCount"]);
    }

    function test_issue_data() {
        fail("Test not implemented");
        return [];
    }

    function test_issue(testData) {
        fail("Test not implemented");
    }

    function test_searchWithInvalidCallback() {
        var jiraClient = createTemporaryQmlObject("import Jira 1.0; Jira { }", root);
        compare(jiraClient.search(null, ""), false);
    }

    function test_searchWithNetworkError_data() {
        var tests = createTemporaryQmlObject("import CuteMockServer 0.5; CuteFile { }", root);
        tests.openFile(":/data/search/test_searchWithNetworkError.json");
        return JSON.parse(tests.data);
    }

    // ToDo: Make reusable code for other Jira endpoints (issue, login, user),
    // since other networkError tests are doing exactly the same things
    function test_searchWithNetworkError(testData) {
        var jiraServer = createTemporaryQmlObject("import CuteMockServer 0.5; CuteMockServer { }", root);
        var jiraClient = createTemporaryQmlObject("import Jira 1.0; Jira { }", root);
        var errorSpy = createTemporaryQmlObject("import QtTest 1.14; SignalSpy { }", root);
        var callbackExecuted = false;
        errorSpy.target = jiraClient;
        errorSpy.signalName = "networkErrorDetails";
        jiraServer.listen(testData["serverPort"], testData["secureServer"]);
        jiraServer.setHttpRoute("POST", "/rest/auth/1/session", testData["statusCode"], "", "");
        jiraClient.options.server = testData["server"];
        verify(jiraClient.search(function(status) {
            compare(status.success, testData["loginSuccess"]);
            compare(status.errors.length, testData["jiraErrors"]);
            callbackExecuted = true;
        }, ""));
        tryVerify(function() {
            return (callbackExecuted || errorSpy.count);
        }, 3000);
        compare(callbackExecuted, testData["callbackExecuted"]);
        compare(errorSpy.count, testData["networkErrorCount"]);
    }

    function test_search_data() {
        fail("Test not implemented");
        return [];
    }

    function test_search(testData) {
        fail("Test not implemented");
    }

    function test_userWithInvalidCallback() {
        var jiraClient = createTemporaryQmlObject("import Jira 1.0; Jira { }", root);
        compare(jiraClient.user(null, ""), false);
    }

    function test_userWithNetworkError_data() {
        var tests = createTemporaryQmlObject("import CuteMockServer 0.5; CuteFile { }", root);
        tests.openFile(":/data/user/test_userWithNetworkError.json");
        return JSON.parse(tests.data);
    }

    // ToDo: Make reusable code for other Jira endpoints (issue, search, login),
    // since other networkError tests are doing exactly the same things
    function test_userWithNetworkError(testData) {
        var jiraServer = createTemporaryQmlObject("import CuteMockServer 0.5; CuteMockServer { }", root);
        var jiraClient = createTemporaryQmlObject("import Jira 1.0; Jira { }", root);
        var errorSpy = createTemporaryQmlObject("import QtTest 1.14; SignalSpy { }", root);
        var callbackExecuted = false;
        errorSpy.target = jiraClient;
        errorSpy.signalName = "networkErrorDetails";
        jiraServer.listen(testData["serverPort"], testData["secureServer"]);
        jiraServer.setHttpRoute("POST", "/rest/auth/1/session", testData["statusCode"], "", "");
        jiraClient.options.server = testData["server"];
        verify(jiraClient.user(function(status) {
            compare(status.success, testData["loginSuccess"]);
            compare(status.errors.length, testData["jiraErrors"]);
            callbackExecuted = true;
        }, ""));
        tryVerify(function() {
            return (callbackExecuted || errorSpy.count);
        }, 3000);
        compare(callbackExecuted, testData["callbackExecuted"]);
        compare(errorSpy.count, testData["networkErrorCount"]);
    }

    function test_user_data() {
        fail("Test not implemented");
        return [];
    }

    function test_user(testData) {
        fail("Test not implemented");
    }

    name: "[Jira]"
}
