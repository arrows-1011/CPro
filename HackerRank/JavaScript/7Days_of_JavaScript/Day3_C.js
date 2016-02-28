function compare(a, b){
    if (a < b) return 1;
    if (a > b) return -1;
    return 0;
}

function processData(myArray) {
     myArray.sort(compare);
     var max = myArray[0];
    for (var i = 1 ; i < myArray.length ; i++) {
        if (myArray[i] != max) {
            console.log(myArray[i]);
            break;
        }
    }
}


// tail starts here
process.stdin.resume();
process.stdin.setEncoding("ascii");
_input = "";
process.stdin.on("data", function (input) {
    _input += input;
});

process.stdin.on("end", function () {
   processData(_input.split('\n')[1].split(' ').map(Number));
});
