import QtQuick 2.6
import QtQml 2.3
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.1
Item{
    property bool  draweState: false
    signal drawerOn()
    Image {
        anchors.fill: parent
        source: "qrc:/Img/Media/title.png"
        Image{
            id:iconDisplayDrawerId
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter
            width: 30
            height: 30
            source: "qrc:/Img/Media/closeDawer.png"
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    if(draweState)
                    {
                        console.log("close list")
                        // add code close drawer
                        iconDisplayDrawerId.source = "qrc:/Img/Media/closeDawer.png"
                        draweState = false
                    }else{
                        console.log("open list")
                        // add code colse drawer
                        iconDisplayDrawerId.source = "qrc:/Img/Media/onDrawer.png"
                        draweState = true
                    }
                    drawerOn() // emit signal used to
                }
            }
        }
        Text{
            anchors.left:iconDisplayDrawerId.right
            anchors.leftMargin: 5
            anchors.verticalCenter: parent.verticalCenter
            text: TRANSLATOR_MODEL.STR_MEDIA_PLAYLIST + TRANSLATOR_MODEL.emptyString
            color: "white"
            font.pixelSize: 30
        }

        Text {
            id: headerTitleText
            text: TRANSLATOR_MODEL.STR_MEDIA_TITLE + TRANSLATOR_MODEL.emptyString
            anchors.centerIn: parent
            color: "white"
            font.pixelSize: 46
        }
    }
}
