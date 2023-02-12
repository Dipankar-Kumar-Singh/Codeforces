#include <bits/stdc++.h>
using namespace std;
#define TestCases   int _test {1} ; ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  

int const limit = 1e6 ;
int const N = 2e5 ;

signed main()
{   
    FAST  

    int n ; cin >>n ; 
    vector<pair<int,int>> v(n) ;

    for(auto &[x,y] : v )  { cin >> x >> y; }
    set<pair<int,int>> s(all(v)) ;

    for(auto &point : v )
    {
        queue<pair<int,int>> q ;
        q.push(point) ;

        while (q.size())
        {
            pair<int,int> p = q.front() ; q.pop() ;
            auto &[x,y] = p ;

            if(!s.count(p))
            {
                cout << x << " " << y << nl ;
                break;
            }
  
            if(abs(x+1)<=limit ) q.push({x+1,y}) ;
            if(abs(x-1)<=limit ) q.push({x-1,y}) ;
            if(abs(y+1)<=limit ) q.push({x,y+1}) ;
            if(abs(y-1)<=limit ) q.push({x,y-1}) ;
        }
    }

}

