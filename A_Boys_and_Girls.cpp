#include <bits/stdc++.h>
using namespace std;

int main()
{   
    
    freopen("input.txt", "r", stdin);
    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
 
    int boy {} , girl {} ;  cin >> boy >> girl ;
    stack<char> g ,b ;

    for(int i = 0 ; i < boy  ; i++){  b.push('B') ;  }
    for(int i = 0 ; i < girl ; i++){  g.push('G') ;  }   

    while(!(g.empty() and b.empty())){ 
        if(girl>boy)
            {
                    if(!g.empty()){ cout << g.top() ; g.pop() ;}
                    if(!b.empty()){ cout << b.top() ; b.pop() ;}
            }
        else{
                    if(!b.empty()){ cout << b.top() ; b.pop() ;}
                    if(!g.empty()){ cout << g.top() ; g.pop() ;}
            }
    }

}

