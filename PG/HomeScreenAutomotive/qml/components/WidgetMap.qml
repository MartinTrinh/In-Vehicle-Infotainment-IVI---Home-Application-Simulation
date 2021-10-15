import QtQuick 2.0
import QtLocation 5.6
import QtPositioning 5.6

MouseArea {
    id: root
    property alias widthImpl: root.implicitWidth
     property alias heightImpl: root.implicitHeight
    preventStealing: true
    propagateComposedEvents: true
    implicitWidth : 370
    implicitHeight : 320
    Rectangle {
        anchors{
            fill: parent
            margins: 10
        }
        opacity: 0.7
        color: "#111419"
    }
    Item {
        id: map
        width: parent.width
        height: parent.height
        Plugin {
            id: mapPlugin
            name: "esri" //"osm" // , "esri", ...
        }
        MapQuickItem {
            id: marker
            anchorPoint.x: image.width/4
            anchorPoint.y: image.height
            coordinate: QtPositioning.coordinate(21.03, 105.78)

            sourceItem: Image {
                id: image
                source: "qrc:/Img/Map/car_icon.png"
            }
        }
        Map {
            id: mapView
            anchors.fill: parent
            plugin: mapPlugin
            center: QtPositioning.coordinate(21.031104, 105.782809)
            zoomLevel: 14
            copyrightsVisible: false
            enabled: false
            Component.onCompleted: {
                mapView.addMapItem(marker)
            }
        }
    }
    Image {
        id: idBackgroud
        x:-2
        y:-7
        height:335
        width :375
        source: ""
    }
    states: [
        State {
            name: "Focus"
            PropertyChanges {
                target: idBackgroud
                source: "qrc:/Img/HomeScreen/bg_widget_f.png"
            }
        },
        State {
            name: "Pressed"
            PropertyChanges {
                target: idBackgroud
                source: "qrc:/Img/HomeScreen/bg_widget_p.png"
            }
        },
        State {
            name: "Normal"
            PropertyChanges {
                target: idBackgroud
                source: ""
            }
        }
    ]
//    onPressed: root.state = "Pressed"
//    onReleased:{
//        root.focus = true
//        root.state = "Focus"
//    }
//    onFocusChanged: {
//        if (root.focus == true )
//            root.state = "Focus"
//        else
//            root.state = "Normal"
//    }
//    onClicked: {
//        console.log("Open Map Screen")
//        SCREEN_CTRL.pushScreen("qrc:/qml/screens/MapScreen.qml")
//    }
}
