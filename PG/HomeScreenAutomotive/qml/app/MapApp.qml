import QtQuick 2.0
import "../components"

AppButton{
    id: mapBtId
    icon:"qrc:/Img/HomeScreen/btn_home_menu_map"
    title: "Map"
    width :185
    height:285
    onOpenScreen:{
        console.log("Home ==> Map screen")
        SCREEN_CTRL.pushScreen(AppEnums.SCREEN_ID_MAP)
    }
}

