#include "translate.h"
#include <QString>
#include <QStringList>

#include "helper/locale.h"
#include "translator/googletranslator.h"

Translate::Translate(QObject *parent) : QObject(parent) {
  GoogleTranslator *googleTranslator = new GoogleTranslator(this);
  connect(googleTranslator, &GoogleTranslator::translateNotify, this,
          &Translate::setTranslated);
  connect(googleTranslator, &GoogleTranslator::connectionProblem, this,
          &Translate::changeProxy);
  proxies.push_back(googleTranslator);
}

void Translate::translate() {
  if (!m_word.isEmpty() && !m_source.isEmpty() && !m_target.isEmpty()) {
    proxies.at(m_currentProxy)
        ->translate(m_word, fullStringMap[m_source], fullStringMap[m_target]);
    setError(false);
  }
}

void Translate::changeProxy() {
  if (m_currentProxy != proxies.length() - 1) {
    ++m_currentProxy;
    translate();
  } else {
    m_currentProxy = 0;
    setError(true);
  }
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

bool Translate::error() const { return m_error; }

void Translate::setError(bool error) {
  if (m_error == error)
    return;

  m_error = error;
  emit errorChanged();
}
