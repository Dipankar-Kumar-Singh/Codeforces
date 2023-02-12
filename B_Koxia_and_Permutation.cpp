#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 

void solve(int& __case__)
{
    int n ;cin >> n ;
    int k ; cin >> k ;
    set<int> s ;

    for(int i = 1 ; i <= n ; i++)  s.insert(i) ;
    
    vector<int> ans ;

    while (s.size())
    {
        vector<int> v(k,-1) ;
        int toBreak = 0 ;
        for(int i = 0 ; i < k ; i++)
        {
            if(i == k - 1)
            {
                auto it = s.begin() ;
                if(it == s.end())
                {
                    toBreak = 1 ;
                    for(int i : v) if(i != -1) ans.push_back(i) ;
                    break; ;
                }
                v[i] = *it ;
                s.erase(it) ;
            }

            else 
            {
                auto it = s.end() ;
                if(it == s.begin())
                {
                    for(auto x : v) if(x != -1) ans.push_back(x) ;
                    toBreak = 1 ;
                    break;
                }
                else it-- ;
                v[i] = *it ;
                s.erase(it) ;
            }

            
        }

        if(toBreak == 1)
        {
            break ;
        }

        for(auto &x : v) ans.push_back(x) ;

    }

    for(auto x : ans) 
        cout << x << " " ;

    cout << nl ;
}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}
