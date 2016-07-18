Notification.requestPermission()
var last_showed = 0;
setInterval(function() {
    var last_active = document.getElementsByClassName("_2v6o")[0].innerText.split(" ")[1].toLowerCase()
    document.getElementsByClassName("_2v6o")[0].innerHTML
    if (last_active === "1m" || last_active === "now") {
        var time_now = new Date().getTime();
        if (time_now - last_showed > 60 * 1000) {
            new Notification("Go Go Go\n" + document.getElementsByClassName("_3oh-")[0].innerText.split(" ")[0] + " is active now!");
            last_showed = time_now;
        }
    }
}, 1000);
