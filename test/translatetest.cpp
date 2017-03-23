#include "translatetest.h"

#include <QDebug>
#include <QThread>
#include <QtTest>

TranslateTest::TranslateTest(QObject *parent)
    : QObject(parent), m_translate(),
      m_signal(&m_translate, &Translate::notifyTranslated) {}

void TranslateTest::getListSupportedLanguages() {
  QStringList languagesList = m_translate.listSupportedLanguages();
  QVERIFY(languagesList.at(0) == "english");
  QVERIFY(languagesList.at(1) == "polish");
}

void TranslateTest::translate() {
  m_translate.setWord("cat");
  m_translate.setSource("english");
  m_translate.setTarget("polish");
  int i = 0;
  while (!m_signal.length() && i++ < 50) {
    QTest::qWait(1000);
  }
  QVERIFY(m_translate.translated() == "kot");
}
