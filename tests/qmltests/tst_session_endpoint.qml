import QtTest 1.14

TestCase {
    id: root

    function test_login_data() {
        var tests = createTemporaryQmlObject("import CuteMockServer 0.5; CuteFile { }", root);
        tests.openFile(":/data/session/test_login.json");
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
        jiraClient.server = "http://localhost:8080/";
        var session = jiraClient.session(function(status) {
            compare(status.success, testData["success"]);
            compare(status.errors.length, testData["errors"]);
            jiraServer = null;
        });
        session.username = testData["username"];
        session.password = testData["password"];
        session.login();
        tryVerify(function() {
            return jiraServer === null;
        }, 500);
        compare(errorSpy.count, 0);
    }

    name: "[Session Endpoint]"
}
