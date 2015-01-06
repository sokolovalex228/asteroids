TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

INCLUDEPATH += src
SOURCES += main.cpp

HEADERS += src/*.h

SOURCES += src/GameAsteroids.cpp

include(deployment.pri)
qtcAddDeployment()

LIBS += -lX11 -lXrandr -lGL -lglut

DISTFILES += \
	task.txt

