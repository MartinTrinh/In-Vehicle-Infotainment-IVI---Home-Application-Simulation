#ifndef APPDEFINES_H
#define APPDEFINES_H

#include <QObject>
#include <QMap>

#define MAIN_QML    "qrc:/qml/main.qml"

class AppEnums: public QObject
{
    Q_OBJECT

    Q_ENUMS(SCREEN_ID)
    Q_ENUMS(LANGUAGE)

public:
    enum SCREEN_ID: int
    {
        // home screen
        SCREEN_ID_HOME,
        // map screen
        SCREEN_ID_MAP,
        // video screen
        SCREEN_ID_VIDEO_PLAYER,
        // music screen
        SCREEN_ID_MUSIC_PLAYER,
        //telephone screen
        SCREEN_ID_TELEPHONE,
        //radio screen
        SCREEN_ID_RADIO,
        //setting screen
        SCREEN_ID_SETTING,
        //climate screen
        SCREEN_ID_CLIMATE
    };
    enum LANGUAGE{ EN = 1, VN, KO };
};

const QMap<int, QString> ScreenNameMap
{
    // home screen
    {AppEnums::SCREEN_ID_HOME, "qrc:/qml/screens/HomeScreen.qml"},
    // map screen
    {AppEnums::SCREEN_ID_MAP, "qrc:/qml/screens/MapScreen.qml"},
    // video screen
    {AppEnums::SCREEN_ID_VIDEO_PLAYER, "qrc:/qml/screens/VideoScreen.qml"},
    // music screen
    {AppEnums::SCREEN_ID_MUSIC_PLAYER, "qrc:/qml/screens/MusicScreen.qml"},
    //telephone screen
    {AppEnums::SCREEN_ID_TELEPHONE, "qrc:/qml/screens/TelephoneScreen.qml"},
    //radio screen
    {AppEnums::SCREEN_ID_RADIO, "qrc:/qml/screens/RadioScreen.qml"},
    //setting screen
    {AppEnums::SCREEN_ID_SETTING, "qrc:/qml/screens/SettingScreen.qml"},
    //climate screen
    {AppEnums::SCREEN_ID_CLIMATE, "qrc:/qml/screens/ClimateScreen.qml"}
};

#endif // APPDEFINES_H
