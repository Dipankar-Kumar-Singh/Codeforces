#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

int n ;
vector<int> capacity ;
multiset<pair<int,int>> s ;

void solve()
{
    int q ; cin >> q ;

    if(q == 1)
    {
        int p , x ;
        cin >> p >> x ;
        --p ;

        while (x > 0)
        {
            auto it = s.lower_bound({p, -1});
            if (it == s.end())  return;

            auto [index, cap] = *it;
            s.erase(it) ;

            cap = cap - x ;

            if(cap > 0 )
            {
                x = 0 ;
                s.insert({index, cap}) ;
            } 

            else 
            {
                x = abs(cap) ; 
            }
        }
    }

    else if(q == 2)
    {
        int k ; cin >> k ;
        --k ;

        auto it = s.lower_bound({k,-1}) ;

        if (it == s.end() or (it->first) != k)
        {
            cout << capacity[k] << nl ;
            return ;
        }

        cout <<  capacity[it -> first] - (it -> second) << nl;
    }
}

signed main()
{
    FAST
    cin >> n ; 
    capacity = vector<int>(n) ;
    for(auto &x  : capacity) cin >> x ;

    for(int i = 0 ; i < n; i++) s.insert( { i , capacity[i]} ) ;

    int q ; cin >>  q ;
    while(q--) solve();
}
