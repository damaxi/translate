TEMPLATE = subdirs

SUBDIRS += \
    lib \
    test

test.depends = lib
