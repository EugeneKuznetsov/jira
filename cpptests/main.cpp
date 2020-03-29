#include <QTest>
#include "test_reply.h"
#include "test_session.h"

int main(int argc, char **argv) {
    QCoreApplication app(argc, argv);
    int status = 0;
    {
        ReplyTestCase testCase;
        status |= QTest::qExec(&testCase, argc, argv);
    }
    {
        SessionTestCase testCase;
        status |= QTest::qExec(&testCase, argc, argv);
    }
    return status;
}
