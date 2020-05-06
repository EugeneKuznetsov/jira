import QtTest 1.14

TestCase {
    id: root

    function test_loginWithInvalidCallback() {
        fail("Test not implemented");
    }

    function test_login_data() {
        var tests = createTemporaryQmlObject("import CuteMockServer 0.4; CuteFile { }", root);
        tests.openFile(":/data/login/test_login.json");
        return JSON.parse(tests.data);
    }

    function test_login(testData) {
        var jiraServer = createTemporaryQmlObject("import CuteMockServer 0.4; CuteMockServer { }", root);
        var jiraClient = createTemporaryQmlObject("import Jira 1.0; Jira { }", root);
        var errorSpy = createTemporaryQmlObject("import QtTest 1.14; SignalSpy { }", root);
        errorSpy.target = jiraClient;
        errorSpy.signalName = "networkErrorDetails";
        jiraServer.listenHttp(8080);
        jiraServer.setHttpRoute("POST", "/rest/auth/1/session", testData["statusCode"], testData["contentType"], testData["content"]);
        jiraClient.options.server = "http://localhost:8080/";
        jiraClient.options.username = testData["username"];
        jiraClient.options.password = testData["password"];
        jiraClient.login(function(status) {
            compare(status.success, testData["success"]);
            compare(status.errors.length, testData["errors"]);
            jiraServer = null;
        });
        tryVerify(function() {
            return jiraServer === null;
        }, 50);
        compare(errorSpy.count, 0);
    }

    function test_loginWithNtworkError() {
        fail("Test not implemented");
    }

    function test_issueWithInvalidCallback() {
        fail("Test not implemented");
    }

    function test_issue_data() {
        return [];
    }

    function test_issue(testData) {
        fail("Test not implemented");
    }

    function test_searchWithInvalidCallback() {
    }

    function test_search_data() {
        return [];
    }

    function test_search(testData) {
        fail("Test not implemented");
    }

    function test_userWithInvalidCallback() {
        fail("Test not implemented");
    }

    function test_user_data() {
        return [];
    }

    function test_user(testData) {
        fail("Test not implemented");
    }

    name: "[Jira]"
}
