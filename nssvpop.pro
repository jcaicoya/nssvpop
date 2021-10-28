QT += widgets

CONFIG += c++17
CONFIG += static

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        CorridorItem.cpp \
        DisplayView.cpp \
        DisplayWidget.cpp \
        FlatItem.cpp \
        FlatsState.cpp \
        MainWindow.cpp \
        OptionsWidget.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    CorridorItem.h \
    DisplayView.h \
    DisplayViewConstants.h \
    DisplayWidget.h \
    FlatItem.h \
    FlatsState.h \
    MainWindow.h \
    OptionsWidget.h
