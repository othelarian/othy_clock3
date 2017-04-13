import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Controls 2.1
import Qt.labs.platform 1.0 as Lab

import OCelements 1.0

Window {
    id: root
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
        Item {
            id: backgroundSettingView
            visible: false
            //
            //
            Text { text: "bg settings" }
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
        Item {
            id: hoursSettingView
            visible: false
            //
            //
            Text { text: "hours settings" }
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
            //
            Text { text: "color selector" }
        }
    }
    // drawer ###################################
    Drawer {
        id: drawer
        width: root.width*0.6
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
                onClicked: {
                    var newview
                    var finish = false
                    switch (action) {
                    case "clock":
                        if (drawerList.currentIndex != 0) { mainView.pop() }
                        break
                    case "bg": finish = true; newview = backgroundSettingView; break
                    case "seconds": finish = true; newview = secondsSettingView; break
                    case "minutes": finish = true; newview = minutesSettingView; break
                    case "hours": finish = true; newview = hoursSettingView; break
                    case "week": finish = true; newview = weekSettingView; break
                    case "days": finish = true; newview = daysSettingView; break
                    case "months": finish = true; newview = monthsSettingView; break
                    }
                    if (finish) {
                        //
                        // TODO : init the settings selected
                        //
                        if (drawerList.currentIndex == 0) { mainView.push(newview) }
                        else { mainView.replace(newview) }
                    }
                    drawerList.currentIndex = index
                    drawer.close()
                }
            }
        }
    }
}
