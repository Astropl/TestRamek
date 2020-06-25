QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Kontrahent/kontrahent.cpp \
#    Urzadzenia/Nowy dokument tekstowy.cpp \
#    Urzadzenia/Nowy dokument tekstowy.cpp \
#    Urzadzenia/Nowy dokument tekstowy.cpp \
    Timery/zegary.cpp \
    Urzadzenia/urzadzenia.cpp \
    Urzadzenia/urzadzeniadodajmodel.cpp \
    Urzadzenia/urzadzeniadodajnrseryjny.cpp \
    Urzadzenia/urzadzeniadodajproducenta.cpp \
    druga.cpp \
#    kontrahent.cpp \
    main.cpp \
    mainwindow.cpp \
    pierwsza.cpp \
    trzecia.cpp \
#    urzadzenia.cpp \
#    urzadzeniadodajmodel.cpp \
#    urzadzeniadodajnrseryjny.cpp \
#    urzadzeniadodajproducenta.cpp

HEADERS += \
    Kontrahent/kontrahent.h \
#    Urzadzenia/Nowy dokument tekstowy.h \
#    Urzadzenia/Nowy dokument tekstowy.h \
#    Urzadzenia/Nowy dokument tekstowy.h \
    Timery/zegary.h \
    Urzadzenia/urzadzenia.h \
    Urzadzenia/urzadzeniadodajmodel.h \
    Urzadzenia/urzadzeniadodajnrseryjny.h \
    Urzadzenia/urzadzeniadodajproducenta.h \
    druga.h \
#    kontrahent.h \
    mainwindow.h \
    pierwsza.h \
    trzecia.h \
#    urzadzenia.h \
#    urzadzeniadodajmodel.h \
#    urzadzeniadodajnrseryjny.h \
#    urzadzeniadodajproducenta.h

FORMS += \
    Kontrahent/kontrahent.ui \
    Urzadzenia/urzadzenia.ui \
    Urzadzenia/urzadzeniadodajmodel.ui \
    Urzadzenia/urzadzeniadodajnrseryjny.ui \
    Urzadzenia/urzadzeniadodajproducenta.ui \
    druga.ui \
#    kontrahent.ui \
    mainwindow.ui \
    pierwsza.ui \
    trzecia.ui \
#    urzadzenia.ui \
#    urzadzeniadodajmodel.ui \
#    urzadzeniadodajnrseryjny.ui \
#    urzadzeniadodajproducenta.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


