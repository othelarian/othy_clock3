import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Controls 2.1
import QtGraphicalEffects 1.0

import OCelements 1.0
import "Components"
import "script.js" as Script

Window {
    id: root
    visible: true
    width: 300; minimumWidth: 200
    height: 300; minimumHeight: 200
    title: "Othy Clock 3"
    // properties ###############################
    //
    property int testi
    //
    property int minute: -1
    property int hour: -1
    property int weekday: -1
    property int day: -1
    property int month: -1
    // functions accessors ######################
    function initSettingView() { Script.initSettingView() }
    function validateSettings() { Script.validateSettings() }
    function setCancelMode() { Script.setCancelMode() }
    function validateCancelMode() { Script.validateCancelMode() }
    function setResetMode() { Script.setResetMode() }
    function validateResetMode() { Script.validateResetMode() }
    function cancelActionsMode() { Script.cancelActionsMode() }
    //
    function initColorSelector(setting,alpha) { Script.initColorSelector(setting,alpha) }
    // launch time ##############################
    Component.onCompleted: Script.init()
    // timer ####################################
    Timer {
        id: timer; interval: 1000; running: false; repeat: true
        onTriggered: Script.timing()
    }
    // keyboard shortcuts #######################
    Shortcut {
        sequence: "Ctrl+S"
        context: Qt.ApplicationShortcut
        onActivated: { if (drawer.visible) { drawer.close() } else { drawer.open() } }
    }
    // main view ################################
    StackView {
        id: mainView
        anchors.fill: parent
        initialItem: clockView
        // clock view ###############################
        Item {
            id: clockView
            // global background ########################
            Rectangle { id: bgAll; anchors.fill: parent }
            // months ###################################
            //
            // TODO : OCmonthsBg
            //
            OCmonthsCog { id: monthsCog; anchors.fill: parent }
            OCmonthsTicks { id: monthsTicks; anchors.fill: parent }
            // days #####################################
            //
            // TODO : OCdaysBg
            //
            OCdaysCog { id: daysCog; anchors.fill: parent }
            OCdaysTicks { id: daysTicks; anchors.fill: parent }
            // week #####################################
            //
            // TODO : OCdaysBg
            //
            OCweekCog { id: weekCog; anchors.fill: parent }
            OCweekTicks { id: weekTicks; anchors.fill: parent }
            // hours ####################################
            OChoursBg { id: hoursBg; anchors.fill: parent }
            OChoursCog { id: hoursCog; anchors.fill: parent }
            OChoursTicks { id: hoursTicks; anchors.fill: parent }
            // minutes ##################################
            //
            // TODO : OChoursBg
            //
            OCminutesCog { id: minutesCog; anchors.fill: parent }
            OCminutesTicks { id: minutesTicks; anchors.fill: parent }
            // seconds ##################################
            //
            // TODO : OCsecondsBg
            //
            OCsecondsTicks { id: secondsTicks; anchors.fill: parent }
            OCsecondsCog { id: secondsCog; anchors.fill: parent }
        }
        // background settings view #################
        SettingsView {
            id: backgroundSettingView
            title: "Fond"
        }
        // seconds settings view ####################
        SettingsView {
            id: secondsSettingView
            title: "Secondes"
        }
        // minutes settings view ####################
        SettingsView {
            id: minutesSettingView
            title: "Minutes"
        }
        // hours settings view ######################
        SettingsView {
            id: hoursSettingView
            title: "Heures"
        }
        // week settings view #######################
        Item {
            id: weekSettingView
            visible: false
            //
            //
            Text { text: "week settings" }
        }
        // days settings view #######################
        Item {
            id: daysSettingView
            visible: false
            //
            //
            Text { text: "days settings" }
        }
        // months settings view #####################
        Item {
            id: monthsSettingView
            visible: false
            //
            //
            Text { text: "months settings" }
        }
        // color selector view ######################
        Item {
            id: colorSelectorView
            visible: false
            // properties
            property bool colorChanged: false
            property string setting
            property color backcolor
            property color activecolor
            property color currentcolor
            property bool alpha
            // elements
            Label {
                id: titleColSel
                anchors.top: parent.top
                anchors.margins: 10
                anchors.horizontalCenter: parent.horizontalCenter
                font.bold: true
                font.pointSize: 14
                text: "Couleur :"
            }
            Row {
                id: colorsShowRow
                anchors.top: titleColSel.bottom
                anchors.margins: 10
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 10
                Column {
                    spacing: 10
                    Label {
                        anchors.horizontalCenter: parent.horizontalCenter
                        text: "Nouvelle :"
                    }
                    Rectangle {
                        id: currColorRect
                        anchors.horizontalCenter: parent.horizontalCenter
                        width: 50; height: 30
                        border.color: "black"
                        border.width: 1
                        color: "white"
                        Rectangle {
                            anchors.fill: parent
                            anchors.margins: 5
                            color: colorSelectorView.backcolor
                        }
                        Rectangle {
                            anchors.fill: parent
                            anchors.margins: 5
                            color: colorSelectorView.currentcolor
                        }
                    }
                }
                Column {
                    spacing: 10
                    Label {
                        anchors.horizontalCenter: parent.horizontalCenter
                        text: "Courante :"
                    }
                    Rectangle {
                        id: newColorRect
                        anchors.horizontalCenter: parent.horizontalCenter
                        width: 50; height: 30
                        border.color: "black"
                        border.width: 1
                        color: "white"
                        Rectangle {
                            anchors.fill: parent
                            anchors.margins: 5
                            color: colorSelectorView.backcolor
                        }
                        Rectangle {
                            anchors.fill: parent
                            anchors.margins: 5
                            color: colorSelectorView.activecolor
                        }
                    }
                }
            }
            Row {
                id: colbtnsRow
                anchors.top: colorsShowRow.bottom
                anchors.margins: 10
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 10
                Button {
                    text: "Valider"
                    enabled: colorSelectorView.colorChanged
                    height: 30
                    onClicked: Script.validColor()
                }
                Button { text: "Annuler"; height: 30; onClicked: mainView.pop() }
            }
            Row {
                id: modeColorRow
                anchors.top: colbtnsRow.bottom
                anchors.margins: 10
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 10
                RadioButton {
                    id: colRgbMode
                    text: "RGB"
                    height: 20
                    checked: true
                    onCheckedChanged: Script.colorModeSwitch()
                }
                RadioButton {
                    id: colHslMode
                    text: "HSL"
                    height: 20
                }
            }
            Flickable {
                width: (parent.width < 350)? parent.width-20 : 330
                anchors.top: modeColorRow.bottom
                anchors.bottom: parent.bottom
                anchors.margins: 10
                anchors.horizontalCenter: parent.horizontalCenter
                clip: true
                interactive: true
                contentHeight: colorSliders.height
                Column {
                    id: colorSliders
                    width: parent.width
                    spacing: 8
                    Item {
                        height: 25
                        width: parent.width
                        LinearGradient {
                            anchors.left: parent.left
                            anchors.leftMargin: 5 + colorValue1Slider.leftPadding
                            anchors.verticalCenter: parent.verticalCenter
                            width: parent.width - 80 - colorValue1Slider.leftPadding - colorValue1Slider.rightPadding
                            height: 6
                            start: Qt.point(0,0)
                            end: Qt.point(width,0)
                            gradient: Gradient {
                                GradientStop { position: 0; color: Qt.rgba(1,0,0,1) }
                                GradientStop { position: 0.167; color: Qt.rgba(1,1,0,1) }
                                GradientStop { position: 0.333; color: Qt.rgba(0,1,0,1) }
                                GradientStop { position: 0.500; color: Qt.rgba(0,1,1,1) }
                                GradientStop { position: 0.667; color: Qt.rgba(0,0,1,1) }
                                GradientStop { position: 0.833; color: Qt.rgba(1,0,1,1) }
                                GradientStop { position: 1; color: Qt.rgba(1,0,0,1) }
                            }
                        }
                        ColorSlider {
                            id: colorValue1Slider
                            anchors.left: parent.left
                            anchors.leftMargin: 5
                            anchors.verticalCenter: parent.verticalCenter
                            width: parent.width-80
                            frontcolor: "#f00"
                            to: (colRgbMode.checked)? 255 : 360
                            onValueChanged: {
                                colorValue1Edit.text = Math.round(value)
                                Script.updateTmpColor()
                            }
                        }
                        TextField {
                            id: colorValue1Edit
                            anchors.right: parent.right
                            anchors.rightMargin: 20
                            anchors.verticalCenter: parent.verticalCenter
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            width: 50; height: 25
                            validator: IntValidator { bottom: 0; top: (colRgbMode.checked)? 255 : 360 }
                            onEditingFinished: { colorValue1Slider.value = parseInt(text) }
                        }
                        Label {
                            id: colorValue1Lab
                            anchors.right: parent.right
                            anchors.rightMargin: 0
                            anchors.verticalCenter: parent.verticalCenter
                            width: 10
                            text: "R"
                        }
                    }
                    Item {
                        height: 25
                        width: parent.width
                        LinearGradient {
                            id: colorValue2Gradient
                            property color firstcolor: "white"
                            property color lastcolor: "black"
                            anchors.left: parent.left
                            anchors.leftMargin: 5 + colorValue2Slider.leftPadding
                            anchors.verticalCenter: parent.verticalCenter
                            width: parent.width - 80 - colorValue2Slider.leftPadding - colorValue2Slider.rightPadding
                            height: 6
                            start: Qt.point(0,0)
                            end: Qt.point(width,0)
                            gradient: Gradient {
                                GradientStop { position: 0; color: colorValue2Gradient.firstcolor }
                                GradientStop { position: 1; color: colorValue2Gradient.lastcolor }
                            }
                        }
                        ColorSlider {
                            id: colorValue2Slider
                            anchors.left: parent.left
                            anchors.leftMargin: 5
                            anchors.verticalCenter: parent.verticalCenter
                            width: parent.width - 80
                            frontcolor: "#0f0"
                            onValueChanged: {
                                colorValue2Edit.text = Math.round(value)
                                Script.updateTmpColor()
                            }
                        }
                        TextField {
                            id: colorValue2Edit
                            anchors.right: parent.right
                            anchors.rightMargin: 20
                            anchors.verticalCenter: parent.verticalCenter
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            width: 50; height: 25
                            validator: IntValidator { bottom: 0; top: 255 }
                            onEditingFinished: { colorValue2Slider.value = parseInt(text) }
                        }
                        Label {
                            id: colorValue2Lab
                            anchors.right: parent.right
                            anchors.rightMargin: 0
                            anchors.verticalCenter: parent.verticalCenter
                            width: 10
                            text: "G"
                        }
                    }
                    Item {
                        height: 25
                        width: parent.width
                        LinearGradient {
                            id: colorValue3Gradient
                            property color firstcolor: "white"
                            property color lastcolor: "black"
                            anchors.left: parent.left
                            anchors.leftMargin: 5 + colorValue3Slider.leftPadding
                            anchors.verticalCenter: parent.verticalCenter
                            width: parent.width - 80 - colorValue3Slider.leftPadding - colorValue3Slider.rightPadding
                            height: 6
                            start: Qt.point(0,0)
                            end: Qt.point(width,0)
                            gradient: Gradient {
                                GradientStop { position: 0; color: colorValue3Gradient.firstcolor }
                                GradientStop { position: 1; color: colorValue3Gradient.lastcolor }
                            }
                        }
                        ColorSlider {
                            id: colorValue3Slider
                            anchors.left: parent.left
                            anchors.leftMargin: 5
                            anchors.verticalCenter: parent.verticalCenter
                            width: parent.width - 80
                            frontcolor: "#00f"
                            onValueChanged: {
                                colorValue3Edit.text = Math.round(value)
                                Script.updateTmpColor()
                            }
                        }
                        TextField {
                            id: colorValue3Edit
                            anchors.right: parent.right
                            anchors.rightMargin: 20
                            anchors.verticalCenter: parent.verticalCenter
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            width: 50; height: 25
                            validator: IntValidator { bottom: 0; top: 255 }
                            onEditingFinished: { colorValue3Slider.value = parseInt(text) }
                        }
                        Label {
                            id: colorValue3Lab
                            anchors.right: parent.right
                            anchors.rightMargin: 0
                            anchors.verticalCenter: parent.verticalCenter
                            width: 10
                            text: "B"
                        }
                    }
                    Item {
                        visible: colorSelectorView.alpha
                        height: 25
                        width: parent.width
                        ColorSlider {
                            id: colorAlphaSlider
                            anchors.left: parent.left
                            anchors.leftMargin: 5
                            anchors.verticalCenter: parent.verticalCenter
                            width: parent.width-80
                            onValueChanged: {
                                colorAlphaEdit.text = Math.round(value)
                                Script.updateTmpColor()
                            }
                        }
                        TextField {
                            id: colorAlphaEdit
                            anchors.right: parent.right
                            anchors.rightMargin: 20
                            anchors.verticalCenter: parent.verticalCenter
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            width: 50; height: 25
                            validator: IntValidator { bottom: 0; top: 255 }
                            onEditingFinished: { colorAlphaSlider.value = parseInt(text) }
                        }
                        Label {
                            anchors.right: parent.right
                            anchors.rightMargin: 0
                            anchors.verticalCenter: parent.verticalCenter
                            width: 10
                            text: "A"
                        }
                    }
                }
            }
        }
    }
    // drawer ###################################
    Drawer {
        id: drawer
        width: (root.width < 300)? root.width*0.7 : 210
        height: root.height
        ListView {
            id: drawerList
            currentIndex: 0
            anchors.fill: parent
            model: ListModel {
                ListElement { name: "Horloge"; action: "clock" }
                ListElement { name: "Fond"; action: "bg" }
                ListElement { name: "Secondes"; action: "seconds" }
                ListElement { name: "Minutes"; action: "minutes" }
                ListElement { name: "Heures"; action: "hours" }
                ListElement { name: "Semaine"; action: "week" }
                ListElement { name: "Jours"; action: "days" }
                ListElement { name: "Mois"; action: "months" }
            }
            delegate: ItemDelegate {
                width: parent.width
                text: model.name
                highlighted: ListView.isCurrentItem
                onClicked: Script.drawerActive(index,action)
            }
        }
    }
}
