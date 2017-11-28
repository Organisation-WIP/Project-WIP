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
    frameworkExtension/interpolation.cpp \
    frameworkExtension/interpolation/sineinterpolation.cpp \
    frameworkExtension/observee.cpp \
    frameworkExtension/observerevent.cpp \
    models/tile.cpp \
    models/tileplane.cpp \
    models/tilewithsquare.cpp \
    models/world.cpp

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
    frameworkExtension/interpolation.h \
    frameworkExtension/interpolation/sineinterpolation.h \
    frameworkExtension/observer.h \
    frameworkExtension/observee.h \
    frameworkExtension/observerevent.h \
    models/tile.h \
    models/tileplane.h \
    models/tilewithsquare.h \
    models/world.h
