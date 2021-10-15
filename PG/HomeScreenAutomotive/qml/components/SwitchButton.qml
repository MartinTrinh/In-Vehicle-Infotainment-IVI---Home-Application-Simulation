import QtQuick 2.0

MouseArea {
    id: root
    property string icon_on: ""
    property string icon_off: ""
    property int status: 0 //0-Off || 1-On
    signal buttonIsOn()
    signal buttonIsOff()
    Image {
        id: img
        width: parent.width
        height: parent.height
        source: (root.status == 1)? icon_on : icon_off
    }
    onClicked: {
        if(root.status == 0)
        {
            root.status = 1
            root.buttonIsOn() // emit signal mode on
        }else{
            root.status = 1
            root.buttonIsOff() // emit signal mode off
        }
    }
}
