import QtQuick 2.9
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import "../components"

Item {
    id: root
    //==============variable initialaze application=========================================
    property bool initPlayer: true
    Component.onCompleted: {
//        if(!MEDIA_CTRL.checkPlayerState())
//        {
            imageListSongDisplayId.currentIndex = PLAYLIST.currentIndex
        //}
        console.log("componet is completed")
    }
    Connections{
        target: PLAYER
        onCurrentIndexChanged: {
            console.trace()
            listSongBackgoundId.mediaPlaylistView.currentIndex = PLAYLIST.currentIndex
            imageListSongDisplayId.currentIndex = PLAYLIST.currentIndex
            console.log(listSongBackgoundId.mediaPlaylistView.currentIndex)
        }
    }
    //======================================================================================
    Image{
        anchors.fill: parent
        source: "qrc:/Img/bg_full.png"
    }
    StatusBar{
        id:headerAreaId
        width: parent.width
        height: 60
    }
    //=========================================title app===========================================//
    Header{
        id:headerItem
        anchors.top: headerAreaId.bottom
        width: parent.width
        height: 50
        onDrawerOn: {
            if(headerItem.draweState)
            {
                listSongBackgoundId.open()
                backgoundMainControllerId.width = mainAppControllerId.width - listSongBackgoundId.width
                console.log("DRAWER OPEN")
            }else{
                listSongBackgoundId.close()
                backgoundMainControllerId.width = mainAppControllerId.width
                console.log("DRAWER CLOSE")
            }
        }
    }
    //===========================main app displaying=============================================//
    Image {
        id: mainAppControllerId
        anchors.top: headerItem.bottom
        anchors.bottom: parent.bottom
        width: parent.width
        source: "qrc:/Img/Media/background.png"
        //=======================list songs========================================================//
        Drawer {
            id: listSongBackgoundId
            property alias  mediaPlaylistView : mediaPlaylist
            interactive: false
            modal: false
            x:0
            y: headerItem.height + headerAreaId.height
            width:  0.18 * parent.width
            height: parent.height - headerItem.height
            background:Image {
                anchors.fill: parent
                source: "qrc:/Img/Media/playlist_item.png"
            }
            ListView {
                id: mediaPlaylist
                width: parent.width
                height: parent.height
                model: MEDIA_MODEL
                clip: true
                focus: true
                delegate: Image {
                    property variant myData: model
                    id: displaySongNameListId
                    width: parent.width
                    height: 50
                    source: "qrc:/Img/Media/playlist.png"
                    Text {
                        id: songNameListId
                        anchors.right: parent.right
                        anchors.rightMargin: 10
                        anchors.verticalCenter: parent.verticalCenter
                        text: TitleRole
                        color: "white"
                        font.bold: true
                        font.pointSize: 12
                    }
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            mediaPlaylist.currentIndex = index
                            // add code here
                            PLAYLIST.setCurrentIndex(index)
                            console.log(index)
                        }
                        onPressed: {
                            displaySongNameListId.source = "qrc:/Img/Media/hold.png"
                        }
                        onReleased: {
                            displaySongNameListId.source = "qrc:/Img/Media/playlist.png"
                        }
                    }
                }
                highlight: Image {
                    source: "qrc:/Img/Media/playlist_item.png"
                    Image {
                        anchors.left: parent.left
                        anchors.leftMargin: 15
                        anchors.verticalCenter: parent.verticalCenter
                        source: "qrc:/Img/Media/playing.png"
                    }
                }
                ScrollBar.vertical: ScrollBar {
                    parent: mediaPlaylist.parent
                    anchors.top: mediaPlaylist.top
                    anchors.left: mediaPlaylist.right
                    anchors.bottom: mediaPlaylist.bottom
                }
                onCurrentIndexChanged: {
                    imageListSongDisplayId.currentIndex = mediaPlaylist.currentIndex
                    console.log("current_changed")
                }
            }
        }

        //=======================main controller====================================================//
        Image {
            id: backgoundMainControllerId
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            width: parent.width
            source: "qrc:/Img/Media/background.png"
            //=====================animation text==============================================================//            NumberAnimation {
            NumberAnimation {
                id: textChangeAni
                property: "opacity"
                from: 0
                to: 1
                duration: 400
                easing.type: Easing.InOutQuad
            }
            Row{
                id: hederDercoIconId
                anchors.top: parent.top
                width: parent.width
                height: 50
                Text {
                    id: songCurrentInfoId
                    anchors.left: parent.left
                    anchors.leftMargin: 10
                    text: listSongBackgoundId.mediaPlaylistView.currentItem.myData.TitleRole +
                          "<br>" + listSongBackgoundId.mediaPlaylistView.currentItem.myData.SingerRole
                    font.bold: true
                    font.pointSize: 12
                    color: "white"
                    onTextChanged: {
                        textChangeAni.target = songCurrentInfoId
                        textChangeAni.restart()
                    }
                }
                Image{
                    id: iconMusicId
                    anchors.right: countPLayListId.left
                    anchors.rightMargin: 5
                    source: "qrc:/Img/Media/music.png"
                }
                Text{
                    id: countPLayListId
                    anchors.right: parent.right
                    anchors.rightMargin: 15
                    text: APP_MODEL.rowCount()
                    font.bold: true
                    font.pointSize: 12
                    color: "white"
                }
            }
            //===================pathView======================================================//
            Component {
                id: appDelegate
                Item {
                    width: parent.width
                    height: parent.height * 3 / 4
                    scale: PathView.iconScale
                    Image {
                        id: myIcon
                        y: 20
                        anchors.horizontalCenter: parent.horizontalCenter
                        width: parent.width * 2/ 8
                        height: parent.height
                        source: AlbumArtRole
                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked:{
                            listSongBackgoundId.mediaPlaylistView.currentIndex = index
                            MEDIA_CTRL.setCurrenIndex(index)
                            console.log(index)
                        }
                    }
                }
            }
            PathView {
                id: imageListSongDisplayId
                anchors.top: hederDercoIconId.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.leftMargin: 200
                anchors.topMargin: 50
                anchors.margins: 20
                preferredHighlightBegin: 0.5
                preferredHighlightEnd: 0.5
                height: parent.height * 3.5 / 5 - hederDercoIconId.height
                width: parent.width *  3 /4
                focus: true
                model: MEDIA_MODEL
                delegate: appDelegate
                pathItemCount: 3
                highlightRangeMode: PathView.StrictlyEnforceRange
                path: Path {
                    startX: 10
                    startY: 120
                    PathAttribute { name: "iconScale"; value: 0.5 }
                    PathLine {/* x:  450 ; y: 100*/ x: imageListSongDisplayId.width * 1.75 / 4  ; y:100}
                    PathAttribute { name: "iconScale"; value: 1.0 }
                    PathLine { /*x:  900 ; y: 120*/ x:imageListSongDisplayId.width * 3.2 / 4  ; y :120}
                    PathAttribute { name: "iconScale"; value: 0.5 }
                }
                onCurrentIndexChanged: {
                    listSongBackgoundId.mediaPlaylistView.currentIndex = imageListSongDisplayId.currentIndex
                    //MEDIA_CTRL.setCurrenIndex(imageListSongDisplayId.currentIndex)
                    console.log("PathView current index is: " + imageListSongDisplayId.currentIndex)
                }
            }
            //================================group button controller, process bar for song================================//
            RowLayout{
                id: processId
                anchors.top: imageListSongDisplayId.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.leftMargin: 20
                width: parent.width
                height:  parent.height * 0.75 / 5 - hederDercoIconId.height
                spacing: 2
                Text {
                    id: currentTimeId
                    Layout.preferredWidth: parent.width / 10
                    Layout.leftMargin: 20
                    text: MEDIA_CTRL.currentTime
                    font.bold: true
                    font.pointSize: 12
                }
                Slider{
                    id: progressBarId
                    Layout.leftMargin: - 30
                    Layout.preferredWidth: parent.width* 8 / 10
                    from: 0
                    to: MEDIA_CTRL.duarationTotal
                    value: MEDIA_CTRL.currentDuaration
                    background: Rectangle {
                        x: -10
                        y: progressBarId.topPadding + progressBarId.availableHeight / 2 - height / 2
                        implicitWidth: 200
                        implicitHeight: 4
                        width: progressBarId.availableWidth
                        height: implicitHeight
                        radius: 2
                        color: "gray"
                        Rectangle {
                            width: progressBarId.visualPosition * parent.width
                            height: parent.height
                            color: "white"
                            radius: 2
                        }
                    }
                    handle: Image {
                        anchors.verticalCenter: parent.verticalCenter
                        x: -10 +  progressBarId.visualPosition * (progressBarId.availableWidth - width)
                        y: progressBarId.topPadding + progressBarId.availableHeight / 2 - height / 2
                        source: "qrc:/Img/Media/point.png"
                        Image {
                            anchors.centerIn: parent
                            source: "qrc:/Img/Media/center_point.png"
                        }
                    }
                    onMoved: {
                        console.log(progressBarId.value)
                        MEDIA_CTRL.setPosition(progressBarId.value)
                    }
                    onToChanged: {
                        if(PLAYER.state === PLAYER.PlayingState)
                        {
                            playPauseId.source = "qrc:/Img/Media/pause.png"
                        }

                        console.log("duaration changed")
                    }
                    onValueChanged: {
                        if(PLAYER.state === PLAYER.PlayingState && progressBarId.value !== 0)
                        {
                            playPauseId.source = "qrc:/Img/Media/play.png"
                        }
                        if(progressBarId.value === 0)
                        {
                            playPauseId.source = "qrc:/Img/Media/pause.png"
                        }

                    }
                }
                Text {
                    id: duarationTimeId
                    Layout.preferredWidth: parent.width / 10
                    text: MEDIA_CTRL.totalTime
                    font.bold: true
                    font.pointSize: 12
                }
            }
            //======================button control list song=======================================================
            RowLayout{
                id: groupButtonControllId
                anchors.top: processId.bottom
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                Layout.alignment: Qt.AlignVCenter
                Layout.margins: 50
                width: parent.width
                height:  parent.height * 0.5 / 5 - hederDercoIconId.height
                SwitchButton{
                    id: buttonShuffleId
                    Layout.margins: 15
                    Layout.preferredWidth:parent.width / 16
                    Layout.preferredHeight: parent.height / 2
                    icon_on: "qrc:/Img/Media/shuffleOn.png"
                    icon_off: "qrc:/Img/Media/shuffleOff.png"
                    onButtonIsOn:{
                        buttonLoopId.status = 0
                        MEDIA_CTRL.switchModePlaylist(4)
                        console.trace()
                    }
                    onButtonIsOff:{
                        buttonShuffleId.status = 0
                        MEDIA_CTRL.switchModePlaylist()
                        console.trace()
                    }
                }
                Image{
                    id: buttonPreviousId
                    Layout.leftMargin: parent.width * 5/ 16
                    Layout.preferredWidth: parent.width / 16
                    Layout.preferredHeight: parent.height * 1.2/ 2
                    source: "qrc:/Img/Media/prevRelease.png"
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            console.log("PREVIOUS SONG")
                            MEDIA_CTRL.previous()
                        }
                        onPressed: {
                            buttonPreviousId.source = "qrc:/Img/Media/prevPress.png"
                        }
                        onReleased: {
                            buttonPreviousId.source = "qrc:/Img/Media/prevRelease.png"
                        }
                    }
                }
                Image{
                    id: playPauseId
                    Layout.alignment: Qt.AlignHCenter
                    Layout.preferredWidth: parent.width / 16
                    Layout.preferredHeight: parent.height * 1.2/ 2
                    source: "qrc:/Img/Media/pause.png"
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            console.trace()
                            if(MEDIA_CTRL.checkPlayerState())
                            {
                                MEDIA_CTRL.pausePlayer()
                                playPauseId.source = "qrc:/Img/Media/pause.png"
                                console.log(" pause")
                            }else
                            {
                                if(initPlayer){
                                    MEDIA_CTRL.initPlayer()
                                    initPlayer = false
                                }else{
                                    MEDIA_CTRL.continuePlayer();
                                }
                                playPauseId.source = "qrc:/Img/Media/play.png"
                                console.log("play")
                            }
                        }
                        onPressed: {
                            if(MEDIA_CTRL.state  === 2)
                            {
                                playPauseId.source = "qrc:/Img/Media/holdPlay.png"
                            }else /*if(MEDIAPLAYER.state  === 1)*/
                            {
                                playPauseId.source = "qrc:/Img/Media/holdPause.png"
                            }
                        }
                        onReleased: {
                            if(MEDIA_CTRL.state  === 2)
                            {
                                playPauseId.source = "qrc:/Img/Media/play.png"
                            }else /*if(MEDIAPLAYER.state  === 1)*/
                            {
                                playPauseId.source = "qrc:/Img/Media/pause.png"
                            }
                        }
                    }
                }
                Image{
                    id: buttonNextId
                    Layout.rightMargin: parent.width * 5/ 16
                    Layout.preferredWidth: parent.width / 16
                    Layout.preferredHeight: parent.height * 1.2/ 2
                    source: "qrc:/Img/Media/nextRelease.png"
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            console.log("NEXT SONG")
                            MEDIA_CTRL.next()
                        }
                        onPressed: {
                            buttonNextId.source = "qrc:/Img/Media/nextPress.png"
                        }
                        onReleased: {
                            buttonNextId.source = "qrc:/Img/Media/nextRelease.png"
                        }
                    }
                }
                SwitchButton{
                    id: buttonLoopId
                    Layout.rightMargin: 20
                    Layout.preferredWidth: parent.width / 16
                    Layout.preferredHeight: parent.height / 2
                    icon_on: "qrc:/Img/Media/repeatOn.png"
                    icon_off: "qrc:/Img/Media/repeatOff.png"
                    onButtonIsOn:{
                        buttonShuffleId.status = 0
                        MEDIA_CTRL.switchModePlaylist(1)
                        console.trace()
                    }
                    onButtonIsOff:{
                        buttonLoopId.status = 0
                        MEDIA_CTRL.switchModePlaylist()
                        console.trace()
                    }
                }
            }
        }
    }
}
