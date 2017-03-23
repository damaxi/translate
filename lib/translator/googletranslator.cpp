#include "googletranslator.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QNetworkReply>
#include <QObject>
#include <QRegularExpression>
#include <QString>
#include <QUrl>
#include <QVariantList>

static QString TRANSLATOR_URL =
    "https://translate.googleapis.com/translate_a/single?client=gtx&sl="
    "%1"
    "&tl="
    "%2"
    "&dt=t&q="
    "%3";

GoogleTranslator::GoogleTranslator(QObject *parent)
    : QObject(parent), AbstractTranslator() {
  connect(&m_network, &QNetworkAccessManager::finished, this,
          &GoogleTranslator::handle);
}

void GoogleTranslator::translate(QString word, QString source, QString target) {
  QString preparedUrl = TRANSLATOR_URL.arg(source).arg(target).arg(word);
  m_network.get(QNetworkRequest(QUrl(preparedUrl)));
}

void GoogleTranslator::handle(QNetworkReply *reply) {
  if (reply->error() == QNetworkReply::NoError) {
    QString replyString(reply->readAll());
    replyString.replace("[", "");
    replyString.replace("]", "");
    QStringList keys = replyString.split(",", QString::SkipEmptyParts);
    QString translated;
    if (keys.length() == 4) {
      translated = keys.first();
      translated.replace("\"", "");
    }

    emit translateNotify(translated);
  } else {
    emit connectionProblem();
  }
}
