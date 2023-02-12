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
    int G = 0 ;
    vector<int> v(n);  for (auto &x : v) cin >> x , G = gcd(G,x);

    if(G==1)
    {
            cout << 0 << nl ;
            return ;
    }

    int cost = 0 ;

    for(int i = n-1 ; i >= 0 ; i--)
    {
        // 
        
    }




}
signed main(){   FAST      TestCases      solve() ;  }



