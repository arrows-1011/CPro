function processData(input) {
    //Enter your code here
    var rows = input.split('\n');
    var N = rows[0];
    var num = [];
    num['a'] = 0;
    num['b'] = 1;
    num['c'] = 2;
    num['d'] = 3;
    num['e'] = 4;
    num['f'] = 5;
    num['g'] = 6;
    num['h'] = 7;
    num['i'] = 8;
    num['j'] = 9;
    num['k'] = 10;
    num['l'] = 11;
    num['m'] = 12;
    num['n'] = 13;
    num['o'] = 14;
    num['p'] = 15;
    num['q'] = 16;
    num['r'] = 17;
    num['s'] = 18;
    num['t'] = 19;
    num['u'] = 20;
    num['v'] = 21;
    num['w'] = 22;
    num['x'] = 23;
    num['y'] = 24;
    num['z'] = 25;
    
    for (var i = 0 ; i < N ; i++) {
        var str = rows[i+1];
        var res = 0;
        for (var j = 0 ; j < str.length/2 ; j++) {
            res += Math.abs(num[str[j]]-num[str[str.length-j-1]]);
        }
        console.log(res);
    }
} 

process.stdin.resume();
process.stdin.setEncoding("ascii");
_input = "";
process.stdin.on("data", function (input) {
    _input += input;
});

process.stdin.on("end", function () {
   processData(_input);
});
