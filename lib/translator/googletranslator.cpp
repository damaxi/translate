#include "googletranslator.h"

#include <QNetworkReply>
#include <QNetworkReply>
#include <QObject>
#include <QString>
#include <QUrl>

static QString TRANSLATOR_URL =
    "https://translate.googleapis.com/translate_a/single?client=gtx&sl="
    "%1"
    "&tl="
    "%2"
    "&dt=t&q="
    "%3";

GoogleTranslator::GoogleTranslator(QObject *parent) : QObject(parent) {
  connect(&m_network, &QNetworkAccessManager::finished, this,
          &GoogleTranslator::handle);
}

QString GoogleTranslator::translate(QString word, QString source,
                                    QString target) {
  QString preparedUrl = TRANSLATOR_URL.arg(source).arg(target).arg(word);
  m_network.get(QNetworkRequest(QUrl(preparedUrl)));
  return preparedUrl;
}

void GoogleTranslator::handle(QNetworkReply *reply) {
  emit translateNotify("dupa");
}
