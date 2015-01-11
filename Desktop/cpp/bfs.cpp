#include <iostream>       // std::cout
#include <stack>          // std::stack
#include <vector>         // std::vector
#include <deque>          // std::deque
#include <queue>
using namespace std;
class vertex;
class edge{
public:
  int index =0;
  int endpoint=0;
  int endpoint2=0;
};
class vertex{
public:
  int index;
  bool visit = false;
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
void bfs(int,vertex v[],edge e[]);
int main ()
{
  vertex v[10];
  edge e[7];
  for (int i=0;i<10;i++)
    v[i].index=i;
  for (int i=0;i<7;i++)
    e[i].index = i;
  connect(v,e);
  for (int i=0;i<10;i++){
    if (!v[i].visit){
      bfs(i,v,e);
      //    cout<<i<<endl;
    }
  }
  return 0;
}
void bfs(int s,vertex v[],edge e[]){
  queue<int> q;
  q.push(s);
  while (!q.empty()){
    int cur = q.front();
    v[cur].visit = true;
    q.pop();
    while (!v[cur].edges.empty()){
      edge cure=v[cur].getEdge();
      int index = (cure.endpoint==cur)?cure.endpoint2:cure.endpoint;
      if (!v[index].visit){
	q.push(index);
      }
    }
  }
}
void connect(vertex v[],edge e[]){
  e[0].endpoint = 0;
  e[0].endpoint2 =2;
  e[1].endpoint = 2;
  e[1].endpoint2 =8;
  e[2].endpoint = 2;
  e[2].endpoint2 =6;
  e[3].endpoint = 4;
  e[3].endpoint2 =2;
  e[4].endpoint = 1;
  e[4].endpoint2 =3;
  e[5].endpoint = 5;
  e[5].endpoint2 =7;
  e[6].endpoint = 7;
  e[6].endpoint2 =9;
  v[0].connectEdge(e[0]);
  v[2].connectEdge(e[0]);
  v[2].connectEdge(e[1]);
  v[2].connectEdge(e[2]);
  v[2].connectEdge(e[3]);
  v[8].connectEdge(e[1]);
  v[6].connectEdge(e[2]);
  v[4].connectEdge(e[3]);
  v[1].connectEdge(e[4]);
  v[3].connectEdge(e[4]);
  v[5].connectEdge(e[5]);
  v[7].connectEdge(e[5]);
  v[7].connectEdge(e[6]);
  v[9].connectEdge(e[6]);
};
