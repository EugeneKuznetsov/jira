import QtTest 1.14

TestCase {
    id: root

    function test_getUser_data() {
        var tests = createTemporaryQmlObject("import CuteMockServer 0.5; CuteFile { }", root);
        tests.openFile(":/data/user/test_user.json");
        return JSON.parse(tests.data);
    }

    function test_getUser(testData) {
        var jiraServer = createTemporaryQmlObject("import CuteMockServer 0.5; CuteMockServer { }", root);
        var jiraClient = createTemporaryQmlObject("import Jira 1.1; Jira { }", root);
        var errorSpy = createTemporaryQmlObject("import QtTest 1.14; SignalSpy { }", root);
        errorSpy.target = jiraClient;
        errorSpy.signalName = "networkErrorDetails";
        jiraServer.listen(8080);
        jiraServer.setHttpRoute("GET", "/rest/api/2/user" + testData["query"], testData["statusCode"], testData["contentType"], testData["content"]);
        jiraClient.server = "http://localhost:8080/";
        jiraClient.user(function(status, user) {
            compare(status.success, testData["success"]);
            compare(status.errors.length, testData["errors"]);
            if (testData["success"])
                compare(user.name, testData["username"]);
            else
                compare(user, null);
            jiraServer = null;
        }).getUser(testData["username"], "");
        tryVerify(function() {
            return jiraServer === null;
        }, 500);
        compare(errorSpy.count, 0);
    }

    name: "[User Endpoint]"
}
