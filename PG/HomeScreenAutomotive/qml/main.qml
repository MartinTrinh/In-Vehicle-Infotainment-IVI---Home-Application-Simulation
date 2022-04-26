import QtQuick 2.9
import QtQuick.Window 2.2

Window{
    id: root
    title: "Home Application"
    visible: true
    width: 1140
    height: 645
    FocusScope{
        anchors.fill: parent
    }

    property var layer_base: layer_base_1

    function reloadScreen() {
        layer_base.source = ""
        layer_base.source = SCREEN_MODEL.currentScreen
    }
    function helloworld()
    {
        console.log("ThangTV22 hello the world")
    }

    function switchLayerBase(from, to) {
        console.log("switchLayerBase");
        if (from.item !== null) {
            from.item.visible = false
            from.source = ""
        }
        if (to.item !== null) {
            to.item.visible = true
        }
        layer_base = from
    }

    // common screen loader
    Loader {
        id: layer_base_1
        anchors.fill: parent
        onLoaded: {
            switchLayerBase(layer_base_2, layer_base_1);
        }
    }
    Loader {
        id: layer_base_2
        anchors.fill: parent
        onLoaded: {
            switchLayerBase(layer_base_1, layer_base_2);
        }
    }
}
