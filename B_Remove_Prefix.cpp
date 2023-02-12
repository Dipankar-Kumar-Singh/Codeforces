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
   int n;   cin >> n;
   vector<int> v(n);  for (auto &x : v) cin >> x;
    reverse(all(v)) ;

    map<int,int> m ;

    for(int i = 0 ; i < n; i++)
    {
        m[ v[i] ]++ ;

        if( m[v[i]] > 1 )
        {
            cout << n - i << nl ;
            return ;
        }
    }


    cout << 0 << nl ;



}
signed main(){   FAST      TestCases      solve() ;  }



