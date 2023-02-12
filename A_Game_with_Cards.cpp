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
    int n;
    cin >> n;
    vector<int> v1(n);
    for (auto &x : v1)
        cin >> x;

    int m;
    cin >> m;
    vector<int> v2(m);
    for (auto &x : v2)
        cin >> x;

    int a = *max_element(begin(v1),end(v1)) ;
    int b = *max_element(begin(v2),end(v2)) ;

    cout << ((a >= b) ? "Alice" : "Bob") << nl;
    cout << ((a <= b) ? "Bob" : "Alice") << nl;

}
signed main(){   FAST      TestCases      solve() ;  }



