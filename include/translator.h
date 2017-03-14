#pragma once

#include <QObject>

class QString;
class QStringList;
enum class Locale;

class Translator : QObject {
  Q_PROPERTY(QString word READ word WRITE setWord NOTIFY notifyWord)
  Q_PROPERTY(QString source READ source WRITE setSource NOTIFY notifySource)
  Q_PROPERTY(QString target READ target WRITE setTarget NOTIFY notifyTarget)
public:
  Translator(QObject *parent = 0);

  QString translate(QString &origin);

  QStringList listSupportedLanguages() const;

  QString word() const;
  void setWord(QString &word);

  QString source() const;
  void setSource(QString &source);

  QString target() const;
  void setTarget(QString &target);

signals:
  void notifyWord();
  void notifySource();
  void notifyTarget();

private:
  QString m_word;
  QString m_source;
  QString m_target;
};