function calc(Y, M, D){
    var date = new Date(Y, M-1, D);
    var day = date.getDay();
    return day;
}

function findDay(myDate) {
    // Return day for date myDate(MM/DD/YYYY)
    // Note that myDate contains the date in string format
    M = myDate[0] + myDate[1];
    D = myDate[3] + myDate[4];
    Y = myDate[6] + myDate[7] + myDate[8] + myDate[9];
    
      var monthNames = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"];
    console.log(monthNames[calc(Y, M, D)]);
} 

// tail starts here
process.stdin.resume();
process.stdin.setEncoding("ascii");
_input = "";
process.stdin.on("data", function (input) {
    _input += input;
});

process.stdin.on("end", function () {
    var dates = _input.split('\n');

    for (var i = 0; i < dates.length - 1; i++) {
        findDay(dates[i]);
    }
});
