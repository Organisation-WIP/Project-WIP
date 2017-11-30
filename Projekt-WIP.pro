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
    frameworkExtension/interpolation.cpp \
    frameworkExtension/observee.cpp \
    frameworkExtension/observerevent.cpp \
    frameworkExtension/spline.cpp

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
    frameworkExtension/interpolation.h \
    frameworkExtension/observer.h \
    frameworkExtension/observee.h \
    frameworkExtension/observerevent.h \
    frameworkExtension/spline.h
