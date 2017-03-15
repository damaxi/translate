#include <QString>
#include <QStringList>
#include <QStringList>
#include <iostream>
#include <translator.h>

#include "locale.h"

using namespace std;

Translator::Translator(QObject *parent) : QObject(parent) {}

QString Translator::translate(QString &origin) { return QString("Hello"); }

QStringList Translator::listSupportedLanguages() const {

  return fullStringMap.keys();
}

QString Translator::word() const { return m_word; }

void Translator::setWord(QString &word) {
  if (m_word == word)
    return;

  m_word = word;
  emit notifyWord();
}

QString Translator::source() const { return m_source; }

void Translator::setSource(QString &source) {
  if (m_source == source)
    return;

  m_source = source;
  emit notifySource();
}

QString Translator::target() const { return m_target; }

void Translator::setTarget(QString &target) {
  if (m_target == target)
    return;

  m_target = target;
  emit notifyTarget();
}