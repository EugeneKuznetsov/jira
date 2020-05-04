#include <QTest>
#include "qmltypes/internal/responsestatus.h"
#include "test_response_status.h"

void ResponseStatusTestCase::invalidStatusCodeAndSimpleError()
{
    ResponseStatus status(-1, "no-json-error-text", {{200, true}, {404, false}});
    QCOMPARE(status.property("success").toBool(), false);
    QCOMPARE(status.property("code").toInt(), -1);
    QVERIFY(status.property("errors").toStringList().empty());
}

void ResponseStatusTestCase::invalidStatusCodeAndJsonError()
{
    ResponseStatus status(20000, "{\"errorMessages\":[\"Some error\"],\"errors\":{}}", {{200, true}, {404, false}});
    QCOMPARE(status.property("success").toBool(), false);
    QCOMPARE(status.property("code").toInt(), 20000);
    QVERIFY(status.property("errors").toStringList().empty());
}

void ResponseStatusTestCase::validSuccessfulStatusCodeAndInvalidStatusMap()
{
    ResponseStatus status(200, "Some successful json data", {});
    QCOMPARE(status.property("success").toBool(), false);
    QCOMPARE(status.property("code").toInt(), 200);
    QVERIFY(status.property("errors").toStringList().empty());
}

void ResponseStatusTestCase::validSuccessfulStatusCodeAndValidStatusMap()
{
    ResponseStatus status(200, "Some successful json data", {{200, true}, {404, false}});
    QCOMPARE(status.property("success").toBool(), true);
    QCOMPARE(status.property("code").toInt(), 200);
    QVERIFY(status.property("errors").toStringList().empty());
}

void ResponseStatusTestCase::validErrorStatusCodeAndValidStatusMap()
{
    ResponseStatus status(400, "{\"errorMessages\":[\"Some error 1\", \"Some error 2\"],\"errors\":{}}", {{200, true}, {400, false}});
    QCOMPARE(status.property("success").toBool(), false);
    QCOMPARE(status.property("code").toInt(), 400);
    QVERIFY(status.property("errors").toStringList().size() == 2);
    QVERIFY(status.property("errors").toStringList()[0] == "Some error 1");
    QVERIFY(status.property("errors").toStringList()[1] == "Some error 2");
}

QTEST_GUILESS_MAIN(ResponseStatusTestCase)
