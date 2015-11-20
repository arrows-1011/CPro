#include <cstdio>
#include <algorithm>

using namespace std;
 
int main(){
    int card[5];
     
    while(scanf("%d" ,&card[0])!=EOF){
        for(int i = 1 ; i < 5 ; i++){
            scanf(",%d" ,&card[i]);
        }
         
        int cnt = 0;
        for(int i = 0 ; i < 5 ; i++){
            for(int j = 0 ; j < 5 ; j++){
                if(card[i] == card[j] && i != j) cnt++;
	    }
        }
         
        int flg = 0;
        switch(cnt){
	case 2:
	    printf("one pair\n");
	    flg = 2;
	    break;
	case 4:
	    printf("two pair\n");
	    flg = 2;
	    break;
	case 6:
	    printf("three card\n");
	    flg = 2;
	    break;
	case 8:
	    printf("full house\n");
	    flg = 2;
	    break;
	case 12:
	    printf("four card\n");
	    flg = 2;
	    break;
	default:
	    flg = 1;
        }
         
        if(flg == 2) continue;
         
        int ct = 0;
        if(flg){
            sort(card,card+5);
            for(int i = 1 ; i < 5 ; i++){
                if(card[i]-card[i-1]==1) ct++;
            }
        }
         
        if(ct==4) printf("straight\n");
        else if(card[0]==1&&card[1]==10&&card[2]==11&&card[3]==12&&card[4]==13) printf("straight\n");
        else printf("null\n");
    }
 
    return 0;
}
