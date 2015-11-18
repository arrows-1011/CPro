#include <iostream>
#define MAX 100

using namespace std;

void BubbleSort(int N,int array[]){
  int tmp;

  for(int i = N-1 ; i > 0 ; i--){
    for(int j = 0 ; j < i ; j++){
      if(array[j+1] < array[j]){
	tmp = array[j];
	array[j] = array[j+1];
	array[j+1] = tmp;
      }
    }
  }

}


int main(){
  int N,array[MAX];

  cin >> N;
  for(int i = 0 ; i < N ; i++)
    cin >> array[i];

  BubbleSort(N,array);

  for(int i = 0 ; i < N ; i++)
    cout << array[i] << " ";

  cout << endl;

  return 0;
}
