#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

void solve()
{
    string s; cin >> s ;
    int n = s.size() ;

    char l = min(s.back() , s.front()) ;
    char r = max(s.back() , s.front()) ;

    vector<pair<char,int>> path ;

    for(int i = 1 ; i  + 1 < n ; i++)
    {
        if(s[i] <= r and s[i] >= l)
        {
            path.push_back({s[i],i}) ;
        }
    }

    sort(all(path), [&](pair<char, int> &p1, pair<char, int> &p2) {
        return abs(p1.first - s.front()) < abs(p2.first - s.front()) ;
    });

    int cost = 0 ;

    if (!path.empty())
    {
        for(int i = 0 ; i < path.size() ; i++)
        {
            if(i==0)
            {
                cost += (abs( s.front() - path.front().first)) ;
            }

            else 
            {
                cost += abs(path[i].first - path[i - 1].first);
            }
        }

        cost += abs(path.back().first - s.back()) ;
    }

    else 
    {
        cost += abs(s.front() - s.back()) ;
    }

    int jump = 2 + path.size() ;
    
    cout << cost << " " << jump << nl ;

    cout << 1 << " " ; 
    for(auto [c , i] : path) cout << ++i << " " ; 
    cout << n << nl;

}
signed main(){   FAST      TestCases      solve() ;  }



