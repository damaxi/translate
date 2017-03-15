#include "translatetest.h"

#include <QtTest>

TranslateTest::TranslateTest(QObject *parent)
    : QObject(parent), m_translate() {}

void TranslateTest::getListSupportedLanguages() {
  QStringList languagesList = m_translate.listSupportedLanguages();
  QVERIFY(languagesList.at(0) == "english");
  QVERIFY(languagesList.at(1) == "polish");
}
