#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
int quicksort(int[],int,int,int,bool);
int partition(int[],int,int,int);
void mergesort(int[],int,int);
void merge(int[],int,int,int);
int main(){
  int array[10] = {1,2,3,4,5,6,7,8,9,10};
  int index = quicksort(array,0,9,5,false);
  cout<<array[index]<<endl;
  return 0;
}
int quicksort(int array[],int lp,int rp,int medindex,bool first){
  int size = rp-lp + 1;
  int group = (size + 4)/5;
  int barray[size];
  if (first && group <= 1){
    return array[size/2];
  }
  for (int i = 0;i<=9;i++){
    barray[i] = array[i];
    //   cout<<barray[i]<<" ";
  }
  // cout<<endl;
  int carray[group];
  for (int i=0;i<group;i++){
    int lowbound = lp + i * 5;
    int upbound = lp+(i+1)*5-1;
    if (upbound>rp)
      upbound = rp;
    mergesort(barray,lowbound,upbound);
    carray[i] = barray[(upbound+lowbound)/2];
    //  cout<<carray[i]<<" ";
  }
  //cout<<endl;
  mergesort(carray,0,group-1);
  int p = quicksort(carray,0,size/5-1,medindex,true);
  // cout<<"p:"<<p<<endl;
  int index = partition(array,lp,rp,p);
  // cout<<"index:"<<index<<" lp:"<<lp<<" rp:"<<rp<<endl;
  if (medindex>index)
    return quicksort(array,index+1,rp,medindex,false);
  else if (medindex < index)
    return quicksort(array,lp,index-1,medindex,false);
  else
    return index;
}
int partition(int array[],int lp,int rp,int pivot){
  int i = lp;
  int j = rp;
  int size = rp - lp + 1;
  int pivotindex;
  for (int k = lp;k<=rp;k++){
    if (pivot == array[k]){
      pivotindex = k;
      break;
    }
  }
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
void mergesort(int array[],int lp,int rp){
  if (lp == rp){
    return;
  }
  mergesort(array,lp,(lp+rp)/2);
  mergesort(array,(lp+rp)/2+1,rp);
  merge(array,lp,(lp+rp)/2,rp);
  return;
}
void merge(int array[],int lp,int mid,int rp){
  int i = lp;
  int j = mid+1;
  int size = rp+1;
  int temp[size];
  for (int n=lp;n<=rp;n++){
    if (i<=mid && j<=rp){
      if (array[i] > array[j]){
	temp[n] = array[j];
	j++;
      }else{
	temp[n] = array[i];
	i++;
      }
    }else{
      if (i<=mid){
	temp[n] = array[i++];
      }
      if (j<=rp){
	temp[n] = array[j++];
      }
    }
  }
  for (int i=lp;i<=rp;i++){
    array[i] = temp[i];
  }
  return;
}
