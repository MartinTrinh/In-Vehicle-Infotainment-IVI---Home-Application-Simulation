import QtQuick 2.0
import QtQuick.Window 2.0
import QtQml.Models 2.1
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3
import QtLocation 5.3
import QtPositioning 5.2
import AppEnums 1.0
import "../components"

Item {
    id: root
    anchors.fill: parent
    // function check application tile
    function checkAppTitle(title)
    {
        var titleApp = "..."
        switch(title)
        {
        case "Map":
            titleApp =   TRANSLATOR_MODEL.STR_APP_MAP + TRANSLATOR_MODEL.emptyString
            break
        case "Video":
            titleApp =  TRANSLATOR_MODEL.STR_APP_VIDEO + TRANSLATOR_MODEL.emptyString
            break
        case "Media":
            titleApp =  TRANSLATOR_MODEL.STR_APP_MEDIA + TRANSLATOR_MODEL.emptyString
            break
        case "Phone":
            titleApp =  TRANSLATOR_MODEL.STR_APP_PHONE + TRANSLATOR_MODEL.emptyString
            break
        case "Radio":
            titleApp = TRANSLATOR_MODEL.STR_APP_RADIO + TRANSLATOR_MODEL.emptyString
            break
        case "Setting":
            titleApp =  TRANSLATOR_MODEL.STR_APP_SETTING + TRANSLATOR_MODEL.emptyString
            break
        default:
            console.log("title not matched")
            break
        }
        return titleApp
    }
    Component.onCompleted: {
        //===============update focus area=====================================================================
        if(SCREEN_CTRL.itemFocus === "climate")
        {
            climateAreaId.forceActiveFocus()
        }else if(SCREEN_CTRL.itemFocus === "music")
        {
            musicAreaId.forceActiveFocus()
        }else
        {
            mapAreaId.forceActiveFocus()
        }

        //============================update data for climate=================================================
        //============update data for fan level=======================
        climateAreaId.fanLvData = "qrc:/Img/Climate/widget_climate_wind_level_0"+CLIMATE_CTRL.fan_level+".png";
        //============update data for driver's temperature============
        if (CLIMATE_CTRL.driver_temp === 16.5) {
            climateAreaId.seatDriverTem = "LOW"
        } else if (CLIMATE_CTRL.driver_temp === 31.5) {
            climateAreaId.seatDriverTem = "HIGH"
        } else {
            climateAreaId.seatDriverTem = CLIMATE_CTRL.driver_temp+"\xB0 C"
        }
        //============update data for passenger's temperature============
        if (CLIMATE_CTRL.passenger_temp === 16.5) {
            climateAreaId.seatPassTemp= "LOW"
        } else if (CLIMATE_CTRL.passenger_temp === 31.5) {
            climateAreaId.seatPassTemp = "HIGH"
        } else {
            climateAreaId.seatPassTemp = CLIMATE_CTRL.passenger_temp+"\xB0 C"
        }

        //============update data for auto mode========================
        if(CLIMATE_CTRL.auto_mode === 0)
        {
            climateAreaId.autoMode = "#1E90FF"
        }else if(CLIMATE_CTRL.auto_mode === 1)
        {
            climateAreaId.autoMode = "white"
        }
        //==============update data for sync mode====================
        if(CLIMATE_CTRL.sync_mode === 0)
        {
            climateAreaId.syncMode =  "#1E90FF"
        }else if(CLIMATE_CTRL.sync_mode === 1)
        {
            climateAreaId.syncMode = "white"
        }
        //====================update data for dirver wind direction==============
        if(CLIMATE_CTRL.driver_wind_mode === 0)
        {
            climateAreaId.fanDriverDown = "qrc:/Img/Climate/widget_climate_arrow_02_n.png"
            climateAreaId.fanDriverUp = "qrc:/Img/Climate/widget_climate_arrow_01_s_b.png"

        }else if(CLIMATE_CTRL.driver_wind_mode === 1)
        {
            climateAreaId.fanDriverDown = "qrc:/Img/Climate/widget_climate_arrow_02_s_b.png"
            climateAreaId.fanDriverUp = "qrc:/Img/Climate/widget_climate_arrow_01_n.png"
        }else if(CLIMATE_CTRL.driver_wind_mode === 2)
        {
            climateAreaId.fanDriverDown = "qrc:/Img/Climate/widget_climate_arrow_02_s_b.png"
            climateAreaId.fanDriverUp = "qrc:/Img/Climate/widget_climate_arrow_01_s_b.png"

        }
        //====================update data for passenger wind direction==============
        if(CLIMATE_CTRL.passenger_wind_mode === 0)
        {
            climateAreaId.fanPassDown = "qrc:/Img/Climate/widget_climate_arrow_02_n.png"
            climateAreaId.fanPassUp = "qrc:/Img/Climate/widget_climate_arrow_01_s_b.png"

        }else if(CLIMATE_CTRL.passenger_wind_mode ===1)
        {
            climateAreaId.fanPassDown = "qrc:/Img/Climate/widget_climate_arrow_02_s_b.png"
            climateAreaId.fanPassUp = "qrc:/Img/Climate/widget_climate_arrow_01_n.png"

        }else if(CLIMATE_CTRL.passenger_wind_mode ===2)
        {
            climateAreaId.fanPassDown = "qrc:/Img/Climate/widget_climate_arrow_02_s_b.png"
            climateAreaId.fanPassUp = "qrc:/Img/Climate/widget_climate_arrow_01_s_b.png"
        }
    }
    Keys.onPressed: {

        console.log("keys.onpress: " + event.key)
        switch(event.key)
        {
        case Qt.Key_1:
            console.log("key_1 on press")
            SCREEN_CTRL.pushScreen("qrc:/qml/screens/MapScreen.qml")
            break
        case Qt.Key_2:
            console.log("key_2 onpress")
            SCREEN_CTRL.pushScreen("qrc:/qml/screens/ClimateScreen.qml")
            break
        case Qt.Key_3:
            console.log("key_3 onpress")
            SCREEN_CTRL.pushScreen("qrc:/qml/screens/MusicScreen.qml")
            break
        case Qt.Key_Return:
        case Qt.Key_Enter:
            console.log("key_enter onpress")
            if(mapAreaId.focus)
            {
                console.log("open map screen by hk")
                SCREEN_CTRL.pushScreen("qrc:/qml/screens/MapScreen.qml")
            }
            else if(climateAreaId.focus)
            {
                console.log("open climate screen by hk")
                SCREEN_CTRL.pushScreen("qrc:/qml/screens/ClimateScreen.qml")

            }
            else if(musicAreaId.focus)
            {
                console.log("open music screen by hk")
                SCREEN_CTRL.pushScreen("qrc:/qml/screens/MusicScreen.qml")
            }
            else if(listViewId.focus)
            {
                console.log("request change screen by hk")
                SCREEN_CTRL.pushScreen(listViewId.currentItem.appItem.urlAppItem)
            }
            break
        case Qt.Key_Up:
            console.log("Key Key_Up arrow hk")
            break;
        case Qt.Key_Down:
            console.log("Key Key_Down arrow hk")
            listViewId.focus = true
            listViewId.forceActiveFocus()
            break;
        default:
            console.log("cannot matched any key")
            break
        }
    }

    //=========================backgound====================================================================
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
        width: 370
        height: 320
        onPressed: mapAreaId.state = "Pressed"
        onReleased:{
            mapAreaId.focus = true
            mapAreaId.state = "Focus"
        }
        onPressAndHold: console.log("WidgetMap onPressAndHold")
        onFocusChanged: {
             console.log("WidgetMap onFocusChanged")
            if (mapAreaId.focus == true )
            {
                //change state
                mapAreaId.state = "Focus"
                climateAreaId.state =  "Normal"
                musicAreaId.state = "Normal"
            }
            else
            {
                mapAreaId.state = "Normal"
            }
        }
        onClicked: {
            console.log("Open Map Screen")
            SCREEN_CTRL.pushScreen("qrc:/qml/screens/MapScreen.qml")
        }
        KeyNavigation.right: climateAreaId
        KeyNavigation.down: listViewId
    }
    WidgetClimate{
        id:climateAreaId
        anchors.top: headerAreaId.bottom
        anchors.left:mapAreaId.right
        anchors.leftMargin: 10
        anchors.right: musicAreaId.left
        anchors.rightMargin: 10
        width: 370
        height: 320
        onClicked: {
            console.log("Open Climate Screen")
            SCREEN_CTRL.pushScreen("qrc:/qml/screens/ClimateScreen.qml")
        }
        onPressed: climateAreaId.state = "Pressed"
        onPressAndHold: console.log("WidgetClimate onPressAndHold")
        onReleased:{
            climateAreaId.focus = true
            climateAreaId.state = "Focus"
        }
        onFocusChanged: {
            console.log("WidgetClimate onFocusChanged")
            if (climateAreaId.focus == true )
            {
                //change state
                mapAreaId.state = "Normal"
                climateAreaId.state = "Focus"
                musicAreaId.state = "Normal"
            }else{
                climateAreaId.state = "Normal"
            }
        }
        KeyNavigation.left: mapAreaId
        KeyNavigation.right: musicAreaId
        KeyNavigation.down: listViewId
    }
    WidgetMedia{
        id:musicAreaId
        anchors.top: headerAreaId.bottom
        anchors.right: parent.right
        width: 370
        height: 320
        onPressed: musicAreaId.state = "Pressed"
        onReleased:{
            musicAreaId.focus = true
            musicAreaId.state = "Focus"
        }
        onPressAndHold: console.log("WidgetMedia onPressAndHold")

        onFocusChanged: {
            console.log("WidgetMedia onFocusChanged")
            if (musicAreaId.focus == true )
            {
                //change state
                mapAreaId.state = "Normal"
                climateAreaId.state =  "Normal"
                musicAreaId.state = "Focus"
            }
            else
            {
                musicAreaId.state = "Normal"
            }
        }
        onClicked: {
            console.log("Open Music Screen")
            SCREEN_CTRL.pushScreen("qrc:/qml/screens/MusicScreen.qml")
        }
        KeyNavigation.left: climateAreaId
        KeyNavigation.down: listViewId
    }

    //===============================application button area========================================
    ListView {
        id:listViewId
        anchors.top: mapAreaId.bottom
        anchors.topMargin: 20
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        width: parent.width
        orientation: ListView.Horizontal
        interactive: false
        spacing: 1
        displaced: Transition {
            NumberAnimation { properties: "x,y"; easing.type: Easing.OutQuad }
        }

        model: visualModel

        Keys.onPressed: {
            console.log("listview press Key: " + event.key)
            switch(event.key){
            case Qt.Key_Right:
                listViewId.incrementCurrentIndex()
                break;
            case Qt.Key_Left:
                listViewId.decrementCurrentIndex()
                break;
            case Qt.Key_Up:
                listViewId.focus = false
                mapAreaId.forceActiveFocus()
                break;
            }
        }

        ScrollBar.horizontal: ScrollBar {
            orientation: Qt.Horizontal
            size: listViewId.width / listViewId.contentWidth
            anchors.top: listViewId.top
            anchors.topMargin: -10
            anchors.left: listViewId.left
            visible: listViewId.count > 6
        }

        onFocusChanged:{
            //handle for check duplicate focus
            console.log("ListView----> Focus: "+focus)
            if(!focus){
                listViewId.currentItem.appItem.focus = false
                listViewId.currentItem.appItem.state = "Normal"
            }else{
                listViewId.currentItem.appItem.focus = true
                listViewId.currentItem.appItem.state = "Focus"
            }
        }
    }

    DelegateModel {
        id: visualModel
        model: APP_MODEL
        delegate: DropArea {
            id: delegateRoot
            width :190
            height:265
            keys: "AppButton"
            property int visualIndex: DelegateModel.itemsIndex
            property alias appItem: app

            onEntered:{
                console.log("DelegateModel onEntered")
                visualModel.items.move(drag.source.visualIndex, icon.visualIndex)
            }
            onActiveFocusChanged: {
                console.log(" DelegateModel onActiveFocusChanged")
                app.focus = true
                app.state = "Focus"

            }
            onExited: {
                console.log("DelegateModel onExited")
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
                width :185
                height:280
                property int visualIndex: 0

                anchors {
                    horizontalCenter: parent.horizontalCenter;
                    verticalCenter: parent.verticalCenter
                }

                AppButton{
                    id: app
                    title: checkAppTitle(model.title)
                    icon: model.iconPath
                    drag.axis: Drag.XAxis
                    drag.target: app.stateDrag ? icon : undefined

                    property bool  stateDrag : false
                    property string urlAppItem: model.url
                    onPressAndHold: {
                        console.log("AppButton onPressAndHold")
                        stateDrag = true
                    }
                    onReleased: {
                        console.log("AppButton onRelease")
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
                        console.log("AppButton onClicked open application screen")
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
}
