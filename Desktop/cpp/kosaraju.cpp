#include <iostream>       // std::cout
#include <stack>          // std::stack
#include <vector>         // std::vector
#include <deque>          // std::deque
#include <queue>
using namespace std;
class vertex;
class edge{
public:
  int index;
  int tail;
  int head;
};
class vertex{
public:
  int index;
  int leader;
  bool visit;
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
void dfs(int,vertex v[],edge e[],int &t);
int main ()
{
  vertex v[9];
  edge e[11];
  int t = 0;
  for (int i=0;i<9;i++){
    v[i].index=i;
    v[i].visit = false;
    v[i].leader = 0;
  }
  for (int i=0;i<11;i++)
    e[i].index = i;
  connect(v,e);
  for (int i=8;i>=0;i--){
    if (!v[i].visit){
      dfs(i,v,e,t);
      //    cout<<i<<endl;
    }
  }
  for (int i=0;i<9;i++){
    cout<<v[i].leader<<" "<<endl;
  }
  return 0;
}
void dfs(int s,vertex v[],edge e[],int &t){
  v[s].visit = true;
  while (!v[s].edges.empty()){
    edge cure=v[s].getEdge();
    int index = cure.head;
    if (!v[index].visit){
      dfs(index,v,e,t);
    }
  }
  t = t + 1;
  v[s].leader = t;
}
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
