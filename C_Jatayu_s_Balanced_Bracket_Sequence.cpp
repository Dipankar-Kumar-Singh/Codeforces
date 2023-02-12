#include <bits/stdc++.h>
using namespace std;
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


struct DSU {
    vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 1) { iota(f.begin(), f.end(), 0); }
    int leader(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) { return leader(x) == leader(y); }
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return false;
        // Addig this extra 
        if(siz[x] < siz[y]) swap(x,y) ;
        //
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) { return siz[leader(x)]; }
};


void solve()
{
    int n ; cin >> n ;
    n = 2*n ;   
    string s; cin >> s ;

    DSU dsu(n+10) ;
    vector<int> v ;
    
    map<int,vector<int>> m ;
    vector<int> bad(n) ;
    //indexs ;
    
    int prevLevel = 0 ; 

    for(int i = n - 1 ; i >=0  ; i--)
    {
        if(!v.empty())
        {
            if(s[i]==')')
            {
                m[v.size()].push_back(i) ;
                v.push_back(i) ;
                continue; 
            }

            int j = v.back() ;
            v.pop_back() ;

            int currLevel = v.size() ;

            dsu.merge(i,j) ;
            m[v.size()].push_back(j) ;
            m[v.size()].push_back(j) ;

            // cout << "prev: L = " << prevLevel << " curLevel = " << currLevel << nl ;
            // for(auto [level , vec ] : m )
            // {
            //     cout << "Level " << level << "  =  " ;
            //     for(auto &x : vec) cout << x << " " ; 
            //     cout << nl ; 
            // }

            // cout << nl ;

            if (prevLevel > currLevel)
            {
                auto& level = m[prevLevel] ;
                int n = level.size() ;
                for(int i = 0 ; i < n;  i++) dsu.merge(level[i],level[0]) ;
                level.clear();
            }

            prevLevel = currLevel ;
        }

        else 
        {
            if (s[i]==')')
            {
                m[v.size()].push_back(i) ;
                v.push_back(i);
            }

            else 
            {
                // --> "("
                bad[i] = 1 ;
                for(auto& [level , node ] : m)
                {
                    int y = node.back() ;
                    for(auto &x : node)
                    {
                        dsu.merge(x,y) ;
                    }
                }
                m.clear(); 
                prevLevel = -1 ;
            }
        }
    }

    if(m.size())
    {
        for(auto& [level , node ] : m)
        {
            int y = node.back() ;
            for(auto &x : node)
            {
                dsu.merge(x,y) ;
            }
        }
    }


    set<int> par ;
    for(int i = 0 ; i < n; i++)
    {
        if(!bad[i])
        {
            par.insert(dsu.leader(i)) ;
        }
    }


    cout << par.size() << nl ;

}




signed main()
{
    FAST
    int t ; cin >> t ; while(t--) solve() ;

}