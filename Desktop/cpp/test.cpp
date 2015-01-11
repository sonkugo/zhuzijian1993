#include <iostream>       // std::cout
#include <stack>          // std::stack
#include <vector>         // std::vector
#include <deque>          // std::deque
using namespace std;
int main ()
{
  stack<int> first;                    // empty stack
  first.push(1);
  cout<<first.top()<<endl;
  first.pop();
  return 0;
}
