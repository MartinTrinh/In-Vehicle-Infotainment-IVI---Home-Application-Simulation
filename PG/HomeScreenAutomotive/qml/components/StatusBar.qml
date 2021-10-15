import QtQuick 2.9
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import AppEnums 1.0
Item {
    id: root
    property alias buttonBackToScreen: buttonBackToScreenId.visible
    property string timerDisplay: "--:--"
    Timer {
        id: timerOS
        interval: 1
        repeat: true
        running: true
        onTriggered: {
            var currentTime = new Date()
            timerDisplay = Qt.formatTime(currentTime, "hh:mm")
        }
    }
    AppButton{
        id:buttonBackToScreenId
        anchors.left: parent.left
        width: 100
        height: 56
        icon:"qrc:/Img/StatusBar/btn_top_back"
        onClicked: {
            console.log("RETURN SCREEN")
            SCREEN_CTRL.popToRoot();
        }
    }
    Image{
        id:leftStickId
        anchors.left: buttonBackToScreenId.right
        anchors.leftMargin: 315
        height: 56
        source: "qrc:/Img/StatusBar/status_divider.png"
    }
    Text {
        id:timerShowId
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: leftStickId.right
        anchors.leftMargin: 30
        color: "white"
        font.pointSize: 20
        font.weight: Font.Bold
        text: timerDisplay
    }
    Image{
        id:betweenStickId
        anchors.left: timerShowId.right
        anchors.leftMargin: 40
        height: 56
        source: "qrc:/Img/StatusBar/status_divider.png"
    }
    Text {
        id: dateShowId
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: betweenStickId.right
        anchors.leftMargin: 30
        font.pointSize: 20
        font.weight: Font.Bold
        color:"white"
        text: Qt.formatDateTime(new Date(), "MMM.d")
    }
    Image{
        id:rightStickId
        anchors.left: dateShowId.right
        anchors.leftMargin: 29
        height: 56
        source: "qrc:/Img/StatusBar/status_divider.png"
    }
}
