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
    if (mainView.currentItem == colorSelectorView) { mainView.pop() }
    switch (action) {
    case "clock":
        if (drawerList.currentIndex != 0) { mainView.pop() }
        finish = false; break
    case "bg":
        //
        // TODO : init the bg settings
        //
        //
        //
        newview = backgroundSettingView; break
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

function initColorSelector(setting,alpha) {
    colorSelectorView.backcolor = ocsettings.getColor("col_bg")
    colorSelectorView.activecolor = ocsettings.getColor(setting)
    //
    colorSelectorView.alpha = alpha
    //
}

function colorModeSwitch() {
    var mode = ""
    if (colRgbMode.checked) {
        mode = "RGB"
        colorValue1Slider.frontcolor = "#f00"
        colorValue1Slider.backcolor = "#ddd"
        colorValue2Slider.frontcolor = "#0f0"
        colorValue2Slider.backcolor = "#ddd"
        colorValue3Slider.frontcolor = "#00f"
        colorValue3Slider.backcolor = "#ddd"
        //
        // TODO : values
        //
    }
    else {
        mode = "HSL"
        colorValue1Slider.frontcolor = "transparent"
        colorValue1Slider.backcolor = "transparent"
        colorValue2Slider.frontcolor = "transparent"
        colorValue2Slider.backcolor = "transparent"
        colorValue3Slider.frontcolor = "transparent"
        colorValue3Slider.backcolor = "transparent"
        //
        // TODO : values
        //
    }
    colorValue1Lab.text = mode[0]
    colorValue2Lab.text = mode[1]
    colorValue3Lab.text = mode[2]
}

function updateGradients() {
    //
    console.log("update gradients")
    //
}
