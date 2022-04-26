import QtQuick 2.0

import "../screens"

Item {
    id: root
    anchors.fill: parent
    focus: true
    /*
         HomeScreen
         MapScreen
         ClimateScreen
         MusicScreen
         VideoScreen
         PhoneScreen
         RadioScreen
         SettingScreen
    */
    //property  string screen: ""

    //=========HomeScreen item=============================
    property string mapWidgetId: ""
    property string climateWidgetId: ""
    property string musicWidgetId: ""
    property string appAreaId: ""
    property string backButtonId: ""

    function keyboardEvent(screen)
    {
        switch(screen)
        {
        case "HomeScreen":
            console.log("key event on homescreen")
            if (Keys.onDigit1Pressed(Qt.Key_1))
            {
               // call open map screen
                console.log("Open Map Screen")
                SCREEN_CTRL.pushScreen("qrc:/qml/screens/MapScreen.qml")

            }else if(Keys.onDigit2Pressed(Qt.Key_2))
            {
                //call open climate screen
                console.log("Open Climate Screen")
                SCREEN_CTRL.pushScreen("qrc:/qml/screens/ClimateScreen.qml")
            }else if(Keys.onDigit3Pressed(Qt.Key_3))
            {
                // call open music screen
                console.log("Open Music Screen")
                SCREEN_CTRL.pushScreen("qrc:/qml/screens/MusicScreen.qml")
            }
            break
        case "MapScreen":
        case "ClimateScreen":
        case "MusicScreen":
        case "VideoScreen":
        case "PhoneScreen":
        case "RadioScreen":
        case "SettingScreen":
            break
        }
    }
}
