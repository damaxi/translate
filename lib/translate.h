#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include "translator/abstracttranslator.h"
#include <QObject>

QT_BEGIN_NAMESPACE
class QString;
class QStringList;
enum class Locale;
QT_END_NAMESPACE

class Translate : public QObject {
  Q_OBJECT
  Q_PROPERTY(QString word READ word WRITE setWord NOTIFY notifyWord)
  Q_PROPERTY(QString source READ source WRITE setSource NOTIFY notifySource)
  Q_PROPERTY(QString target READ target WRITE setTarget NOTIFY notifyTarget)
  Q_PROPERTY(QString translated READ translated WRITE setTranslated NOTIFY
                 notifyTranslated)
  Q_PROPERTY(bool error READ error WRITE setError NOTIFY errorChanged)
public:
  Translate(QObject *parent = 0);
  virtual ~Translate() = default;

  Q_INVOKABLE QStringList listSupportedLanguages() const;

  QString word() const;
  void setWord(QString word);

  QString source() const;
  void setSource(QString source);

  QString target() const;
  void setTarget(QString target);

  QString translated() const;
  void setTranslated(QString translated);

  bool error() const;
  void setError(bool error);

signals:
  void notifyWord();
  void notifySource();
  void notifyTarget();
  void notifyTranslated();
  void errorChanged();

private:
  void translate();
  void changeProxy();

  QVector<AbstractTranslator *> proxies;

  QString m_word;
  QString m_source;
  QString m_target;
  QString m_translated;
  bool m_error;
  int m_currentProxy = 0;
};

#endif // TRANSLATOR_H
