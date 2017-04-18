import QtQuick 2.7

Item {
    id: colorBtn
    width: 40; height: 30
    property string colorsetting
    property color colorbtn
    property bool coloralpha
    Rectangle {
        anchors.fill: parent
        border.color: "black"
        border.width: 1
        color: "white"
        MouseArea {
            anchors.fill: parent
            onClicked: {
                root.initColorSelector(colorBtn.colorsetting,colorBtn.coloralpha)
                mainView.push(colorSelectorView)
            }
        }
        Rectangle {
            anchors.fill: parent
            anchors.margins: 5
            color: colorBtn.colorbtn
        }
    }
}
