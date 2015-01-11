#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
void mergesort(int[],int,int,int &in);
void merge(int[],int,int,int,int &in);
int main(){
  int array[10] = {9,8,4,6,5,6,3,2,1,0} ;
  int in = 0;
  mergesort(array,0,9,in);
  for (int i=0;i<10;i++){
    cout<<array[i]<<" ";
  }
  cout<<endl<<"inversion times: "<<in<<endl;
  return 0;
}
void mergesort(int array[],int lp,int rp,int &in){
  if (lp == rp){
    return;
  }
  mergesort(array,lp,(lp+rp)/2,in);
  mergesort(array,(lp+rp)/2+1,rp,in);
  merge(array,lp,(lp+rp)/2,rp,in);
  return;
}
void merge(int array[],int lp,int mid,int rp,int &in){
  int i = lp;
  int j = mid+1;
  int size = rp+1;
  int temp[size];
  for (int n=lp;n<=rp;n++){
    if (i<=mid && j<=rp){
      if (array[i] > array[j]){
	temp[n] = array[j];
	in = in + mid - i + 1;
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
