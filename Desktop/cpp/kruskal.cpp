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
  int pointTo;
  int rank;
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
void dfs(vertex v[],edge e[],int Vsize,int Esize,vector<int> T);
bool myfunction(edge e1,edge e2){return e1.weight<e2.weight;};
int find(vertex ver,vertex v[]);
void Union(vertex &v1,vertex &v2);
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
    v[i].pointTo = i;
    v[i].rank = 0;
  }
  for (int i=0;i<5;i++)
    e[i].index = i;
  connect(v,e);
  v[0].key = 0;
  sort(e,e+5,myfunction);
  int Vsize = 4;
  int Esize= 5;
  dfs(v,e,Vsize,Esize,T);
  return 0;
}
void dfs(vertex v[],edge e[],int Vsize,int Esize,vector<int> T){
  for (int i = 0;i<Esize;i++){
    int first = e[i].head;
    int second = e[i].tail;
    int firstL = find(v[first],v);
    int secondL = find(v[second],v);
    if (firstL != secondL){
      T.push_back(i);
      cout<<e[i].weight<<endl;
      Union(v[firstL],v[secondL]);
    }
  }
}
int find(vertex ver,vertex v[]){
  while (ver.pointTo != ver.index){
    ver= v[ver.pointTo];
  }
  return ver.index;
}
void Union(vertex &v1,vertex &v2){
  if (v1.rank > v2.rank){
    v2.pointTo = v1.index;
    v1.rank++;
  }
  if (v1.rank < v2.rank){
    v1.pointTo = v2.index;
    v2.rank++;
  }
  if (v1.rank == v2.rank){
    v2.pointTo = v1.index;
    v1.rank++;
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
