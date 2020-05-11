#include <iostream>
#include <queue>
#include <string>

//For each test case, output one line per car, in the same order as the input,
//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1842

using namespace std;
int main() {
    queue<int> left;
    queue<int> right;
    queue<int> cars;

    // parallel data structure
    queue<int> cartimes;
    queue<string> sides;


    int c;
    int n;
    int t;
    int m;
    int arrivetime;
    string bank;
    char boat;
    int ct; //current time
    int nt; //new time
    cin >> c;

    for (int x = 0; x < c; x++) 
    {

        cin >> n;
        cin >> t;
        cin >> m;
        
        boat = 'l';
        for (int b = 0; b < m; b++) {
            cin >> arrivetime;
             cartimes.push(arrivetime);
            cin >> bank;
             sides.push(bank);
            if (bank == "left") {
                left.push(arrivetime);
            } else if(bank=="right") {
                right.push(arrivetime);
            }
        }

        ct = 0;
        while (!left.empty()||!right.empty()) {

            switch (boat) {
            case 'l':
              if(!left.empty())
              { //pickup from left
                for (int y = 0; y < n; y++) {
                    if (left.front() <= ct && !left.empty()) {
                        cars.push(ct);
                        left.pop();
                    } 
                        
                    
                }
              }
                if (!cars.empty()) {
                    while (!cars.empty()) {
                        cout << cars.front() + t << endl;
                        cars.pop();
                    }
                    boat = 'r';
                    ct = ct + t;
                }
                 else if (right.front() <= ct && !right.empty()) {
                    
                        ct = ct + t;
                        boat = 'r';
                        
                    
                } else{ //not traveling
                
                    ct++;
                }
                break;
            

            case 'r': 
                if(!right.empty())
				        {
                  for (int i = 0; i < n; i++) {
                      if (right.front() <= ct && !right.empty()) {
                          cars.push(ct);
                          right.pop();
                      } 
                          
                      
                  }
				        }
                //traveling
                if (!cars.empty()) {
                    while (!cars.empty()) {
                        cout << cars.front() + t << endl;
                        cars.pop();
                    }
                    boat = 'l';
                    ct = ct + t;
                } 
                else if (left.front() <= ct && !left.empty()) {
                    
                        ct = ct + t;
                        boat = 'l';
                    
                } else{ //not traveling
                
                    ct++;
                }
            
            break;
            }
        }

        cout << endl;
        
    }
    return 0;
}