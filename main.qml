import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Controls 2.1
import Qt.labs.platform 1.0

import OCelements 1.0

Window {
    visible: true
    width: 300; minimumWidth: 200
    height: 300; minimumHeight: 200
    title: qsTr("Othy clock 3")
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
    Component.onCompleted: {
        //
        testi = 0
        //
        bgAll.color = ocsettings.getColor("col_bg")
        var dte = new Date();
        //
        //
        hoursTicks.visible = false
        //
        hoursCog.value = dte.getHours()
        hour = dte.getHours()
        //
        //
        minutesTicks.visible = false
        minutesCog.visible = false
        //
        timer.start()
    }
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
    // settings access ##########################
    Rectangle {
        id: settingsBtn
        x: 5; y: 5; width: 10; height: 10
        color: "#aaa"
        opacity: 0.1
        property bool opened: false
        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onEntered: { settingsBtn.opacity = 1 }
            onExited: { settingsBtn.opacity = 0.1 }
            onClicked: { if (!settingsBtn.opened) settingsBtn.opened = true }
        }
    }
    // settings window ##########################
    Window {
        id: settings
        visible: settingsBtn.opened
        property int fwidth: 380
        property int fheight: 210
        width: fwidth; minimumWidth: fwidth; maximumWidth: fwidth
        height: fheight; minimumHeight: fheight; maximumHeight: fheight
        onVisibleChanged: {
            // bg init
            bgColorRect.color = ocsettings.getColor("col_bg")
            bgColSelector.currentColor = "blue" //ocsettings.getColor("col_bg")
            // seconds init
            //
            // minutes init
            //
            // hours init
            //
            // week init
            //
            // days init
            //
            // months init
            //
        }
        onClosing: { settingsBtn.opened = false }
        Column{
            id: settingsColumn
            y: 5; width: 100
            spacing: 2
            property int btnwidth: 80
            property int btnheight: 20
            Button {
                id: bgSettingsBtn
                width: settingsColumn.btnwidth; height: settingsColumn.btnheight
                text: "Global BG"
                onClicked: { if (!highlighted) settingsStack.replace(bgSettingsScreen) }
            }
            Button {
                id: secondsSettingsBtn
                width: settingsColumn.btnwidth; height: settingsColumn.btnheight
                text: "Seconds"
                onClicked: { if (!highlighted) settingsStack.replace(secondsSettingsScreen) }
            }
            Button {
                id: minutesSettingsBtn
                width: settingsColumn.btnwidth; height: settingsColumn.btnheight
                text: "Minutes"
                onClicked: { if (!highlighted) settingsStack.replace(minutesSettingsScreen) }
            }
            Button {
                id: hoursSettingsBtn
                width: settingsColumn.btnwidth; height: settingsColumn.btnheight
                text: "Hours"
                onClicked: { if (!highlighted) settingsStack.replace(hoursSettingsScreen) }
            }
            Button {
                id: weekSettingsBtn
                width: settingsColumn.btnwidth; height: settingsColumn.btnheight
                text: "Week"
                onClicked: { if (!highlighted) settingsStack.replace(weekSettingsScreen) }
            }
            Button {
                id: daysSettingsBtn
                width: settingsColumn.btnwidth; height: settingsColumn.btnheight
                text: "Days"
                onClicked: { if (!highlighted) settingsStack.replace(daysSettingsScreen) }
            }
            Button {
                id: monthsSettingsBtn
                width: settingsColumn.btnwidth; height: settingsColumn.btnheight
                text: "Months"
                onClicked: { if (!highlighted) settingsStack.replace(monthsSettingsScreen) }
            }
        }
        StackView {
            id: settingsStack
            anchors.left: parent.left
            anchors.leftMargin: 100
            anchors.right: parent.right
            anchors.rightMargin: 5
            anchors.top: parent.top
            anchors.topMargin: 5
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            initialItem: bgSettingsScreen
            Transition {
                id: enterAnim
                YAnimator {
                    from: -210; to: 0
                    duration: 400; easing.type: Easing.OutCubic
                }
            }
            Transition {
                id: exitAnim
                YAnimator {
                    from: 0; to: -210
                    duration: 400; easing.type: Easing.OutCubic
                }
            }
            pushEnter: enterAnim; pushExit: exitAnim
            popEnter: enterAnim; popExit: exitAnim
            replaceEnter: enterAnim; replaceExit: exitAnim
            Item {
                id: bgSettingsScreen
                visible: false
                x: 0; y: 0
                onVisibleChanged: { bgSettingsBtn.highlighted = visible }
                Row {
                    anchors.horizontalCenter: parent.horizontalCenter
                    spacing: 10
                    Label {
                        anchors.verticalCenter: parent.verticalCenter
                        text: "Choisir la couleur du fond :"
                    }
                    Rectangle {
                        id: bgColorRect
                        width: 20; height: 20
                        border.color: "black"
                        border.width: 1
                        MouseArea {
                            anchors.fill: parent
                            onClicked: { bgColSelector.open() }
                        }
                    }
                    Button {
                        height: settingsColumn.btnheight
                        text: "Défaut"
                        onClicked: {
                            ocsettings.resetSetting("col_bg")
                            var newcol = ocsettings.getColor("col_bg")
                            bgColorRect.color = newcol
                            bgColSelector.currentColor = newcol
                            bgAll.color = newcol
                        }
                    }
                }
                ColorDialog {
                    id: bgColSelector
                    onAccepted: {
                        bgColorRect.color = color
                        bgAll.color = color
                        ocsettings.setSetting('col_bg',color)
                    }
                }
            }
            Item {
                id: secondsSettingsScreen
                visible: false
                x: 0; y: 0
                onVisibleChanged: { secondsSettingsBtn.highlighted = visible }
                //
                Text { text: "test 2" }
                //
                Rectangle {
                    color: "red"
                    x: 20; y: 10; width: 20; height: 20
                }
            }
            Item {
                id: minutesSettingsScreen
                visible: false
                x: 0; y: 0
                onVisibleChanged: { minutesSettingsBtn.highlighted = visible }
                //
                //
                Text {
                    text: "minutes settings"
                }
            }
            Item {
                id: hoursSettingsScreen
                visible: false
                onVisibleChanged: { hoursSettingsBtn.highlighted = visible }
                //
                // TODO : bticks & fticks actives
                //
                //
                Text {
                    text: "hours settings"
                }
            }
            Item {
                id: weekSettingsScreen
                visible: false
                onVisibleChanged: { weekSettingsBtn.highlighted = visible }
                //
                //
                Text {
                    text: "week settings"
                }
            }
            Item {
                id: daysSettingsScreen
                visible: false
                //
                //
                Text {
                    text: "days settings"
                }
            }
            Item {
                id: monthsSettingsScreen
                visible: false
                //
                //
                Text {
                    text: "months settings"
                }
            }
        }
    }
}
