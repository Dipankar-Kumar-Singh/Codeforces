#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()

const int N = 1e3 +10 ;
multiset<int> s ;
vector<int> m[N] ;

signed main()
{
    FAST
    vector<pair<pair<int,int>,int>> w ; 

    int cc = 1 ;
    t_case
    {
        int c , p ; cin >> c >> p ; 
        w.push_back({{p,c},cc}) ;  cc++ ;                                       
    }

    int n ; cin >> n ;  vector<int> v(n,0) ;
    for(int i = 0 ; i < n ; i++){
        int x ; cin >> x  ; 
        v[i] = x ; 
        s.insert(x) ;  m[x].push_back(i+1) ;
    }

    int total_money = 0 , total_team = 0 ; 
    sort(all(w)) ; reverse(all(w)) ;
    vector<pair<int,int>> ans ;

    for(auto &[x,i] : w)
    {
        auto &[p,c] =  x ;
        auto it = s.lower_bound(c) ;
        if(it == s.end()) continue ;
        else
        {
            int table = *it ;
            auto &vv = m[table] ;
            int id_table = vv.back() ; vv.pop_back() ;
            total_money += p ; total_team++ ;
            s.erase(it) ;
            ans.push_back({i,id_table}) ;
        }
    }

    cout << total_team << " " << total_money << "\n" ;
    for(auto [x,y]:ans)
        cout << x << " " << y << "\n" ;
    
}

