#ifndef GOOGLE_H
#define GOOGLE_H

#include "abstracttranslator.h"

QT_BEGIN_NAMESPACE
class QString;
class QNetworkReply;
QT_END_NAMESPACE

class GoogleTranslator : public QObject, public AbstractTranslator {

  Q_OBJECT
public:
  GoogleTranslator(QObject *parent = 0);

  void translate(QString word, QString source, QString target) override;

signals:
  void translateNotify(QString translated);
  void connectionProblem();

private:
  void handle(QNetworkReply *reply) override;
};

#endif // GOOGLE_H
