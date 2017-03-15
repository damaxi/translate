#ifndef GOOGLETRANSLATORTEST_H
#define GOOGLETRANSLATORTEST_H

#include "threadsafeqsignalspy.h"
#include "translator/googletranslator.h"
#include <QObject>

class GoogleTranslatorTest : public QObject {
  Q_OBJECT
public:
  explicit GoogleTranslatorTest(QObject *parent = 0);

private slots:
  void translate();

private:
  GoogleTranslator m_googleTranslator;
  ThreadsafeQSignalSpy m_signal;
};

#endif // GOOGLETRANSLATORTEST_H
