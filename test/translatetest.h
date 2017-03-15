#ifndef TRANSLATETEST_H
#define TRANSLATETEST_H

#include <QObject>
#include <translate.h>

class TranslateTest : public QObject {
  Q_OBJECT
public:
  explicit TranslateTest(QObject *parent = 0);

signals:

private slots:
  void getListSupportedLanguages();

private:
  Translate m_translate;
};

#endif // TRANSLATETEST_H
