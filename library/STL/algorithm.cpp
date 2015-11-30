#include <iostream>
#include <algorithm>

#define N 5

bool cmp(int a,int b){
    return a > b;
}

int main(){
    /*
      std::is_sorted(first, last)
      Checks if the elements in range [first, last) are sorted in ascending order.
     */
    int a[N] = {1,2,3,4,5};
    if(std::is_sorted(a,a+N)){
	std::cout << "OK" << std::endl;
    }else{
	std::cout << "NG" << std::endl;
    }
    int b[N] = {3,1,2,5,4};
    if(std::is_sorted(b,b+N)){
	std::cout << "OK" << std::endl;
    }else{
	std::cout << "NG" << std::endl;
    }
    if(std::is_sorted(b+1,b+3)){
	std::cout << "OK" << std::endl;
    }else{
	std::cout << "NG" << std::endl;
    }
    int c[N] = {5,4,3,2,1};
    if(std::is_sorted(c,c+N,cmp)){
	std::cout << "OK" << std::endl;
    }else{
	std::cout << "NG" << std::endl;
    }
    return 0;
}
