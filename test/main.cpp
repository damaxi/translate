#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <QStringList>
#include <translator.h>

TEST_CASE("A method should return locales", "[locales]") {
  Translator translator;
  QStringList locales = translator.listSupportedLanguages();
  REQUIRE(locales[0] == "english");
  REQUIRE(locales[1] == "polish");
}