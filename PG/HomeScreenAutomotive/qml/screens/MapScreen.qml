import QtQuick 2.9
import QtLocation 5.15
import QtPositioning 5.15
import "../components"

Item {
    anchors.fill: parent
    Image{
        anchors.fill: parent
        source: "qrc:/Img/bg_full.png"
    }
    StatusBar{
        id:headerAreaId
        width: parent.width
        height: 60
    }
    Text {
        id: titleAppScreenId
        anchors.top: headerAreaId.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        text: TRANSLATOR_MODEL.STR_APP_MAP  + TRANSLATOR_MODEL.emptyString
        color: "white"
        font.pointSize: 20
        font.weight: Font.Bold
        height: 50
    }
    Rectangle{
        anchors.top: titleAppScreenId.bottom
        width: parent.width
        height: parent.height - 58
        Plugin{
            id:maplugin
            name: "esri"
        }
        Map{
            id: mapView
            anchors.fill: parent
            plugin: maplugin
            center: QtPositioning.coordinate(21.031104, 105.782809)
            zoomLevel: 20
        }
    }
}
