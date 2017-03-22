#ifndef TRANSLATETEST_H
#define TRANSLATETEST_H

#include <QObject>
#include <QSignalSpy>
#include <translate.h>

class TranslateTest : public QObject {
  Q_OBJECT
public:
  explicit TranslateTest(QObject *parent = 0);

signals:

private slots:
  void getListSupportedLanguages();
  void translate();

private:
  Translate m_translate;
  QSignalSpy m_signal;
};

#endif // TRANSLATETEST_H
