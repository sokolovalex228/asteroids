TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

INCLUDEPATH += src
SOURCES += main.cpp \
	test.c \
	src/Sprite.cpp \
	src/Hero.cpp \
	src/Asteroid.cpp \
	src/Texture.cpp \
	src/Utils.cpp \
	src/Atlas.cpp \
	src/Screen1.cpp \
	src/InfoSprite.cpp \
	src/Object.cpp \
    src/Button.cpp

HEADERS += src/*.h \
	src/Sprite.h \
	src/Hero.h \
	src/Asteroid.h \
	src/Screen1.h \
	src/InfoSprite.h \
	src/Object.h \
    src/Button.h

SOURCES += src/GameAsteroids.cpp
SOURCES += src/VBO.cpp

include(deployment.pri)
qtcAddDeployment()

LIBS += -lGL -lGLESv2 -lpng12 -ljansson -lSDL2

DISTFILES += \
	task.txt

