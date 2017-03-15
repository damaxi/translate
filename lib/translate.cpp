#include "translate.h"
#include <QString>
#include <QStringList>
#include <QStringList>

#include "helper/locale.h"

using namespace std;

Translate::Translate(QObject *parent) : QObject(parent) {}

QString Translate::translate(QString &origin) { return QString("Hello"); }

QStringList Translate::listSupportedLanguages() const {

  return fullStringMap.keys();
}

QString Translate::word() const { return m_word; }

void Translate::setWord(QString &word) {
  if (m_word == word)
    return;

  m_word = word;
  emit notifyWord();
}

QString Translate::source() const { return m_source; }

void Translate::setSource(QString &source) {
  if (m_source == source)
    return;

  m_source = source;
  emit notifySource();
}

QString Translate::target() const { return m_target; }

void Translate::setTarget(QString &target) {
  if (m_target == target)
    return;

  m_target = target;
  emit notifyTarget();
}
