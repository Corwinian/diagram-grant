#include <QtCore/QString>
#include <QtTest/QtTest>

class GrantTests : public QObject
{
    Q_OBJECT

public:
    GrantTests();

private Q_SLOTS:
    void testDb();
};

GrantTests::GrantTests()
{
}

void GrantTests::testDb()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(GrantTests);

#include "tst_GrantTests.moc"
