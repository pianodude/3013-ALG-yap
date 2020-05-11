#include <iostream>
using namespace std;
int main() {
  int x;
  int y;
  int i=1;

  
  cin>>x;
  while(x!=0)
  {
  y=x/2;
  cout<<"Case "<<i<<": ";
  cout<<y<<endl;
  i++;
  cin>>x;
  }
  return 0;
}