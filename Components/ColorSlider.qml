import QtQuick 2.7
import QtQuick.Controls 2.1

Slider {
    id: colorSlider
    property color backcolor: "#ddd"
    property color frontcolor: "#999"
    property alias sliderBg: sliderBg
    stepSize: 1
    snapMode: Slider.SnapAlways
    from: 0
    to: 255
    background: Rectangle {
        id: sliderBg
        x: colorSlider.leftPadding
        y: colorSlider.topPadding + colorSlider.availableHeight/2 - height/2
        implicitWidth: 200
        implicitHeight: 6
        width: colorSlider.availableWidth
        height: implicitHeight
        color: colorSlider.backcolor
        Rectangle {
            width: colorSlider.visualPosition * parent.width
            height: parent.height
            color: colorSlider.frontcolor
        }
    }
    handle: Rectangle {
        x: colorSlider.leftPadding + colorSlider.visualPosition*(colorSlider.availableWidth-width)
        y: colorSlider.topPadding + colorSlider.availableHeight/2 - height/2
        height: 18; width: 10
        color: "white"
        border.color: "black"
        border.width: 1
        radius: 2
    }
}
