#include <iostream>
#include <map>
#include <iterator>
#include <fstream>
#include <queue>
using namespace std; 

int main() {
    

    map<int, int> numMap; 
    
    int currentnum;
    queue <int> myqueue;

    cin>>currentnum;
    while(!cin.eof())
    {
        
        //how to scan through each x in map
        if ( numMap.find(currentnum) == numMap.end() )
        {
            numMap[currentnum] = 0;
            myqueue.push(currentnum);
        }
  
        numMap[currentnum]++;
        cin>>currentnum;
    }
  
    // loop through map and print key value
 
    
 map<int, int>::iterator itr;
    while(!myqueue.empty())
    { itr=numMap.begin();
      while(itr->first!=myqueue.front())
      {
        itr++;
      }
      
      cout<<itr->first<<" "<<itr->second<<endl;
      myqueue.pop();
    }
    return 0;
}


