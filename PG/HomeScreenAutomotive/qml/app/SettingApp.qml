import QtQuick 2.0
import "../components"

AppButton {
    id:settingBtId
    width :185
    height:285
    icon:"qrc:/Img/HomeScreen/btn_home_menu_settings"
    title: "Setting"
    onOpenScreen:{
        console.log("Home ==> Setting screen")
        SCREEN_CTRL.pushScreen(AppEnums.SCREEN_ID_SETTING)
    }
}
