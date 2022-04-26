import QtQuick 2.9
import "../components"

Item {
    id: root

    Component.onCompleted: {
        //===============updte focus area=====================================================================
        root.forceActiveFocus()
    }
    Keys.onPressed: {
        console.log("keys.onpress: " + event.key)
        switch(event.key)
        {
        case Qt.Key_1:
            console.log("key_1 on press")
            SCREEN_CTRL.pushScreen("qrc:/qml/screens/MapScreen.qml")
            break
        case Qt.Key_2:
            console.log("key_2 onpress")
            SCREEN_CTRL.pushScreen("qrc:/qml/screens/ClimateScreen.qml")
            break
        case Qt.Key_3:
            console.log("key_3 onpress")
            SCREEN_CTRL.pushScreen("qrc:/qml/screens/MusicScreen.qml")
            break
        case Qt.Key_Escape:
            console.log("key_esc onpress")
            SCREEN_CTRL.popToRoot();
            break
        default:
            console.log("key not support")
            break
        }
    }
    Image{
        anchors.fill: parent
        source: "qrc:/Img/bg_full.png"
    }
    StatusBar{
        id:headerAreaId
        width: parent.width
        height: 60
    }
}
