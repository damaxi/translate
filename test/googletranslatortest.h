#ifndef GOOGLETRANSLATORTEST_H
#define GOOGLETRANSLATORTEST_H

#include "translator/googletranslator.h"
#include <QObject>
#include <QSignalSpy>

class GoogleTranslatorTest : public QObject {
  Q_OBJECT
public:
  explicit GoogleTranslatorTest(QObject *parent = 0);

private slots:
  void translate();
  void translateComplicated();
  void translateNonExistance();

private:
  GoogleTranslator m_googleTranslator;
  QSignalSpy m_signal;
};

#endif // GOOGLETRANSLATORTEST_H
