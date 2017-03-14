#pragma once

#include <QMap>

enum class Locale { en, pl };

static QMap<QString, Locale> fullStringMap({{"english", Locale::en},
                                            {"polish", Locale::pl}});