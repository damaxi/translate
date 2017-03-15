#include "googletranslatortest.h"
#include "translatetest.h"
#include <QtTest/QtTest>

int main(int argc, char *argv[]) {
  int ret = 0;
  TranslateTest translateTest;
  ret += QTest::qExec(&translateTest, argc, argv);

  GoogleTranslatorTest googleTranslatorTest;
  ret += QTest::qExec(&googleTranslatorTest, argc, argv);

  return ret;
}
