import QtQuick 2.7
import QtQuick.Controls 2.1

Slider {
    id: colorSlider
    //
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
