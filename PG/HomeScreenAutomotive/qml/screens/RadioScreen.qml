import QtQuick 2.9
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import "../components"

Item {
    id: root
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
