#include <iostream>       // std::cout
#include <stack>          // std::stack
#include <vector>         // std::vector
#include <deque>          // std::deque
#include <queue>
#include <algorithm>
using namespace std;
class vertex;
class edge{
public:
  int index;
  int tail;
  int head;
  int weight;
};
class vertex{
public:
  int index;
  bool visit;
  int distance;
  int pre;
  vector<edge> edges;
  void connectEdge(edge e){
    edges.push_back(e);
  }
  edge getEdge(){
    edge e = edges.back();
    edges.pop_back();
    return e;
  }
};
void connect(vertex v[],edge e[]);
void dfs(vertex v[],edge e[],int &size);
int main ()
{
  vertex v[9];
  edge e[11];
  for (int i=0;i<9;i++){
    v[i].index=i;
    v[i].visit = false;
    v[i].distance = 10000;
  }
  for (int i=0;i<11;i++)
    e[i].index = i;
  connect(v,e);
  v[0].distance = 0;
  int size = 9;
  for (int i=0;i<8;i++){
    if (!v[i].visit){
      dfs(v,e,size);
      //    cout<<i<<endl;
    }
  }
  return 0;
}
void dfs(vertex v[],edge e[],int &size){
  while (size > 0){
    int min = v[0].distance;
    int s = 0;
    for (int i =0;i<size;i++)
      if (v[i].distance<min){
	min = v[i].distance;
	s = i;
      }
    v[s].visit = true;
    while (!v[s].edges.empty()){
      edge cure=v[s].getEdge();
      int index = cure.head;
      if (v[index].distance>v[s].distance+cure.weight){
	v[index].distance = v[s].distance+cure.weight;
	v[index].pre = s;
      }
    }
    vertex temp = v[0];
    v[0] = v[size-1];
    v[size-1] = temp;
    size--;
  }
}
// void heapify(vertex v[],int size){
//   vertex temp = v[0];
//   v[0] = v[size-1];
//   v[size-1] = temp;
//   int i=0;
//   while (i*2+2<=size){
//     if (v[i*2+1].distance<v[i].distance || v[i*2+2].distance<v[i].distance)
//       if (v[i*2+1].distance<v[i*2+2].distance){
// 	temp = v[i*2+1];
// 	v[i*2+1] = v[i];
// 	v[i] = temp;
	
//       }
//   }
//}
void connect(vertex v[],edge e[]){
  e[0].head = 0;
  e[0].tail = 6;
  e[1].head = 3;
  e[1].tail = 0;
  e[2].head = 6;
  e[2].tail = 3;
  e[3].head = 8;
  e[3].tail = 6;
  e[4].head = 5;
  e[4].tail = 8;
  e[5].head = 1;
  e[5].tail = 5;
  e[6].head = 8;
  e[6].tail = 1;
  e[7].head = 2;
  e[7].tail = 8;
  e[8].head = 4;
  e[8].tail = 2;
  e[9].head = 7;
  e[9].tail = 4;
  e[10].head = 2;
  e[10].tail = 7;
  e[0].weight = 4;
  e[1].weight = 5;
  e[2].weight = 7;
  e[3].weight = 1;
  e[4].weight = 8;
  e[5].weight = 3;
  e[6].weight = 6;
  e[7].weight = 7;
  e[8].weight = 2; 
  e[9].weight = 1;
  e[10].weight = 10;
  v[0].connectEdge(e[1]);
  v[1].connectEdge(e[6]);
  v[2].connectEdge(e[8]);
  v[3].connectEdge(e[2]);
  v[4].connectEdge(e[9]);
  v[5].connectEdge(e[5]);
  v[6].connectEdge(e[3]);
  v[6].connectEdge(e[0]);
  v[7].connectEdge(e[10]);
  v[8].connectEdge(e[4]);
  v[8].connectEdge(e[7]);
};
