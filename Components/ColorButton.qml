import QtQuick 2.7

Item {
    //
    width: 40; height: 30
    //
    Rectangle {
        //
        anchors.fill: parent
        border.color: "black"
        border.width: 1
        color: "white"
        //
        Rectangle {
            anchors.fill: parent
            anchors.margins: 5
            //
            color: "red"
            //
        }
    }
}