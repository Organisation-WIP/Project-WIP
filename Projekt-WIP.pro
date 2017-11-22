include(frameworkPath)

TARGET = Projekt-WIP
SOURCES += \
    myscene.cpp \
    models/tower.cpp \
    models/enemyship.cpp \
    models/playership.cpp \
    frameworkExtension/model.cpp \
    frameworkExtension/bone.cpp \
    frameworkExtension/animation.cpp \
    frameworkExtension/keyframe.cpp \
    frameworkExtension/keyframeboneinfo.cpp

//HEADERS  +=

FORMS += \
    dockwidget.ui

HEADERS += \
    models/tower.h \
    models/enemyship.h \
    models/playership.h \
    frameworkExtension/model.h \
    frameworkExtension/bone.h \
    frameworkExtension/animation.h \
    frameworkExtension/keyframe.h \
    frameworkExtension/keyframeboneinfo.h
