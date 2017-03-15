#include "googletranslatortest.h"
#include <QList>
#include <QThread>
#include <QVariant>
#include <QtTest>

GoogleTranslatorTest::GoogleTranslatorTest(QObject *parent)
    : QObject(parent), m_googleTranslator(),
      m_signal(&m_googleTranslator, &GoogleTranslator::translateNotify) {}

void GoogleTranslatorTest::translate() {
  QThread thread;
  m_googleTranslator.translate("cat", "en", "pl");
  m_signal.moveToThread(&thread);
  QVERIFY(m_signal.wait(10000));
  QList<QVariant> arguments = m_signal.takeFirst();
  QVERIFY(arguments.at(0).type() == QVariant::String);
  QVERIFY(arguments.at(0).toString() == "dupa");
  qDebug() << "Hej";
}
