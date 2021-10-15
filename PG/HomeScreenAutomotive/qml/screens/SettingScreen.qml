import QtQuick 2.0
import QtQuick.Controls 2.12
import AppEnums 1.0
import "../components"
Item {
    id: root
//    Component.onCompleted: {
//        volumeId.value = MEDIA_CTRL.volume
//    }

    Image{
        anchors.fill: parent
        source: "qrc:/Img/bg_full.png"
    }
    StatusBar{
        id:headerAreaId
        width: parent.width
        height: 60
    }
    Text{
        id:titleAppScreenId
        anchors.top: headerAreaId.bottom
        anchors.topMargin: 40
        anchors.left: parent.left
        anchors.leftMargin: 460
        text: TRANSLATOR_MODEL.STR_SETTING_SERVICE_MODE + TRANSLATOR_MODEL.emptyString
        color: "white"
        font.pointSize: 20
        font.weight: Font.Bold
    }
    Text {
        id:languageFeildId
        anchors.top:  parent.top
        anchors.left: parent.left
        anchors.topMargin: 200
        anchors.leftMargin: 50
        text: TRANSLATOR_MODEL.STR_SETTING_LANGUAGE + TRANSLATOR_MODEL.emptyString
        color: "white"
        font.pointSize: 20
        font.weight: Font.Bold

    }
    RadioButton{
        id: vietnameseId
        anchors.top:  parent.top
        anchors.left: parent.left
        anchors.topMargin: 200
        anchors.leftMargin: 300
        Text{
            y: 40
            text:TRANSLATOR_MODEL.STR_SETTING_LANGUAGE_VIETNAMESE + TRANSLATOR_MODEL.emptyString
            color: "white"
            font.pointSize: 16
            font.weight: Font.Bold
        }
        checked:TRANSLATOR_MODEL.checkModeLang(AppEnums.VN)
        onCheckedChanged: {
            console.log("changed language to  vietnamese")
            TRANSLATOR_MODEL.setLanguage(AppEnums.VN);
        }
    }


    RadioButton{
        id: englishId
        anchors.top:  parent.top
        anchors.left: parent.left
        anchors.topMargin: 200
        anchors.leftMargin: 500
        Text{
            y: 40
            text: TRANSLATOR_MODEL.STR_SETTING_LANGUAGE_ENGLISH + TRANSLATOR_MODEL.emptyString
            color: "white"
            font.pointSize: 16
            font.weight: Font.Bold
        }
        checked:TRANSLATOR_MODEL.checkModeLang(AppEnums.EN)
        onCheckedChanged: {
            console.log("changed language to  english")
            TRANSLATOR_MODEL.setLanguage(AppEnums.EN);
        }

    }

    RadioButton{
        id: koreaId
        anchors.top:  parent.top
        anchors.left: parent.left
        anchors.topMargin: 200
        anchors.leftMargin: 700
        Text{
            y: 40
            text: TRANSLATOR_MODEL.STR_SETTING_LANGUAGE_KOREA + TRANSLATOR_MODEL.emptyString
            color: "white"
            font.pointSize: 16
            font.weight: Font.Bold
        }
        checked:TRANSLATOR_MODEL.checkModeLang(AppEnums.KO)
        onCheckedChanged: {
            console.log("changed language to  korea")
            TRANSLATOR_MODEL.setLanguage(AppEnums.KO);
        }
    }


    Text {
        anchors.top:parent.top
        anchors.topMargin: 400
        anchors.left: parent.left
        anchors.leftMargin: 50
        text:TRANSLATOR_MODEL.STR_SETTING_LANGUAGE_VOLUME + TRANSLATOR_MODEL.emptyString
        color: "white"
        font.pointSize: 20
        font.weight: Font.Bold
    }
    Slider {
        id: volumeId
        anchors.top:parent.top
        anchors.topMargin: 420
        anchors.left: parent.left
        anchors.leftMargin: 300
        width: 430
        height: 10
        from : 10
        to: 100
        stepSize: 2
        value: MEDIA_CTRL.volume
        onValueChanged:{
            MEDIA_CTRL.setVolume(volumeId.value)
            console.log("value = " + volumeId.value)
        }
    }



}
