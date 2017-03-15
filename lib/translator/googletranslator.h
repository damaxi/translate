#ifndef GOOGLE_H
#define GOOGLE_H

#include <QNetworkAccessManager>

QT_BEGIN_NAMESPACE
class QString;
class QNetworkReply;
QT_END_NAMESPACE

class GoogleTranslator : public QObject {

  Q_OBJECT
public:
  GoogleTranslator(QObject *parent = 0);

  QString translate(QString word, QString source, QString target);

  void handle(QNetworkReply *reply);

signals:
  void translateNotify(QString translated);

private:
  QNetworkAccessManager m_network;
};

#endif // GOOGLE_H
