#include "translatetest.h"

#include <QtTest>

TranslateTest::TranslateTest(QObject *parent)
    : QObject(parent), m_translate(),
      m_signal(&m_translate, &Translate::notifyTarget) {}

void TranslateTest::getListSupportedLanguages() {
  QStringList languagesList = m_translate.listSupportedLanguages();
  QVERIFY(languagesList.at(0) == "english");
  QVERIFY(languagesList.at(1) == "polish");
}

void TranslateTest::translate() {
  m_translate.setWord("cat");
  m_translate.setSource("english");
  m_translate.setTarget("polish");
  // QVERIFY(m_signal.wait(1000));
  QVERIFY(m_translate.target() == "kot");
}
