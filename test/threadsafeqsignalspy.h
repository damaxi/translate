#ifndef THREADSAFEQSIGNALSPY_H
#define THREADSAFEQSIGNALSPY_H

#include <QSignalSpy>
#include <QTime>

struct ThreadsafeQSignalSpy : QSignalSpy {
  template <typename Func>
  ThreadsafeQSignalSpy(
      const typename QtPrivate::FunctionPointer<Func>::Object *obj,
      Func signal0)
      : QSignalSpy(obj, signal0) {}

  bool wait(int timeout) {
    auto origCount(count());
    QTime timer;
    timer.start();

    while (count() <= origCount && timer.elapsed() < timeout)
      QCoreApplication::instance()->processEvents(QEventLoop::AllEvents,
                                                  timeout / 10);
    return count() > origCount;
  }
};

#endif // THREADSAFEQSIGNALSPY_H
