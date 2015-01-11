#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
void quicksort(int[],int,int);
int partition(int[],int,int);
int main(){
  int array[10] = {10,20,1,3,9,30,3,2,2,15} ;
  quicksort(array,0,9);
  for (int i=0;i<10;i++){
    cout<<array[i]<<" ";
  }
  cout<<endl;
  return 0;
}
void quicksort(int array[],int lp,int rp){
  if (lp == rp){
    return;
  }
  int index = partition(array,lp,rp);
  quicksort(array,lp,index-1);
  quicksort(array,index,rp);
  return;
}
int partition(int array[],int lp,int rp){
  int i = lp;
  int j = rp;
  int size = rp - lp + 1;
  int pivot = 0;
  for (int k=lp;k<=rp;k++){
    pivot = pivot + array[k];
  }
  pivot = pivot / size;
  while (i!=j){
    if (array[i]<=pivot){
      i++;
    }else if (array[j]>pivot){
      j--;
    }else{
      int temp = array[i];
      array[i] = array[j];
      array[j] = temp;
    }
  }
  return i;
}
