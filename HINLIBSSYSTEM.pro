QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Book.cpp \
    Magazine.cpp \
    browsecatalogue.cpp \
    catalogue.cpp \
    catalogueitem.cpp \
    digitalMedia.cpp \
    loan.cpp \
    main.cpp \
    patron.cpp \
    system.cpp \
    viewauth.cpp

HEADERS += \
    browsecatalogue.h \
    catalogue.h \
    catalogueitem.h \
    loan.h \
    patron.h \
    system.h \
    viewauth.h

FORMS += \
    browsecatalogue.ui \
    viewauth.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
