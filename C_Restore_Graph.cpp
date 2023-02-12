#include <bits/stdc++.h>
using namespace std;
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

// FINAL SOLUTION IS ✌️3️⃣❎ FASTRE THAN FIRST ONE ..😄 [124 ms --> 46 ms]
// MEMORY USED --> 83,000 KB --> 8,000 KB 😃😃😃

int const N = 1e5 + 1 ;
vector<int> dis[N] ;
vector<int> in(N) ;

signed main()
{
    FAST  
    int n , k ; cin >> n >> k ; 

    vector<pair<int,int>> d(n) ;
    vector<int> diss(n) ;
    
    for(int i = 0 ; i < n ; i++)  {   int x ; cin >> x ;  d[i] = {x,i} ;  diss[i] = x ; }
    sort(begin(d),end(d)) ; 
    for(int i = 1 ; i < d.size() ; i++)
    {
        auto [d1,🥲] = d[i] ; auto [d2,😎] = d[i-1] ;
        if(abs(d1 - d2) > 1 or (d1==d2 and d1==0)){ cout << - 1 ;  return 0; }
    }

    queue<int> q ;
    for(auto &[dd,nn] : d)
    {
        dis[dd].push_back(nn) ;
        if(dd>0) q.push(nn) ;
    }

    int ans = 0 ;
    vector<pair<int,int>> matches ;

    while (!q.empty())
    { 
        int y = q.front() ; q.pop() ;
        int done = 0 ;
        for(auto &x : dis[diss[y]-1])
        {
            if(in[x]<k)
            {        
                done = 1 ;  in[x]++, in[y]++;
                matches.push_back({x+1,y+1}) ;
                break ;
            }
        }
        if(!done){   cout << - 1 ;  return 0;   }
        ans++ ;
    }

    cout << ans << "\n" ;
    for(auto  &[ x , y ]  : matches)  cout << x << " " << y << "\n" ;
}