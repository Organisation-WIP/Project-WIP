include(frameworkPath)
include($$FRAMEWORK_PATH)

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
    frameworkExtension/animationbone.cpp \
    frameworkExtension/graph.cpp \
    frameworkExtension/interpolation/linearinterpolation.cpp \
    frameworkExtension/interpolation.cpp

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
    frameworkExtension/animationbone.h \
    frameworkExtension/graph.h \
    frameworkExtension/interpolation/interpolationmethod.h \
    frameworkExtension/interpolation/linearinterpolation.h \
    frameworkExtension/interpolation.h
