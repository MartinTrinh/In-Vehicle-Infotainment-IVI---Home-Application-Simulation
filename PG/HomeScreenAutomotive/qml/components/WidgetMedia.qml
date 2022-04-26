import QtQuick 2.0
import QtGraphicalEffects 1.0

MouseArea {
    id: root
    Rectangle {
        anchors{
            fill: parent
            margins: 10
        }
        opacity: 0.7
        color: "#111419"
    }
    Image {
        id: bgBlur
        width: 370
        height: 320
        source: {
            if (MEDIA_MODEL.rowCount() > 0 && MEDIA_MODEL.rowCount() >  PLAYLIST.currentIndex)
                return MEDIA_MODEL.data(MEDIA_MODEL.index(PLAYLIST.currentIndex,0), 260)
            else
                return "qrc:/Img/Media/cover_art.jpg"
        }
    }
    FastBlur {
        anchors.fill: bgBlur
        source: bgBlur
        radius: 18
    }
    Image {
        id: idBackgroud
        source: ""
        x:-4
        y:-7
        height:335
        width :375

    }
    Text {
        id: title
        anchors.horizontalCenter: parent.horizontalCenter
        y: 40
        text: TRANSLATOR_MODEL.STR_WIDGET_USBMUSIC +  TRANSLATOR_MODEL.emptyString
        color: "white"
        font.pixelSize: 20
    }
    Image {
        id: bgInner
        anchors.centerIn: parent
        width: 150
        height: 150
        source: {
            if (MEDIA_MODEL.rowCount() > 0 && MEDIA_MODEL.rowCount() >  PLAYLIST.currentIndex)
                return MEDIA_MODEL.data(MEDIA_MODEL.index(PLAYLIST.currentIndex,0), 260)
            else
                return "qrc:/Img/HomeScreen/cover_art.jpg"
        }
    }
    //    Image{
    //        x:201
    //        y:119
    //        width: 258
    //        height: 258
    //        source: "qrc:/Img/HomeScreen/widget_media_album_bg.png"
    //    }
    Text {
        id: txtSinger
        anchors.top: bgInner.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        //horizontalAlignment: Text.AlignHCenter
        text: {
            if (MEDIA_MODEL.rowCount() > 0 && MEDIA_MODEL.rowCount() >  PLAYLIST.currentIndex)
                return MEDIA_MODEL.data(MEDIA_MODEL.index(PLAYLIST.currentIndex,0), 258)
        }
        color: "white"
        font.pixelSize: 18
    }
    Text {
        id: txtTitle
        anchors.top:txtSinger.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        //horizontalAlignment: Text.AlignHCenter
        text: {
            if (MEDIA_MODEL.rowCount() > 0 && MEDIA_MODEL.rowCount() >  PLAYLIST.currentIndex)
                return MEDIA_MODEL.data(MEDIA_MODEL.index(PLAYLIST.currentIndex,0), 257)
        }
        color: "white"
        font.pixelSize: 20
    }
    Image{
        id: imgDuration
        anchors.top: txtTitle.bottom
        anchors.left: parent.left
        anchors.leftMargin: 20
        width: parent.width - 40
        height: 2
        source: "qrc:/Img/HomeScreen/widget_media_pg_n.png"
    }
    Image{
        id: imgPosition
        anchors.top: txtTitle.bottom
        anchors.left: parent.left
        anchors.leftMargin: 20
        width: 0
        height: 2
        source: "qrc:/Img/HomeScreen/widget_media_pg_s.png"
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
//        console.log("Open Music Screen")
//        SCREEN_CTRL.pushScreen("qrc:/qml/screens/MusicScreen.qml")
//    }

    Connections{
        target: PLAYLIST
        onCurrentIndexChanged:{
            if (MEDIA_MODEL.rowCount() > 0 && MEDIA_MODEL.rowCount() >  PLAYLIST.currentIndex) {
                bgBlur.source = MEDIA_MODEL.data(myModel.index(PLAYLIST.currentIndex,0), 260)
                bgInner.source = MEDIA_MODEL.data(myModel.index(PLAYLIST.currentIndex,0), 260)
                txtSinger.text = MEDIA_MODEL.data(myModel.index(PLAYLIST.currentIndex,0), 258)
                txtTitle.text = MEDIA_MODEL.data(myModel.index(PLAYLIST.currentIndex,0), 257)
            }
           console.log("current Index changed")
        }
    }

    Connections{
        target: PLAYER
        onDurationChanged:{
            //imgDuration.width = parent.width - 50
            imgPosition.width = 0
        }
        onPositionChanged: {
            imgPosition.width = (PLAYER.position / PLAYER.duration) * imgDuration.width;
        }
    }
}
