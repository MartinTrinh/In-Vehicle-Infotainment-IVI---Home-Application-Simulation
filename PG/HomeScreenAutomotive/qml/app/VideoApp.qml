import QtQuick 2.0
import "../components"

AppButton {
    id:videoBtId
    width :185
    height:285
    icon:"qrc:/Img/HomeScreen/btn_home_menu_video"
    title: "Video"
    onOpenScreen:{
        console.log("Home ==> Video screen")
        SCREEN_CTRL.pushScreen(AppEnums.SCREEN_ID_VIDEO_PLAYER)
    }
}
