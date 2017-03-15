#pragma once

class QString;

class GoogleTranslator {
public:
  QString translate(QString word, QString source, QString target);
};