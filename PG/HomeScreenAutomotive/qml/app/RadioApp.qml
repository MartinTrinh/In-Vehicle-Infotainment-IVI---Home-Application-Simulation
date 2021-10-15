import QtQuick 2.0
import "../components"

AppButton {
    id:radioBtId
    width :185
    height:285
    icon:"qrc:/Img/HomeScreen/btn_home_menu_radio"
    title: "Radio"
    onOpenScreen:{
        console.log("Home ==> Radio screen")
        SCREEN_CTRL.pushScreen(AppEnums.SCREEN_ID_RADIO)
    }
}
