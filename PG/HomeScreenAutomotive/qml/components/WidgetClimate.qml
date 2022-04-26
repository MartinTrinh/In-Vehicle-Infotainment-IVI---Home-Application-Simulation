import QtQuick 2.0

MouseArea {
    id: root
    property alias bgrOpacity: colorBgrId.opacity
    property alias fanLvData: fanLevelIconId.source
    property alias seatDriverTem: seatDirverTempId.text
    property alias seatPassTemp: seatPassTempId.text
    property alias autoMode: autoModeId.color
    property alias syncMode: syncModeId.color
    property alias fanDriverDown: fanDownDriverIconId.source
    property alias fanDriverUp: fanUpDriverIconId.source
    property alias fanPassDown: fanDownPassIconId.source
    property alias fanPassUp: fanUpPassIconId.source
    Rectangle {
        id:colorBgrId
        width: 370
        height: 320
        opacity: 0.7
        color: "#111419"
    }
    Text{
        id: climateContainerId
        anchors.horizontalCenter: parent.horizontalCenter
        y: 15
        text: TRANSLATOR_MODEL.STR_WIDGET_CLIMATE  + TRANSLATOR_MODEL.emptyString
        font.pointSize: 20
        color: "white"
    }
    Item{
        id:possitionTitleContainerId
        anchors.top: climateContainerId.bottom
        anchors.topMargin: 5
        anchors.left: parent.left
        anchors.right: parent.right
        width: parent.width
        height: 20
        Text{
            id:driverTitleId
            anchors.left: parent.left
            anchors.leftMargin: 42
            text:TRANSLATOR_MODEL.STR_WIDGET_DRIVER + TRANSLATOR_MODEL.emptyString
            font.pointSize: 20
            color: "white"
        }
        Image {
            anchors.top: driverTitleId.bottom
            anchors.left: parent.left
            anchors.leftMargin: 42
            source: "qrc:/Img/Climate/bg_bottom.png"
            width: driverTitleId.width
            height: 2
        }
        Text {
            id: passengerTitleId
            anchors.right:  parent.right
            anchors.rightMargin: 30
            text: TRANSLATOR_MODEL.STR_WIDGET_PASSENDER + TRANSLATOR_MODEL.emptyString
            font.pointSize: 20
            color: "white"
        }
        Image {
            anchors.top: passengerTitleId.bottom
            anchors.right:  parent.right
            anchors.rightMargin: 30
            source: "qrc:/Img/Climate/bg_bottom.png"
            width: passengerTitleId.width
            height: 2
        }
    }
    Image {
        id: fanDownDriverIconId
        anchors.top: parent.top
        anchors.topMargin: 150
        anchors.left: parent.left
        anchors.leftMargin: 10
        width: 60
        height:50
        source: "qrc:/Img/Climate/widget_climate_arrow_02_n.png"
    }
    Image {
        id: fanUpDriverIconId
        anchors.top: parent.top
        anchors.topMargin: 120
        anchors.left: parent.left
        anchors.leftMargin: 30
        width: 60
        height:50
        source: "qrc:/Img/Climate/widget_climate_arrow_01_n.png"
    }
    Image {
        id: seatDriverIconId
        anchors.top: parent.top
        anchors.topMargin: 100
        anchors.left: fanDownDriverIconId.right
        anchors.leftMargin: -20
        width: 70
        height:100
        source: "qrc:/Img/Climate/widget_climate_arrow_seat.png"
    }
    Image {
        id: fanLevelIconId
        anchors.top: parent.top
        anchors.topMargin: 140
        anchors.left: seatDriverIconId.right
        anchors.leftMargin: -20
        width: 160
        height:80
        source: "qrc:/Img/Climate/widget_climate_wind_level_00.png"
    }
    Image {
        id: fanDownPassIconId
        anchors.top: parent.top
        anchors.topMargin: 150
        anchors.left: fanLevelIconId.right
        anchors.leftMargin: -25
        width: 60
        height:50
        source: "qrc:/Img/Climate/widget_climate_arrow_02_n.png"
    }
    Image {
        id: fanUpPassIconId
        anchors.top: parent.top
        anchors.topMargin: 120
        anchors.left: fanLevelIconId.right
        anchors.leftMargin: -5
        width: 60
        height:50
        source: "qrc:/Img/Climate/widget_climate_arrow_01_n.png"
    }
    Image {
        id: seatPassIconId
        anchors.top: parent.top
        anchors.topMargin: 100
        anchors.left: fanDownPassIconId.right
        anchors.leftMargin: -20
        width: 70
        height:100
        source: "qrc:/Img/Climate/widget_climate_arrow_seat.png"
    }
    Text {
        id: seatDirverTempId
        anchors.top: parent.top
        anchors.topMargin: 220
        anchors.left: parent.left
        anchors.leftMargin: 42
        text: "0\xB0 C" // add code here
        font.pointSize: 20
        color: "white"
    }
    Image {
        id: fanIconId
        anchors.top: parent.top
        anchors.topMargin: 220
        anchors.left: parent.left
        anchors.leftMargin: 165
        width: 35
        height: 35
        source: "qrc:/Img/Climate/ico_wind_level_off.png"
        cache: true
    }
    Text {
        id: seatPassTempId
        anchors.top: parent.top
        anchors.topMargin: 220
        anchors.left: parent.left
        anchors.leftMargin: 290
        text: "0\xB0 C"
        font.pointSize: 20
        color: "white"
    }
    Text{
        id:autoModeId
        anchors.top: parent.top
        anchors.topMargin: 275
        anchors.left: parent.left
        anchors.leftMargin: 30
        text: TRANSLATOR_MODEL.STR_WIDGET_AUTOMODE + TRANSLATOR_MODEL.emptyString
        font.pointSize: 20
        color: "white"
    }
    Text {
        id:outsideTitleId
        anchors.top: parent.top
        anchors.topMargin: 255
        anchors.horizontalCenter: parent.horizontalCenter
        //anchors.leftMargin: 32
        text: TRANSLATOR_MODEL.STR_WIDGET_OUTSIDE + TRANSLATOR_MODEL.emptyString
        font.pointSize: 18
        color: "white"
    }
    Text {
        id:outsideTempId
        anchors.top: outsideTitleId.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        text:"28.5" + "\xB0 C"
        font.pointSize: 20
        color: "white"
    }
    Text {
        id:syncModeId
        anchors.top: parent.top
        anchors.topMargin: 275
        anchors.right: parent.right
        anchors.rightMargin: 20
        text: TRANSLATOR_MODEL.STR_WIDGET_SYNCMODE + TRANSLATOR_MODEL.emptyString
        font.pointSize: 20
        color: "white"
    }
    Connections{
        target: CLIMATE_CTRL
        onDataChanged: {
            //=======================set data for fan level============================
            if (CLIMATE_CTRL.fan_level >= 1 && CLIMATE_CTRL.fan_level < 10) {
                fanLevelIconId.source = "qrc:/Img/Climate/widget_climate_wind_level_0"+CLIMATE_CTRL.fan_level+".png"
            }else {
                fanLevelIconId.source = "qrc:/Img/Climate/widget_climate_wind_level_10.png"
            }
            //=====================set data for driver temp====================================
            if (CLIMATE_CTRL.driver_temp == 16.5) {
                seatDirverTempId.text = "LOW"
            } else if (CLIMATE_CTRL.driver_temp == 31.5) {
                seatDirverTempId.text = "HIGH"
            } else {
                seatDirverTempId.text = CLIMATE_CTRL.driver_temp+"\xB0 C"
            }

            //===================set data for passenger temp===================================
            if (CLIMATE_CTRL.passenger_temp == 16.5) {
                seatPassTempId.text = "LOW"
            } else if (CLIMATE_CTRL.passenger_temp == 31.5) {
                seatPassTempId.text = "HIGH"
            } else {
                seatPassTempId.text = CLIMATE_CTRL.passenger_temp+"\xB0 C"
            }

            //===================set data for AUTO mode  0: ON | 1:OFF===========================
            if(CLIMATE_CTRL.auto_mode == 0)
            {
                autoModeId.color = "#1E90FF"
            }else if(CLIMATE_CTRL.auto_mode == 1)
            {
                autoModeId.color = "white"
            }

            //======================set data for SYNC mode  0: ON | 1:OFF===========================
            if(CLIMATE_CTRL.sync_mode == 0)
            {
                syncModeId.color =  "#1E90FF"
            }else if(CLIMATE_CTRL.sync_mode == 1)
            {
                syncModeId.color = "white"
            }
            //===================set data for driver wind direction=========================================
            if(CLIMATE_CTRL.driver_wind_mode == 0)
            {
                fanDownDriverIconId.source = "qrc:/Img/Climate/widget_climate_arrow_02_n.png"
                fanUpDriverIconId.source = "qrc:/Img/Climate/widget_climate_arrow_01_s_b.png"

            }else if(CLIMATE_CTRL.driver_wind_mode == 1)
            {
                fanDownDriverIconId.source = "qrc:/Img/Climate/widget_climate_arrow_02_s_b.png"
                fanUpDriverIconId.source = "qrc:/Img/Climate/widget_climate_arrow_01_n.png"
            }else if(CLIMATE_CTRL.driver_wind_mode == 2)
            {
                fanDownDriverIconId.source = "qrc:/Img/Climate/widget_climate_arrow_02_s_b.png"
                fanUpDriverIconId.source = "qrc:/Img/Climate/widget_climate_arrow_01_s_b.png"

            }
            //===================set data for passenger wind direction=========================================
            if(CLIMATE_CTRL.passenger_wind_mode == 0)
            {
                fanDownPassIconId.source = "qrc:/Img/Climate/widget_climate_arrow_02_n.png"
                fanUpPassIconId.source = "qrc:/Img/Climate/widget_climate_arrow_01_s_b.png"

            }else if(CLIMATE_CTRL.passenger_wind_mode ==1)
            {
                fanDownPassIconId.source = "qrc:/Img/Climate/widget_climate_arrow_02_s_b.png"
                fanUpPassIconId.source = "qrc:/Img/Climate/widget_climate_arrow_01_n.png"

            }else if(CLIMATE_CTRL.passenger_wind_mode ==2)
            {
                fanDownPassIconId.source = "qrc:/Img/Climate/widget_climate_arrow_02_s_b.png"
                fanUpPassIconId.source = "qrc:/Img/Climate/widget_climate_arrow_01_s_b.png"
            }

        }
    }
    Image {
        id: idBackgroud
        source: ""
        height:320
        width :370
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
}
