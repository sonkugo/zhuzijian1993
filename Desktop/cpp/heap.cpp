#include<iostream>
#include<stdio.h>
#include <algorithm>
using namespace std;
void heapify(int array[],int);
void downward(int array[],int,int);
int extractmin(int array[],int &size);
void upward(int array[],int,int size);
void swap(int array[],int,int);
int main(){
  int array[100];
  int size = 10;
  for (int i = 0;i<10;i++){
    array[i] = random() % 10;
    cout<<array[i]<<" ";
  }
  cout<<endl;
  heapify(array,size);
  // while (size >0){
  //   cout<<extractmin(array,size)<<" ";
  // }
  // cout<<endl;
  size++;
  upward(array,0,size);
  for (int i = 0;i<size;i++)
    cout<<array[i]<<" ";
  cout<<endl;
}
void upward(int array[],int num,int size){
  int parent = size / 2 - 1;
  int i = size - 1;
  array[i] = num;
  do{
    if (array[parent]>=array[i])
      swap(array,parent,i);
    i=parent;
    parent = (parent+1)/2-1;
  }while (parent>=0);
}
int extractmin(int array[],int &size){
  int min = array[0];
  swap(array,0,size-1);				
  size = size - 1;
  downward(array,0,size);
  return min;
}
void heapify(int array[],int size){
  for (int i = size/2-1;i>=0;i--)
    downward(array,i,size);
}
void downward(int array[],int pos,int size){
  int lastpoint = size - 1; 
  int right;
  int left;
  while(pos*2+1<=lastpoint){
    left = pos*2+1;
    if (pos*2+2>lastpoint)
      right = left;
    else
      right = pos*2+2;
    if (array[pos]>array[left] || array[pos] > array[right])
      if (array[left]<=array[right]){
	swap(array,left,pos);
	pos = left;
      }
      else{
	swap(array,right,pos);
	pos = right;
      }
    else
      return;
  }
}
void swap(int array[],int pos,int i){
  int temp = array[pos];
  array[pos] = array[i];
  array[i] = temp;
}
