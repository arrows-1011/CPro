//Write your code below this line.
for (var s of my_array) {
    var isPal = true;
   for (var i = 0 ; i < s.length/2 ; i++) {
       if (s[i] != s[s.length-i-1]) {
           isPal = false;
           break;
       }
   }
    if (isPal) {
        console.log(s);
    }
}
