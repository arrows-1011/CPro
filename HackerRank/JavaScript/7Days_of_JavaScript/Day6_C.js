function dfs(x, y, H, W, mat) {
    var res = 0;
    for (var i = -1 ; i <= 1 ; i++) {
        for (var j = -1 ; j <= 1 ; j++) {
            var nx = x + i;
            var ny = y + j;
            if (0 <= nx && nx < W && 0 <= ny && ny < H) {
                if (mat[ny][nx] == 1) {
                    mat[ny][nx] = 0;
                    res += dfs(nx, ny, H, W, mat) + 1;
                }
            }
        }
    }
    return res;
}

function processData(input) {
    //Enter your code here
     var rows = input.split('\n');
     var mat = [];
     var H = rows[0], W = rows[1];
     for (var i = 0 ; i < H ; i++) {
         mat[i] = [];
         mat[i] = rows[i+2].split(' ').map(Number);
     } 
     
     var res = 0;
     for (var i = 0 ; i < H ; i++) {
        for (var j = 0 ; j < W ; j++) {
            if (mat[i][j] == 1) {
                mat[i][j] = 0;
                res = Math.max(res, dfs(j, i, H, W, mat) + 1);
            }
        }
     }
     console.log(res);
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
