import QtQuick 2.7
import QtQuick.Controls 2.1

Item {
    id: settingsView
    visible: false
    // properties
    property string title
    property var listmodel: ListModel {}
    property bool settings_mod
    property bool settings_cancel
    property bool settings_reset
    property bool actions_mode
    property string actions
    // events handlers
    onVisibleChanged: { if (settingsView.visible) { root.initSettingView() } }
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
            visible: !actions_mode
            enabled: settings_mod; height: 30; width: 80
            text: "Valider"
            onClicked: root.validateSettings()
        }
        Button {
            visible: !actions_mode
            enabled: settings_cancel; height: 30; width: 80
            text: "Annuler"
            onClicked: root.setCancelMode()
        }
        Button {
            visible: !actions_mode
            enabled: settings_reset; height: 30; width: 80
            text: "Défaut"
            onClicked: root.setResetMode()
        }
        Label {
            visible: actions_mode
            anchors.verticalCenter: parent.verticalCenter
            text: (actions == "cancel")? "Annuler" : "Défaut"
        }
        Button {
            //
            visible: actions_mode
            //
            enabled: false // TODO
            //
            height: 30; width: 80
            text: "Valider"
            //
        }
        Button {
            visible: actions_mode
            height: 30; width: 80
            text: "Terminer"
            onClicked: root.cancelActionsMode()
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
            //
            //
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
                font.bold: mod
                //
                color: "black"
                //
                // TODO : depend
                //
            }
            Item {
                anchors.right: parent.right
                anchors.rightMargin: 0
                width: 120
                height: parent.height
                ColorButton {
                    visible: !actions_mode && (type == "color")? true : false
                    colorsetting: setting
                    colorbtn: (type == "color")? Qt.rgba(tcolor.r,tcolor.g,tcolor.b,tcolor.a) : "black"
                    coloralpha: (type == "color")? alpha : false
                    anchors.centerIn: parent
                }
                SpinBox {
                    visible: !actions_mode && (type == "number")? true : false
                    //
                    from: 0; to: 300
                    height: 30
                    width: 120
                    //
                }
                Switch {
                    visible: !actions_mode && (type == "bool")? true : false
                    checked: (type == "bool")? tbool : false
                    //
                    anchors.centerIn: parent
                    //
                    onCheckedChanged: {
                        //
                    }
                }
                //
                // TODO : add the reset checkbox
                //
                CheckBox {
                    //
                    visible: actions_mode
                    //
                    anchors.centerIn: parent
                    //
                }
                //
            }
        }
        ScrollIndicator.vertical: ScrollIndicator {
            parent: optionsList.parent
            anchors.top: optionsList.top
            anchors.bottom: optionsList.bottom
            anchors.left: optionsList.right
        }
    }
}
