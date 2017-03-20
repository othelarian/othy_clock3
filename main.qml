import QtQuick 2.7
import QtQuick.Window 2.2

import OCelements 1.0

Window {
    visible: true
    width: 300
    height: 300
    title: qsTr("Othy clock 3")
    // properties ###############################
    property int second
    property int minute
    property int hour
    property int weekday
    property int day
    property int month
    // launch time ##############################
    Component.onCompleted: {
        // initialize
        //
        second = 0
        //
        // init the timer
        timer.start()
    }
    // timer ####################################
    Timer {
        id: timer; interval: 1000; running: false; repeat: true
        onTriggered: {
            //
            second++
            tst1.text = second
            //
        }
    }
    // TEST PURPOSE
    Text {
        id: tst1
        x: 10; y: 10
        text: "test"
    }

    // background ###############################
    // elements #################################
    // background ###########
    // hours ################
    OChours {
        id: hoursElt
        anchors.fill: parent
        //
        //
    }
    // minutes ##############
    // seconds ##############
    OCseconds {
        id: secondsElt
        //
        anchors.fill: parent
        //
    }
}
