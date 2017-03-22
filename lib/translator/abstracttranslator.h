#ifndef ABSTRACTTRANSLATOR_H
#define ABSTRACTTRANSLATOR_H

#include <QNetworkAccessManager>

QT_BEGIN_NAMESPACE
class QString;
class QNetworkReply;
QT_END_NAMESPACE

class AbstractTranslator {
public:
  virtual ~AbstractTranslator() = default;

  virtual QString translate(QString word, QString source, QString target) = 0;

protected:
  virtual void handle(QNetworkReply *reply) = 0;

  QNetworkAccessManager m_network;
};

#endif // ABSTRACTTRANSLATOR_H
