import QtQuick 2.7
import QtQuick.Controls 2.1

Slider {
    id: colorSlider
    property color backcolor: "#ddd"
    property color frontcolor: "#999"
    property alias sliderBg: sliderBg
    stepSize: 0.01
    snapMode: Slider.SnapAlways
    background: Rectangle {
        id: sliderBg
        x: colorSlider.leftPadding
        y: colorSlider.topPadding + colorSlider.availableHeight/2 - height/2
        implicitWidth: 200
        implicitHeight: 6
        //
        width: colorSlider.availableWidth
        height: implicitHeight
        radius: 2
        //
        color: colorSlider.backcolor
        gradient: Gradient {
            GradientStop { position: 0; color: "blue" }
            GradientStop { position: 1; color: "yellow" }
            //
        }
        //
        Rectangle {
            width: colorSlider.visualPosition * parent.width
            height: parent.height
            //
            color: colorSlider.frontcolor
            //
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
