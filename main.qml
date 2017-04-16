import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Controls 2.1
import Qt.labs.platform 1.0 as Lab

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
    // launch time ##############################
    Component.onCompleted: Script.init()
    // timer ####################################
    Timer {
        id: timer; interval: 1000; running: false; repeat: true
        onTriggered: {
            var dte = new Date()
            //
            // TODO : change hour to check
            //
            // TEST ZONE
            testi++
            dte.setHours(dte.getHours()+testi)
            // TEST ZONE
            //
            //
            if (dte.getHours() != hour) {
                hour = dte.getHours(); hoursCog.value = hour; bgElt.hoursValue = hour
            }
            if (dte.getMinutes() != minute) {
                //
                minute = dte.getMinutes()
                //
                // TEST ZONE
                //hoursElt.even = (minute%2 == 0)? true : false
                // TEST ZONE
                //
                secondsCog.even = (minute%2 == 0)? true : false
            }
            //
            // TEST ZONE
            //hoursElt.value = dte.getSeconds()%12
            // TEST ZONE
            //
            secondsCog.value = dte.getSeconds()
            //secondsTicks.value = dte.getSeconds()
        }
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
            // elements background ######################
            OCbackground { id: bgElt; anchors.fill: parent }
            // months ###################################
            OCmonthsCog { id: monthsCog; anchors.fill: parent }
            OCmonthsTicks { id: monthsTicks; anchors.fill: parent }
            // days #####################################
            OCdaysCog { id: daysCog; anchors.fill: parent }
            OCdaysTicks { id: daysTicks; anchors.fill: parent }
            // week #####################################
            OCweekCog { id: weekCog; anchors.fill: parent }
            OCweekTicks { id: weekTicks; anchors.fill: parent }
            // hours ####################################
            OChoursCog { id: hoursCog; anchors.fill: parent }
            OChoursTicks { id: hoursTicks; anchors.fill: parent }
            // minutes ##################################
            OCminutesCog { id: minutesCog; anchors.fill: parent }
            OCminutesTicks { id: minutesTicks; anchors.fill: parent }
            // seconds ##################################
            OCsecondsTicks { id: secondsTicks; anchors.fill: parent }
            OCsecondsCog { id: secondsCog; anchors.fill: parent }
        }
        // background settings view #################
        SettingsView {
            id: backgroundSettingView
            title: "Fond"
            //
            //
            listmodel: ListModel {
                ListElement {
                    label: "Couleur du fond :"
                    type: "color"
                    //
                    //
                }
            }
        }
        // seconds settings view ####################
        Item {
            id: secondsSettingView
            visible: false
            //
            //
            Text { text: "seconds settings" }
        }
        // minutes settings view ####################
        Item {
            id: minutesSettingView
            visible: false
            //
            //
            Text { text: "minutes settings" }
        }
        // hours settings view ######################
        SettingsView {
            id: hoursSettingView
            //
            //
            listmodel: ListModel {
                //ListElement { label: "color"; }
            }
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
            //
            property bool colorChanged: false
            //
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
                        text: "Couleur courante :"
                        wrapMode: TextInput.WordWrap
                    }
                    Rectangle {
                        id: currColorRect
                        anchors.horizontalCenter: parent.horizontalCenter
                        width: 50; height: 30
                        border.color: "black"
                        border.width: 1
                    }
                }
                Column {
                    spacing: 10
                    Label {
                        anchors.horizontalCenter: parent.horizontalCenter
                        text: "Nouvelle couleur :"
                        wrapMode: TextInput.WordWrap
                    }
                    Rectangle {
                        id: newColorRect
                        anchors.horizontalCenter: parent.horizontalCenter
                        width: 50; height: 30
                        border.color: "black"
                        border.width: 1
                    }
                }
            }
            Row {
                id: colbtnsRow
                anchors.top: colorsShowRow.bottom
                anchors.margins: 10
                anchors.horizontalCenter: parent.horizontalCenter
                //
                spacing: 10
                //
                Button {
                    //
                    text: "Valider"
                    enabled: colorSelectorView.colorChanged
                    height: 30
                    //
                }
                Button {
                    //
                    text: "Annuler"
                    height: 30
                    //
                }
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
            Column {
                //
                width: (parent.width < 350)? parent.width-20 : 330
                anchors.top: modeColorRow.bottom
                anchors.margins: 10
                anchors.horizontalCenter: parent.horizontalCenter
                //
                spacing: 10
                //
                Item {
                    height: 25
                    width: parent.width
                    ColorSlider {
                        id: colorValue1Slider
                        anchors.left: parent.left
                        anchors.leftMargin: 5
                        anchors.verticalCenter: parent.verticalCenter
                        width: parent.width-60
                        frontcolor: "#f00"
                        onValueChanged: {
                            //
                            //
                        }
                    }
                    Label {
                        anchors.right: parent.right
                        anchors.rightMargin: 20
                        anchors.verticalCenter: parent.verticalCenter
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        width: 30; height: 20
                        background: Rectangle {
                            color: "#f2f2f2"
                            anchors.fill: parent
                            border.color: "black"
                            border.width: 1
                        }
                        text: Math.round(colorValue1Slider.value*100)/100
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
                    ColorSlider {
                        id: colorValue2Slider
                        anchors.left: parent.left
                        anchors.leftMargin: 5
                        anchors.verticalCenter: parent.verticalCenter
                        width: parent.width - 60
                        frontcolor: "#0f0"
                        onValueChanged: {
                            //
                            //
                        }
                    }
                    Label {
                        anchors.right: parent.right
                        anchors.rightMargin: 20
                        anchors.verticalCenter: parent.verticalCenter
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        width: 30; height: 20
                        background: Rectangle {
                            color: "#f2f2f2"
                            anchors.fill: parent
                            border.color: "black"
                            border.width: 1
                        }
                        text: Math.round(colorValue2Slider.value*100)/100
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
                    ColorSlider {
                        id: colorValue3Slider
                        anchors.left: parent.left
                        anchors.leftMargin: 5
                        anchors.verticalCenter: parent.verticalCenter
                        width: parent.width - 60
                        frontcolor: "#00f"
                        onValueChanged: {
                            //
                            //
                        }
                    }
                    Label {
                        anchors.right: parent.right
                        anchors.rightMargin: 20
                        anchors.verticalCenter: parent.verticalCenter
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        width: 30; height: 20
                        background: Rectangle {
                            color: "#f2f2f2"
                            anchors.fill: parent
                            border.color: "black"
                            border.width: 1
                        }
                        text: Math.round(colorValue3Slider.value*100)/100
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
                    height: 25
                    width: parent.width
                    ColorSlider {
                        id: colorAlphaSlider
                        anchors.left: parent.left
                        anchors.leftMargin: 5
                        anchors.verticalCenter: parent.verticalCenter
                        width: parent.width-60
                        onValueChanged: {
                            //
                            //
                        }
                        //
                        //
                        sliderBg.gradient: null
                        //
                    }
                    Label {
                        anchors.right: parent.right
                        anchors.rightMargin: 20
                        anchors.verticalCenter: parent.verticalCenter
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        width: 30; height: 20
                        background: Rectangle {
                            color: "#f2f2f2"
                            anchors.fill: parent
                            border.color: "black"
                            border.width: 1
                        }
                        text: Math.round(colorAlphaSlider.value*100)/100
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
