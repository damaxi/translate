#include "googletranslatortest.h"
#include <QList>
#include <QThread>
#include <QVariant>
#include <QtTest>

GoogleTranslatorTest::GoogleTranslatorTest(QObject *parent)
    : QObject(parent), m_googleTranslator(),
      m_signal(&m_googleTranslator, &GoogleTranslator::translateNotify) {}

void GoogleTranslatorTest::translate() {
  m_googleTranslator.translate("cat", "en", "pl");
  QVERIFY(m_signal.wait(10000));
  QList<QVariant> arguments = m_signal.takeFirst();
  QVERIFY(arguments.at(0).type() == QVariant::String);
  QVERIFY(arguments.at(0).toString() == "kot");
}

void GoogleTranslatorTest::translateComplicated() {
  m_googleTranslator.translate("This is a cat", "en", "pl");
  QVERIFY(m_signal.wait(10000));
  QList<QVariant> arguments = m_signal.takeFirst();
  QVERIFY(arguments.at(0).type() == QVariant::String);
  QVERIFY(arguments.at(0).toString() == "To jest kot");
}
/*
We cann't avoid this
*/
void GoogleTranslatorTest::translateNonExistance() {
  m_googleTranslator.translate("catt", "en", "pl");
  QVERIFY(m_signal.wait(10000));
  QList<QVariant> arguments = m_signal.takeFirst();
  QVERIFY(arguments.at(0).type() == QVariant::String);
  QVERIFY(arguments.at(0).toString() == "Catt");
}
