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
    int n ; cin >> n ;
    vector<int> v(n) ; for (auto &x : v) cin >> x ;
    vector<vector<int>> loc(n+1000);

    for(int i = 0 ; i < n ; i++)
    {
        loc[v[i]].push_back(i) ;
    } 

    for(int c = 1 ; c <= n ; c++)
    {
        auto &l = loc[c] ;
        if (l.size() < 2)
        {
            if(l.empty()) cout << 0 <<  " " ;
            else cout << 1 << " " ;
            continue;
        }

        int tower = 1 ;

        for(int i = 1 ; i < l.size() ; i++)
        {
            if (abs(l[i] - l[i - 1]) % 2 != 0)
                tower++;
        }

        cout << tower << " " ;

    }

    cout << nl;

   

   


}
signed main(){   FAST      TestCases      solve() ;  }



