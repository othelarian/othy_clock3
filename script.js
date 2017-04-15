// GLOBALS ############################

// METHODS ############################

function init() {
    //
    bgAll.color = ocsettings.getColor("col_bg")
    //
    hoursTicks.visible = false
    //
    var dte = new Date()
    //
    hoursCog.value = dte.getHours()
    root.hour = dte.getHours()
    //
    minutesTicks.visible = false
    minutesCog.visible = false
    //
    //
    timer.start()
}

function timing() {
    //
    //
}

function drawerActive(index,action) {
    var newview
    var finish = true
    switch (action) {
    case "clock":
        if (drawerList.currentIndex != 0) { mainView.pop() }
        finish = false; break
    case "bg": newview = backgroundSettingView; break
    case "seconds": newview = secondsSettingView; break
    case "minutes": newview = minutesSettingView; break
    case "hours": newview = hoursSettingView; break
    case "week": newview = weekSettingView; break
    case "days": newview = daysSettingView; break
    case "months": newview = monthsSettingView; break
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
