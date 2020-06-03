QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += qt debug warn_on

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
    Proj/Attr/hfbutton_facade_attrs.cpp \
    Proj/Attr/hfcheckbox_facade_attrs.cpp \
    Proj/Attr/hflabel_facade_attrs.cpp \
    Proj/Attr/hflineedit_facade_attrs.cpp \
    Proj/Attr/hflistwidget_facade_attrs.cpp \
    Proj/Attr/hfradiobtn_facade_attrs.cpp \
    Proj/Attr/hftabwidget_facade_attrs.cpp \
    Proj/Attr/hftext_facade_attrs.cpp \
    Proj/Attr/hfview_facade_attrs.cpp \
    Proj/Attr/hfwidget_facade_attr.cpp \
    Proj/facade/hfbutton_facade.cpp \
    Proj/hfview_facade.cpp \
    main.cpp \
    widget.cpp

HEADERS += \
    Proj/Attr/hfbutton_facade_attrs.h \
    Proj/Attr/hfcheckbox_facade_attrs.h \
    Proj/Attr/hflabel_facade_attrs.h \
    Proj/Attr/hflineedit_facade_attrs.h \
    Proj/Attr/hflistwidget_facade_attrs.h \
    Proj/Attr/hfradiobtn_facade_attrs.h \
    Proj/Attr/hftabwidget_facade_attrs.h \
    Proj/Attr/hftext_facade_attrs.h \
    Proj/Attr/hfview_facade_attrs.h \
    Proj/Attr/hfwidget_facade_attr.h \
    Proj/facade/hfbutton_facade.h \
    Proj/hfsin_hungry.h \
    Proj/hfview_facade.h \
    widget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
