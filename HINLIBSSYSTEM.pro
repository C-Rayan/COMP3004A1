QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Book.cpp \
    Magazine.cpp \
    accountstatus.cpp \
    browsecatalogue.cpp \
    catalogue.cpp \
    catalogueitem.cpp \
    digitalMedia.cpp \
    librarian.cpp \
    loan.cpp \
    patron.cpp \
    system.cpp \
    systemadmin.cpp \
    viewItem.cpp \
    viewauth.cpp \
    viewstatus.cpp

HEADERS += \
    accountstatus.h \
    browsecatalogue.h \
    catalogue.h \
    catalogueitem.h \
    librarian.h \
    loan.h \
    patron.h \
    system.h \
    systemadmin.h \
    viewItem.h \
    viewauth.h \
    viewstatus.h

FORMS += \
    browsecatalogue.ui \
    viewItem.ui \
    viewStatus.ui \
    viewauth.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    schema.sql
