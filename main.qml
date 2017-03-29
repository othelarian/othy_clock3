import QtQuick 2.7
import QtQuick.Window 2.2

import OCelements 1.0

Window {
    visible: true
    width: 300; minimumWidth: 200
    height: 300; minimumHeight: 200
    title: qsTr("Othy clock 3")
    // properties ###############################
    property int minute: -1
    property int hour: -1
    property int weekday: -1
    property int day: -1
    property int month: -1
    // launch time ##############################
    Component.onCompleted: {
        timer.start()
    }
    // timer ####################################
    Timer {
        id: timer; interval: 1000; running: false; repeat: true
        onTriggered: {
            var dte = new Date()
            //
            if (dte.getMinutes() != minute) {
                //
                minute = dte.getMinutes()
                //
                //
                secondsElt.even = (minute%2 == 0)? true : false
            }
            //
            // TEST ZONE
            // TEST ZONE
            //
            secondsElt.value = dte.getSeconds()
        }
    }
    // main background ##########################
    OCbackground { id: bgElt; anchors.fill: parent }
    // hours ################
    OChours {
        id: hoursElt
        anchors.fill: parent
        //
        //
    }
    // minutes ##############
    // seconds ##############
    OCseconds { id: secondsElt; anchors.fill: parent }
}
