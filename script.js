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
