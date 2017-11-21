include("/home/flo/Nextcloud/Game-Engineering/Semester3/Computergrafik/Uebungen/FrameworkLinux/Common.pri")

TARGET = Projekt-WIP
SOURCES += \
    myscene.cpp \
    models/tower.cpp \
    models/enemyship.cpp \
    models/playership.cpp

//HEADERS  +=

FORMS += \
    dockwidget.ui

HEADERS += \
    models/tower.h \
    models/enemyship.h \
    models/playership.h
