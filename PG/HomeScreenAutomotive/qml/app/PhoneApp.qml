import QtQuick 2.0
import "../components"

AppButton {
    id:phoneBtId
    width :185
    height:285
    icon:"qrc:/Img/HomeScreen/btn_home_menu_phone"
    title: "Phone"
    onOpenScreen:{
        console.log("Home ==> Phone screen")
        SCREEN_CTRL.pushScreen(AppEnums.SCREEN_ID_TELEPHONE)
    }
}
