QT       += core gui
QT +=network
QT += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    account.cpp \
    bankenvironment.cpp \
    bankmenu.cpp \
    card.cpp \
    cardreaderdll.cpp \
    client.cpp \
    events.cpp \
    main.cpp \
    mainwindow.cpp \
    welcome.cpp

HEADERS += \
    account.h \
    bankenvironment.h \
    bankmenu.h \
    card.h \
    cardreaderdll.h \
    client.h \
    events.h \
    mainwindow.h \
    welcome.h

FORMS += \
    account.ui \
    bankmenu.ui \
    card.ui \
    client.ui \
    events.ui \
    mainwindow.ui \
    welcome.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
