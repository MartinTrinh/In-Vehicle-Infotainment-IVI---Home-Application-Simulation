import QtQuick 2.9
import QtQml.Models 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtLocation 5.15
import QtPositioning 5.15
import AppEnums 1.0
import "../components"

Item {
    id: root
    anchors.fill: parent
    focus: true
    // function check application tile
    function checkAppTitle(title)
    {
        switch(title)
        {
         case "Map":
             return  TRANSLATOR_MODEL.STR_APP_MAP + TRANSLATOR_MODEL.emptyString
         case "Video":
             return TRANSLATOR_MODEL.STR_APP_VIDEO + TRANSLATOR_MODEL.emptyString
         case "Media":
             return TRANSLATOR_MODEL.STR_APP_MEDIA + TRANSLATOR_MODEL.emptyString
         case "Phone":
             return TRANSLATOR_MODEL.STR_APP_PHONE + TRANSLATOR_MODEL.emptyString
         case "Radio":
             return TRANSLATOR_MODEL.STR_APP_RADIO + TRANSLATOR_MODEL.emptyString
         case "Setting":
             return TRANSLATOR_MODEL.STR_APP_SETTING + TRANSLATOR_MODEL.emptyString
        }
    }

    Component.onCompleted: {
        //============================update data for climate========================================================================
        //============update data for fan level=======================
        climateAreaId.fanLvData = "qrc:/Img/Climate/widget_climate_wind_level_0"+CLIMATE_CTRL.fan_level+".png";
        //============update data for driver's temperature============
        if (CLIMATE_CTRL.driver_temp == 16.5) {
            climateAreaId.seatDriverTem = "LOW"
        } else if (CLIMATE_CTRL.driver_temp == 31.5) {
            climateAreaId.seatDriverTem = "HIGH"
        } else {
            climateAreaId.seatDriverTem = CLIMATE_CTRL.driver_temp+"\xB0 C"
        }
        //============update data for passenger's temperature============
        if (CLIMATE_CTRL.passenger_temp == 16.5) {
            climateAreaId.seatPassTemp= "LOW"
        } else if (CLIMATE_CTRL.passenger_temp == 31.5) {
            climateAreaId.seatPassTemp = "HIGH"
        } else {
            climateAreaId.seatPassTemp = CLIMATE_CTRL.passenger_temp+"\xB0 C"
        }

        //============update data for auto mode========================
        if(CLIMATE_CTRL.auto_mode == 0)
        {
            climateAreaId.autoMode = "#1E90FF"
        }else if(CLIMATE_CTRL.auto_mode == 1)
        {
            climateAreaId.autoMode = "white"
        }
        //==============update data for sync mode====================
        if(CLIMATE_CTRL.sync_mode == 0)
        {
            climateAreaId.syncMode =  "#1E90FF"
        }else if(CLIMATE_CTRL.sync_mode == 1)
        {
            climateAreaId.syncMode = "white"
        }
        //====================update data for dirver wind direction==============
        if(CLIMATE_CTRL.driver_wind_mode == 0)
        {
            climateAreaId.fanDriverDown = "qrc:/Img/Climate/widget_climate_arrow_02_n.png"
            climateAreaId.fanDriverUp = "qrc:/Img/Climate/widget_climate_arrow_01_s_b.png"

        }else if(CLIMATE_CTRL.driver_wind_mode == 1)
        {
            climateAreaId.fanDriverDown = "qrc:/Img/Climate/widget_climate_arrow_02_s_b.png"
            climateAreaId.fanDriverUp = "qrc:/Img/Climate/widget_climate_arrow_01_n.png"
        }else if(CLIMATE_CTRL.driver_wind_mode == 2)
        {
            climateAreaId.fanDriverDown = "qrc:/Img/Climate/widget_climate_arrow_02_s_b.png"
            climateAreaId.fanDriverUp = "qrc:/Img/Climate/widget_climate_arrow_01_s_b.png"

        }
        //====================update data for passenger wind direction==============
        if(CLIMATE_CTRL.passenger_wind_mode == 0)
        {
            climateAreaId.fanPassDown = "qrc:/Img/Climate/widget_climate_arrow_02_n.png"
            climateAreaId.fanPassUp = "qrc:/Img/Climate/widget_climate_arrow_01_s_b.png"

        }else if(CLIMATE_CTRL.passenger_wind_mode ==1)
        {
            climateAreaId.fanPassDown = "qrc:/Img/Climate/widget_climate_arrow_02_s_b.png"
            climateAreaId.fanPassUp = "qrc:/Img/Climate/widget_climate_arrow_01_n.png"

        }else if(CLIMATE_CTRL.passenger_wind_mode ==2)
        {
            climateAreaId.fanPassDown = "qrc:/Img/Climate/widget_climate_arrow_02_s_b.png"
            climateAreaId.fanPassUp = "qrc:/Img/Climate/widget_climate_arrow_01_s_b.png"
        }
        //=========================================update language==========================================

    }


    Image{
        anchors.fill: parent
        source: "qrc:/Img/bg_full.png"
    }
    //===========================header status area==========================================================
    StatusBar{
        id:headerAreaId
        width: parent.width
        height: 60
        buttonBackToScreen: false
    }
    //===========================wingets area================================================================
    WidgetMap{
        id: mapAreaId
        anchors.top: headerAreaId.bottom
        anchors.left:parent.left
        anchors.leftMargin: 5

        onPressed: mapAreaId.state = "Pressed"
        onReleased:{
            mapAreaId.focus = true
            mapAreaId.state = "Focus"
        }
        onFocusChanged: {
            if (mapAreaId.focus == true )
                mapAreaId.state = "Focus"
            else
                mapAreaId.state = "Normal"
        }
        onClicked: {
            console.log("Open Map Screen")
            SCREEN_CTRL.pushScreen("qrc:/qml/screens/MapScreen.qml")
        }
    }
    WidgetClimate{
        id:climateAreaId
        anchors.top: headerAreaId.bottom
        anchors.left:mapAreaId.right
        anchors.leftMargin: 10
        anchors.right: musicAreaId.left
        anchors.rightMargin: 10
        onClicked: {
            console.log("Open Climate Screen")
            SCREEN_CTRL.pushScreen("qrc:/qml/screens/ClimateScreen.qml")
        }
        onPressed: climateAreaId.state = "Pressed"
        onReleased:{
            climateAreaId.focus = true
            climateAreaId.state = "Focus"
        }
        onFocusChanged: {
            if (climateAreaId.focus == true )
                climateAreaId.state = "Focus"
            else
                climateAreaId.state = "Normal"
        }
    }
    WidgetMedia{
        id:musicAreaId
        anchors.top: headerAreaId.bottom
        anchors.right: parent.right

        onPressed: musicAreaId.state = "Pressed"
        onReleased:{
            musicAreaId.focus = true
            musicAreaId.state = "Focus"
        }
        onFocusChanged: {
            if (musicAreaId.focus == true )
                musicAreaId.state = "Focus"
            else
                musicAreaId.state = "Normal"
        }
        onClicked: {
            console.log("Open Music Screen")
            SCREEN_CTRL.pushScreen("qrc:/qml/screens/MusicScreen.qml")
        }
    }

    //===============================application button area========================================

    ScrollView {
        anchors.top: mapAreaId.bottom
        anchors.topMargin: 10
        anchors.left: parent.left
        width: parent.width
        //        height: 300
        //        clip: true
        //ScrollBar.vertical.policy: ScrollBar.AlwaysOn

        ListView {
            id:listViewId
            width: parent.width
            height: 300
            orientation: ListView.Horizontal
            interactive: false
            spacing: 1
            displaced: Transition {
                NumberAnimation { properties: "x,y"; easing.type: Easing.OutQuad }
            }
            model: DelegateModel {
                id: visualModel
                model: APP_MODEL
                delegate: DropArea {
                    id: delegateRoot
                    width :190
                    height:285
                    keys: "AppButton"
                    property int visualIndex: DelegateModel.itemsIndex
                    onEntered: {
                        visualModel.items.move(drag.source.visualIndex, icon.visualIndex)
                        console.log(drag.source.visualIndex)
                        console.log(icon.visualIndex)

                    }
                    onActiveFocusChanged: {
                        console.log("onActiveFocusChanged")
                        app.focus = true
                        app.state = "Focus"
                    }
                    onExited: {
                        console.log("onExited")
                        listViewId.focus = true
                        APP_CTRL.updateDataFromQML(drag.source.visualIndex, icon.visualIndex)
                    }

                    Binding {
                        target: icon
                        property: "visualIndex"
                        value: visualIndex
                    }
                    Item {
                        id: icon
                        property int visualIndex: 0
                        width :185
                        height:285
                        anchors {
                            horizontalCenter: parent.horizontalCenter;
                            verticalCenter: parent.verticalCenter
                        }

                        AppButton{
                            id: app
                            anchors.fill: parent
                            title: checkAppTitle(model.title)
                            icon: model.iconPath
                            property bool  stateDrag : false
                            drag.axis: Drag.XAxis
                            drag.target: app.stateDrag ? icon : undefined
                            onPressed: {
                                console.log("onPress")
                                console.log(icon.visualIndex)
                                stateDrag = true
                            }
                            onReleased: {
                                //stateDrag = false
                                console.log("onRelease")
                                console.log(icon.visualIndex)
                                app.focus = true
                                app.state = "Focus"
                                for (var index = 0; index < visualModel.items.count;index++){
                                    if (index !== icon.visualIndex)
                                        visualModel.items.get(index).focus = false
                                    else
                                        visualModel.items.get(index).focus = true
                                }
                            }
                            onClicked: {
                                console.log("------->Request Change Screen")
                                SCREEN_CTRL.pushScreen(model.url)
                            }
                        }

                        onFocusChanged: app.focus = icon.focus
                        Drag.active: app.drag.active
                        Drag.keys: "AppButton"
                        Drag.hotSpot.x: width /2
                        Drag.hotSpot.y: height /2
                        states: [
                            State {
                                when: icon.Drag.active
                                ParentChange {
                                    target: icon
                                    parent: delegateRoot.parent
                                }

                                AnchorChanges {
                                    target: icon
                                    anchors.horizontalCenter: undefined
                                    anchors.verticalCenter: undefined
                                }
                            }
                        ]
                    }
                }
            }

            //            ScrollBar.vertical: ScrollBar {
            //                parent: listViewId.parent
            //                anchors.top: listViewId.top
            //                anchors.left: listViewId.left
            //                //anchors.bottom: listViewId.bottom
            //            }
        }
    }
}
