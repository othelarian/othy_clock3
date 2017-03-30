import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Controls 2.1

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
        bgAll.color = ocsettings.bgGlobal
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
    //
    // TODO : other elements
    //
    // hours ####################################
    OChoursCog { id: hoursCog; anchors.fill: parent }
    OChoursTicks { id: hoursTicks; anchors.fill: parent }
    // minutes ##################################
    OCminutesTicks { id: minutesTicks; anchors.fill: parent }
    OCminutesCog { id: minutesCog; anchors.fill: parent }
    // seconds ##################################
    //
    //OCsecondsTicks { id: secondsTicks; anchors.fill: parent }
    //
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
        property int fwidth: 320
        property int fheight: 210
        width: fwidth; minimumWidth: fwidth; maximumWidth: fwidth
        height: fheight; minimumHeight: fheight; maximumHeight: fheight
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
                //
                //
            }
            Button {
                id: secondsSettingsBtn
                width: settingsColumn.btnwidth; height: settingsColumn.btnheight
                text: "Seconds"
                //
            }
            Button {
                id: minutesSettingsBtn
                width: settingsColumn.btnwidth; height: settingsColumn.btnheight
                text: "Minutes"
                //
            }
            Button {
                width: settingsColumn.btnwidth; height: settingsColumn.btnheight
                text: "Hours"
                //
            }
            Button {
                width: settingsColumn.btnwidth; height: settingsColumn.btnheight
                text: "Week"
                //
            }
            Button {
                width: settingsColumn.btnwidth; height: settingsColumn.btnheight
                text: "Days"
                //
            }
            Button {
                width: settingsColumn.btnwidth; height: settingsColumn.btnheight
                text: "Months"
                //
            }
        }
        StackView {
            id: settingsStack
            width: 210; x: 100; y: 5
            initialItem: bgSettingsScreen
            //
            //
            Item {
                id: bgSettingsScreen
                visible: false
                onVisibleChanged: {
                    //
                    console.log("test visibility: "+visible)
                    //
                    bgSettingsBtn.highlighted = true
                    //
                }
                //
                Text { text: "test" }
                //
            }
            Item {
                id: secondsSettingsScreen
                visible: false
                //
                //
            }
            Item {
                id: minutesSettingsScreen
                visible: false
                //
                //
            }
            Item {
                id: hoursSCreen
                visible: false
                //
                //
            }
            Item {
                id: weekScreen
                visible: false
                //
                //
            }
            Item {
                id: daysScreen
                visible: false
                //
                //
            }
            Item {
                id: monthsScreen
                visible: false
                //
                //
            }
        }
    }
}
