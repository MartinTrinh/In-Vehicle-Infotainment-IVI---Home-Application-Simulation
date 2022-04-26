QT +=  quickcontrols2  multimedia dbus xml
QT += location
CONFIG += c++11

# getdata from dbus
DBUS_INTERFACES += Dbus/climate_data.xml

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += PROJECT_PATH=\"\\\"$${_PRO_FILE_PWD_}/\\\"\"

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \
    ./src \
    ./src/common \
    ./src/controller\
    ./src/model

HEADERS += \
    src/common/appdefines.h \
    src/common/loghelper.h \
    src/controller/applicationcontroller.h \
    src/controller/climatecontroller.h \
    src/controller/mediacontroller.h \
    src/controller/screencontroller.h \
    src/controller/translatorcontroller.h \
    src/controller/xmlreader.h \
    src/model/applicationsmodel.h \
    src/model/climate_data_interface.h \
    src/model/climatemodel.h \
    src/model/mediamodel.h \
    src/model/screenmodel.h \
    src/model/translatormodel.h \
    src/appengine.h

SOURCES += \
    src/controller/applicationcontroller.cpp \
    src/controller/climatecontroller.cpp \
    src/controller/mediacontroller.cpp \
    src/controller/screencontroller.cpp \
    src/controller/translatorcontroller.cpp \
    src/controller/xmlreader.cpp \
    src/model/applicationsmodel.cpp \
    src/model/climatemodel.cpp \
    src/model/mediamodel.cpp \
    src/model/screenmodel.cpp \
    src/model/translatormodel.cpp \
    src/appengine.cpp \
    src/main.cpp \

RESOURCES += \
    ImageSrc.qrc \
    localization.qrc \
    qml.qrc

TRANSLATIONS += \
    localization/AppLanguage_en.ts \
    localization/AppLanguage_ko.ts \
    localization/AppLanguage_vi.ts

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =
#/usr/lib/x86_64-linux-gnu/qt5/qml

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

LIBS += -ltag

DISTFILES += \
    applications.xml \
    src/Dbus/climate_data.xml

