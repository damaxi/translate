#ifndef GOOGLE_H
#define GOOGLE_H

class QString;

class GoogleTranslator {
public:
  QString translate(QString word, QString source, QString target);
};

#endif // GOOGLE_H
