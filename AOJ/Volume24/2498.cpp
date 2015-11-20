#include <bits/stdc++.h>
 
using namespace std;
 
class Dice{
public:
    int x[24],t[2];
    Dice(){
	for(int i = 0 ; i < 4 ; i++){ x[i] = 0; }
	for(int i = 0 ; i < 2 ; i++){
	    for(int j = 0 ; j < 8 ; j++){ x[j+i*8+4] = j/2+1; }
	}
	for(int i = 0 ; i < 4 ; i++){ x[i+20] = 5; }
    }
    char c(int a){
	switch(a){
	case 0:
	    return 'r';
	case 1:
	    return 'g';
	case 2:
	    return 'y';
	case 3:
	    return 'b';
	case 4:
	    return 'w';
	case 5:
	    return 'o';
	}
    }
    void U(){
	t[0] = x[4]; t[1] = x[5];
	x[4] = x[6]; x[5] = x[7];
	x[6] = x[8]; x[7] = x[9];
	x[8] = x[10]; x[9] = x[11];
	x[10] = t[0]; x[11] = t[1];
	t[0] = x[0]; x[0] = x[2];
	x[2] = x[3]; x[3] = x[1];
	x[1] = t[0];
    }
    void F(){
	t[0] = x[2]; t[1] = x[3];
	x[2] = x[13]; x[3] = x[5];
	x[13] = x[21]; x[5] = x[20];
	x[21] = x[8]; x[20] = x[16];
	x[8] = t[0]; x[16] = t[1];
	t[0] = x[6]; x[6] = x[14];
	x[14] = x[15]; x[15] = x[7];
	x[7] = t[0];
    }
    void R(){
	t[0] = x[1]; t[1] = x[3];
	x[1] = x[7]; x[3] = x[15];
	x[7] = x[21]; x[15] = x[23];
	x[21] = x[18]; x[23] = x[10];
	x[18] = t[0]; x[10] = t[1];
	t[0] = x[8]; x[8] = x[16];
	x[16] = x[17]; x[17] = x[9];
	x[9] = t[0];
    }
    void D(){
	t[0] = x[12]; t[1] = x[13];
	x[12] = x[18]; x[13] = x[19];
	x[18] = x[16]; x[19] = x[17];
	x[16] = x[14]; x[17] = x[15];
	x[14] = t[0]; x[15] = t[1];
	t[0] = x[20]; x[20] = x[22];
	x[22] = x[23]; x[23] = x[21];
	x[21] = t[0];
    }
    void B(){
	t[0] = x[0]; t[1] = x[1];
	x[0] = x[9]; x[1] = x[17];
	x[9] = x[23]; x[17] = x[22];
	x[23] = x[12]; x[22] = x[4];
	x[12] = t[0]; x[4] = t[1];
	t[0] = x[10]; x[10] = x[18];
	x[18] = x[19]; x[19] = x[11];
	x[11] = t[0];
    }
    void L(){
	t[0] = x[0]; t[1] = x[2];
	x[0] = x[19]; x[2] = x[11];
	x[19] = x[20]; x[11] = x[22];
	x[20] = x[6]; x[22] = x[14];
	x[6] = t[0]; x[14] = t[1];
	t[0] = x[4]; x[4] = x[12];
	x[12] = x[13]; x[13] = x[5];
	x[5] = t[0];
    }
    void print(){
	printf("..%c%c....\n",c(x[0]),c(x[1]));
	printf("..%c%c....\n",c(x[2]),c(x[3]));
	for(int i = 0 ; i < 2 ; i++){
	    for(int j = 0 ; j < 8 ; j++){
		printf("%c",c(x[j+i*8+4]));
	    }
	    printf("\n");
	}
	printf("..%c%c....\n",c(x[20]),c(x[21]));
	printf("..%c%c....\n",c(x[22]),c(x[23]));
    }
};
 
int main(){
    Dice d;
    char ch;
    while(cin >> ch){
	if(ch == 'U') d.U(); 
	if(ch == 'F') d.F(); 
	if(ch == 'R') d.R(); 
	if(ch == 'D') d.D(); 
	if(ch == 'B') d.B(); 
	if(ch == 'L') d.L(); 
    }
    d.print();
    return 0;
}
