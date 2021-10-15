import QtQuick 2.0

MouseArea {
    id: root
    property string icon :""
    property string title : ""
    Image {
        id: idBackgroud
        width: root.width
        height: root.height
        source: icon + "_n.png"
    }
    Text {
        id: appTitle
        anchors.horizontalCenter: parent.horizontalCenter
        y: 150
        text: title
        font.pixelSize: 30
        color: "white"
    }

    states: [
        State {
            name: "Focus"
            PropertyChanges {
                target: idBackgroud
                source: icon + "_f.png"
            }
        },
        State {
            name: "Pressed"
            PropertyChanges {
                target: idBackgroud
                source: icon + "_p.png"
            }
        },
        State {
            name: "Normal"
            PropertyChanges {
                target: idBackgroud
                source: icon + "_n.png"
            }
        }
    ]
    onPressed: root.state = "Pressed"
    onReleased: {
        root.focus = true
        root.state = "Focus"
    }
    onFocusChanged: {
        if (root.focus == true )
            root.state = "Focus"
        else
            root.state = "Normal"
    }
}
