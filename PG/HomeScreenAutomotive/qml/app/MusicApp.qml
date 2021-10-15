import QtQuick 2.0
import "../components"
AppButton {
    id:musicBtId
    width :185
    height:285
    icon:"qrc:/Img/HomeScreen/btn_home_menu_media"
    title: "Media"
    onOpenScreen:{
        console.log("Home ==> Music screen")
        SCREEN_CTRL.pushScreen(AppEnums.SCREEN_ID_MUSIC_PLAYER)
    }
}
