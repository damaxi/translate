#include "googletranslatortest.h"
#include "translatetest.h"
#include <QCoreApplication>
#include <QtTest/QtTest>

int main(int argc, char *argv[]) {
  QCoreApplication app(argc, argv);
  int ret = 0;
  TranslateTest translateTest;
  ret += QTest::qExec(&translateTest, argc, argv);

  GoogleTranslatorTest googleTranslatorTest;
  ret += QTest::qExec(&googleTranslatorTest, argc, argv);

  app.exec();
  return ret;
}
