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
  int key;
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
void dfs(vertex v[],edge e[],int &size,vector<int> T);
int main ()
{
  vertex v[4];
  edge e[5];
  vector<int> T(5);
  vector<int>::size_type sz=T.size();
  for (int i=0;i<4;i++){
    v[i].index=i;
    v[i].visit = false;
    v[i].key = 10000;
  }
  for (int i=0;i<5;i++)
    e[i].index = i;
  connect(v,e);
  v[0].key = 0;
  int size = 4;
  for (int i=0;i<4;i++){
    if (!v[i].visit){
      dfs(v,e,size,T);
    }
  }
  // cout<<T->front()<<endl;
  // for(unsigned i = 0;i<sz;i++)
  //   cout<<T[i]<<endl;
      return 0;
}
void dfs(vertex v[],edge e[],int &size,vector<int> T){
  
  while (size>0){
    int min = 10000;
    int s = 0;
    for (int i =0;i<4;i++){
      //    cout<<v[i].key<<endl;
      if (v[i].key<min && !v[i].visit){
	min = v[i].key;
	s = i;
      }
    }
    v[s].visit = true;
    //  cout<<s<<endl;
    T.push_back(v[s].key);
    cout<<v[s].key<<endl;
    while (!v[s].edges.empty()){
      edge cure=v[s].getEdge();
      //  cout<<"edge:"<<cure.index<<" weight:"<<cure.weight<<endl;
      int index = (cure.head == s)?cure.tail:cure.head;
      // cout<<"s:"<<v[s].index<<" index"<<index<<" key"<<v[index].key<<endl;
      if (v[index].key>cure.weight && !v[index].visit){
	v[index].key = cure.weight;
      }
      
    }
    cout<<endl;
    // vertex temp = v[s];
    // v[s] = v[size-1];
    // v[size-1] = temp;
    size--;
  }
}
void connect(vertex v[],edge e[]){
  e[0].head = 0;
  e[0].tail = 1;
  e[1].head = 0;
  e[1].tail = 2;
  e[2].head = 2;
  e[2].tail = 3;
  e[3].head = 0;
  e[3].tail = 3;
  e[4].head = 1;
  e[4].tail = 3;
  e[0].weight = 0;
  e[1].weight = 3;
  e[2].weight = 1;
  e[3].weight = 2;
  e[4].weight = 4;
  v[0].connectEdge(e[0]);
  v[0].connectEdge(e[1]);
  v[0].connectEdge(e[3]);
  v[1].connectEdge(e[0]);
  v[1].connectEdge(e[4]);
  v[2].connectEdge(e[1]);
  v[2].connectEdge(e[2]);
  v[3].connectEdge(e[2]);
  v[3].connectEdge(e[3]);
  v[3].connectEdge(e[4]);
};
