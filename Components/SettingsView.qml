import QtQuick 2.7
import QtQuick.Controls 2.1

Item {
    id: settingsView
    visible: false
    // properties
    property string title
    property var listmodel
    property bool init: false
    property bool mod: false
    // elements
    Label {
        id: titleLab
        anchors.top: parent.top
        anchors.margins: 10
        anchors.horizontalCenter: parent.horizontalCenter
        font.bold: true
        font.pointSize: 14
        text: title
    }
    Row {
        id: rowBtns
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: titleLab.bottom
        anchors.margins: 10
        spacing: 10
        Button {
            //
            enabled: mod
            height: 30
            //
            text: "Valider"
            //
        }
        Button {
            //
            height: 30
            //
            text: "Défaut"
            //
        }
    }
    ListView {
        id: optionsList
        anchors.top: rowBtns.bottom
        anchors.bottom: parent.bottom
        anchors.margins: 10
        anchors.horizontalCenter: parent.horizontalCenter
        width: (parent.width < 400)? parent.width-20 : 380
        clip: true
        spacing: 5
        model: listmodel
        delegate: Item {
            height: 30
            width: optionsList.width
            Rectangle {
                color: "#f5f5f5"
                anchors.fill: parent
            }
            Label {
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 5
                width: parent.width-130
                wrapMode: TextInput.WordWrap
                text: label
            }
            Item {
                anchors.right: parent.right
                anchors.rightMargin: 0
                width: 120
                height: parent.height
                ColorButton {
                    visible: (type == "color")? true : false
                    //
                    anchors.centerIn: parent
                    //
                }
                SpinBox {
                    visible: (type == "number")? true : false
                    //
                    from: 0; to: 300
                    height: 30
                    width: 120
                    //
                }
                Switch {
                    visible: (type == "bool")? true : false
                    //
                    anchors.centerIn: parent
                    //
                }
            }
        }
        ScrollIndicator.vertical: ScrollIndicator {}
    }
}
