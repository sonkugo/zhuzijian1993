#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
int quicksort(int[],int,int,int);
int partition(int[],int,int);
int main(){
  int array[10] = {10,2,21,5,1,2,10,6,10,4} ;
  int index = quicksort(array,0,9,5);
  cout<<array[index]<<endl;
  return 0;
}
int quicksort(int array[],int lp,int rp,int medindex){
  int index = partition(array,lp,rp);
  if (medindex>index)
    return quicksort(array,index,rp,medindex);
  else if (medindex < index)
    return quicksort(array,lp,index-1,medindex);
  else
    return index;
}
int partition(int array[],int lp,int rp){
  int i = lp;
  int j = rp;
  int size = rp - lp + 1;
  int pivotindex = rand() % size+lp;
  int pivot = array[pivotindex];
  while (i<=j){
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
  int temp = array[j];
  array[j] =array[pivotindex];
  array[pivotindex] = temp;
  return j;
}
