#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int total ; cin >> total ;  for(test = 1 ; test <=  total ; test++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  
int test = 0 ;

int n ; 
vector<int> v ; 
vector<int> segEnd ;

void solve()
{
    cin >> n;
    v = vector<int>(n + 1);
    for(int i = 1; i <= n ; i++) cin >> v[i] ;
    segEnd = vector<int>(n + 1, -1);

    segEnd[0] = 1 ;

    for(int i = 1 ; i <= n ; i++ )
    {
        if (segEnd[i - 1] == 1 and i + v[i] <= n)
        {
            segEnd[i + v[i]] = 1;
        }

        if(i - v[i] - 1 >= 0 and segEnd[i - v[i] - 1] == 1)
        {
            segEnd[i] = 1 ;
        }
    }

    cout << ((segEnd[n] == 1) ? "YES" : "NO") << nl;
}

signed main(){  FAST    TestCases    solve() ; }