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
    vector<int> v(n);  
    for(int i = 0 ; i < n ; i++) v[i] = i + 1 ;

    for(int i = n-1 ; i >= 0 ; i--)
    {
        if(i-1<0) break;
        swap(v[i],v[i-1]) ;
        i-- ;
    }

    for(auto x : v) cout << x << " " ;
    cout << nl; 


}
signed main(){   FAST      TestCases      solve() ;  }



