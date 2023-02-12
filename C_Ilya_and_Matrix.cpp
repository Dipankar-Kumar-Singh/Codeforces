#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

long long power(long long a, long long b){long long res=1;while(b>0){if(b&1){res=(res*a);}a=(a*a);b =b>>1;}return (res);}

void solve()
{
    int n;   cin >> n;
    vector<int> v(n);   
    for (auto &x : v) cin >> x;

    sort(all(v)) ;
    reverse(all(v)) ;
    int s = 0 ;

    for (int m = 1; m <= n; m *= 4)
        s += accumulate(v.begin(), v.begin() + m, 0LL);

    cout << s << endl ;

}
signed main(){   FAST      solve() ;  }



