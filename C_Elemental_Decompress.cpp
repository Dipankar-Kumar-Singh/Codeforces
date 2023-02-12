#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 


void solve(int& __case__)
{
    int n; cin >>  n; 
    vector<int> v(n) ;
    for(auto &x : v) cin >> x ;

    set<int,greater<int>> unusedA ;
    set<int,greater<int>> unusedB ;
    for(int i = 1 ; i <= n ; i++) unusedA.insert(i) ;
    for(int i = 1 ; i <= n ; i++) unusedB.insert(i) ;

    map<int,int> m ;
    for (auto x : v) {
        m[x]++;
        if (m[x] > 2) {
            cout << "NO" << nl;
            return;
        }
    }

    map<int,int> visA ;
    map<int,int> visB ;

    vector<int> a(n, -1) , b(n, -1) ;

    for(int i = 0 ; i < n; i++)
    {   
        if(visA[v[i]]) 
        {
            if(visB[v[i]])
            {
                cout << "NO" << nl ;
                return ;
            }

            b[i] = v[i] ;
            visB[v[i]] = 1 ;
            unusedB.erase(v[i]) ;

        }
        else
        {
            visA[v[i]] = 1;
            a[i] = v[i];
            unusedA.erase(a[i]);
        }
    }


    for(int i = 0 ; i < n; i++)
    {
        if (a[i] != -1)
        {
            auto it = unusedB.lower_bound(a[i]);
            if (it == unusedB.end())
            {
                cout << "NO" << nl;
                return;
            }
            b[i] = *it;
            unusedB.erase(it);
        }

        else if(b[i] != -1)
        {
            auto it = unusedA.lower_bound(b[i]);
            if (it == unusedA.end())
            {
                cout << "NO" << nl;
                return;
            }
            a[i] = *it;
            unusedA.erase(it);
        }
    }

    cout << "YES" << nl ;
    for(int x : a) cout << x << " " ; cout << nl ;
    for(int x : b) cout << x << " " ; cout << nl ;

}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}
