#include <iostream>
#define MAX 100

using namespace std;

void SelectionSort(int N,int array[]){
  int minIndex,tmp;

  for(int i = 0 ; i < N-1 ; i++){
    minIndex = i;
    for(int j = i+1 ; j < N ; j++){
      if(array[j] < array[minIndex]){
	minIndex = j;
      }
    }
    tmp = array[i];
    array[i] = array[minIndex];
    array[minIndex] = tmp;
  }
}

int main(){
  int N,array[MAX];

  cin >> N;
  for(int i = 0 ; i < N ; i++)
    cin >> array[i];

  SelectionSort(N,array);
  for(int i = 0 ; i < N ; i++)
    cout << array[i] << " ";
  cout << endl;

  return 0;
}
