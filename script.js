// GLOBALS ############################

var currview
var qmlsetting = {
    "list": ["bg"],
    "seconds": {},
    "minutes": {},
    "hours": {},
    "week": {},
    "days": {},
    "months": {}
}

// METHODS ############################

// CLOCK & TIMER ############

function init() {
    // init qmlsetting
    qmlsetting["bg"] = {
        "view": backgroundSettingView,
        "setting_list": ["col_bg"],
        "col_bg": {
            type: "color", alpha: false, mod: false,
            label: "Couleur du fond :",
            defvalue: ocsettings.getColor("col_bg",true),
            actvalue: ocsettings.getColor("col_bg"),
            tmpvalue: ocsettings.getColor("col_bg")
        }
    }
    //
    qmlsetting["seconds"].view = secondsSettingView
    qmlsetting["minutes"].view = minutesSettingView
    qmlsetting["hours"].view = hoursSettingView
    qmlsetting["week"].view = weekSettingView
    qmlsetting["days"].view = daysSettingView
    qmlsetting["months"].view = monthsSettingView
    //
    //
    // init visuals
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
    var dte = new Date()
    //
    // TEST ZONE
    root.testi++
    dte.setHours(dte.getHours()+root.testi)
    // TEST ZONE
    //
    if (dte.getHours() != root.hour) {
        hour = dte.getHours()
        hoursCog.value = hour
        bgElt.hoursValue = hour
        //
        // TODO : hours ticks
        // TODO : separate hours bg ?
        //
    }
    if (dte.getMinutes() != minute) {
        //
        //
    }
    //
    //
}

// SETTINGS #################

function drawerActive(index,action) {
    var newview
    var finish = true
    currview = action
    if (mainView.currentItem == colorSelectorView) { mainView.pop() }
    if (action == "clock") {
        if (drawerList.currentIndex != 0) { mainView.pop() }
        finish = false
    }
    else { newview = qmlsetting[action].view }
    if (finish) {
        if (drawerList.currentIndex == 0) { mainView.push(newview) }
        else { mainView.replace(newview) }
    }
    drawerList.currentIndex = index
    drawer.close()
}

function initSettingView() {
    qmlsetting[currview].view.listmodel.clear()
    var settings_mod = false
    var settings_cancel = false
    var settings_reset = false
    for (var i=0;i<qmlsetting[currview].setting_list.length;i++) {
        var elt = qmlsetting[currview].setting_list[i]
        //
        var obj = {
            label: qmlsetting[currview][elt].label,
            type: qmlsetting[currview][elt].type,
            setting: elt,
            tmpvalue: qmlsetting[currview][elt].tmpvalue
        }
        //
        switch (obj.type) {
        case "color": obj.alpha = qmlsetting[currview][elt].alpha; break
        case "number":
            //
            break
        case "bool":
            //
            break
        }
        //
        qmlsetting[currview].view.listmodel.append(obj)
        //
        // TODO : check for settings mod/cancel/reset
        //
    }
    qmlsetting[currview].view.settings_mod = settings_mod
    qmlsetting[currview].view.settings_cancel = settings_cancel
    qmlsetting[currview].view.settings_reset = settings_reset
}

function validateSettings() {
    //
    console.log("validate settings")
    //
}

function setCancelMode() {
    //
    console.log("set cancel mode")
    //
}

function validateCancelMode() {
    //
    //
}

function cancelCancelMode() {
    //
    //
}

function setResetMode() {
    //
    console.log("set reset mode")
    //
}

function validateResetMode() {
    //
    //
}

function cancelResetMode() {
    //
    //
}

// COLOR SELECTOR ###########

function initColorSelector(setting,alpha) {
    colorSelectorView.backcolor = ocsettings.getColor("col_bg")
    colorSelectorView.setting = setting
    var tmpcol = qmlsetting[currview][setting].tmpvalue
    colorSelectorView.activecolor = qmlsetting[currview][setting].actvalue
    colorSelectorView.currentcolor = tmpcol
    colorSelectorView.colorChanged = false
    colorValue1Slider.value = Math.round((colRgbMode.checked)? tmpcol.r*255 : tmpcol.hslHue*360)
    colorValue2Slider.value = Math.round((colRgbMode.checked)? tmpcol.g*255 : tmpcol.hslSaturation*255)
    colorValue3Slider.value = Math.round((colRgbMode.checked)? tmpcol.b*255 : tmpcol.hslLightness*255)
    colorValue1Edit.text = Math.round(colorValue1Slider.value)
    colorValue2Edit.text = Math.round(colorValue2Slider.value)
    colorValue3Edit.text = Math.round(colorValue3Slider.value)
    colorSelectorView.alpha = alpha
    var h = tmpcol.hslHue
    var s = tmpcol.hslSaturation
    var l = tmpcol.hslLightness
    colorValue2Gradient.firstcolor = Qt.hsla(h,0,l,1)
    colorValue2Gradient.lastcolor = Qt.hsla(h,1,l,1)
    colorValue3Gradient.firstcolor = Qt.hsla(h,s,0,1)
    colorValue3Gradient.lastcolor = Qt.hsla(h,s,1,1)
}

function colorModeSwitch() {
    var mode = "", v1, v2, v3
    if (colRgbMode.checked) {
        mode = "RGB"
        colorValue1Slider.frontcolor = "#f00"
        colorValue1Slider.backcolor = "#ddd"
        colorValue2Slider.frontcolor = "#0f0"
        colorValue2Slider.backcolor = "#ddd"
        colorValue3Slider.frontcolor = "#00f"
        colorValue3Slider.backcolor = "#ddd"
        v1 = Math.round(colorSelectorView.currentcolor.r*255)
        v2 = Math.round(colorSelectorView.currentcolor.g*255)
        v3 = Math.round(colorSelectorView.currentcolor.b*255)
    }
    else {
        mode = "HSL"
        colorValue1Slider.frontcolor = "transparent"
        colorValue1Slider.backcolor = "transparent"
        colorValue2Slider.frontcolor = "transparent"
        colorValue2Slider.backcolor = "transparent"
        colorValue3Slider.frontcolor = "transparent"
        colorValue3Slider.backcolor = "transparent"
        v1 = Math.round(colorSelectorView.currentcolor.hslHue*360)
        v2 = Math.round(colorSelectorView.currentcolor.hslSaturation*255)
        v3 = Math.round(colorSelectorView.currentcolor.hslLightness*255)
    }
    colorValue1Slider.value = v1
    colorValue1Edit.text = v1
    colorValue2Slider.value = v2
    colorValue2Edit.text = v2
    colorValue3Slider.value = v3
    colorValue3Edit.text = v3
    colorValue1Lab.text = mode[0]
    colorValue2Lab.text = mode[1]
    colorValue3Lab.text = mode[2]
    checkColor()
}

function updateTmpColor() {
    var tmpcol, v1, v2, v3, a
    a = (colorSelectorView.alpha)? Math.round(colorAlphaSlider.value)/255 : 1
    v1 = Math.round(colorValue1Slider.value)/ ((colRgbMode.checked)? 255 : 360)
    v2 = Math.round(colorValue2Slider.value)/255
    v3 = Math.round(colorValue3Slider.value)/255
    if (colRgbMode.checked) { tmpcol = Qt.rgba(v1,v2,v3,a) }
    else { tmpcol = Qt.hsla(v1,v2,v3,a) }
    colorSelectorView.currentcolor = tmpcol
    var h = tmpcol.hslHue
    var s = tmpcol.hslSaturation
    var l = tmpcol.hslLightness
    colorValue2Gradient.firstcolor = Qt.hsla(h,0,l,1)
    colorValue2Gradient.lastcolor = Qt.hsla(h,1,l,1)
    colorValue3Gradient.firstcolor = Qt.hsla(h,s,0,1)
    colorValue3Gradient.lastcolor = Qt.hsla(h,s,1,1)
    checkColor()
}

function checkColor() {
    var col1 = colorSelectorView.currentcolor
    var col2 = qmlsetting[currview][colorSelectorView.setting].tmpvalue
    if (Math.round(col1.r*255) != Math.round(col2.r*255)) { colorSelectorView.colorChanged = true }
    else if (Math.round(col1.g*255) != Math.round(col2.g*255)) { colorSelectorView.colorChanged = true }
    else if (Math.round(col1.b*255) != Math.round(col2.b*255)) { colorSelectorView.colorChanged = true }
    else { colorSelectorView.colorChanged = false }
}

function validColor() {
    qmlsetting[currview][colorSelectorView.setting].tmpvalue = colorSelectorView.currentcolor
    mainView.pop()
}
