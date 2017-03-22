#include "translate.h"
#include <QString>
#include <QStringList>

#include "helper/locale.h"
#include "translator/googletranslator.h"

using namespace std;

Translate::Translate(QObject *parent) : QObject(parent) {
  GoogleTranslator *googleTranslator = new GoogleTranslator(this);
  connect(googleTranslator, &GoogleTranslator::translateNotify, this,
          &Translate::setTranslated);
  proxies.push_back(googleTranslator);
}

void Translate::translate() {
  if (!m_word.isEmpty() && !m_source.isEmpty() && !m_target.isEmpty())
    proxies.at(m_currentProxy)
        ->translate(m_word, fullStringMap[m_source], fullStringMap[m_target]);
}

QStringList Translate::listSupportedLanguages() const {

  return fullStringMap.keys();
}

QString Translate::word() const { return m_word; }

void Translate::setWord(QString word) {
  if (m_word == word)
    return;

  m_word = word;
  translate();
  emit notifyWord();
}

QString Translate::source() const { return m_source; }

void Translate::setSource(QString source) {
  if (m_source == source)
    return;

  m_source = source;
  translate();
  emit notifySource();
}

QString Translate::target() const { return m_target; }

void Translate::setTarget(QString target) {
  if (m_target == target)
    return;

  m_target = target;
  translate();
  emit notifyTarget();
}

QString Translate::translated() const { return m_translated; }

void Translate::setTranslated(QString translated) {
  if (m_translated == translated)
    return;

  m_translated = translated;
  emit notifyTranslated();
}
