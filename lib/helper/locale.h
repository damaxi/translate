#ifndef LOCALE_H
#define LOCALE_H

#include <QMap>

enum class Locale { en, pl };

static QMap<QString, Locale> fullStringMap({{"english", Locale::en},
                                            {"polish", Locale::pl}});

#endif // LOCALE_H
