#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int total ; cin >> total ;  for(test = 1 ; test <=  total ; test++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  
#define print(ans) cout << "Case #" << test << ": " << ans << "\n" ;


int const INF  = 1e18 ;
int test = 0 ;

int noOfTwos(int num)
{
    int fr = 0 ;
    while(num%2==0) 
    {
        num = num / 2 ;
        fr++ ;
    }
    return fr ;
}

void solve()
{
    int ans = 0 ; 
    int n ; cin >> n ;
    vector<int> v(n) ; for(auto &x : v) cin >> x ; 
    vector<int> twosExtractable ;

    int twos = 0 ;  
    for(int i = 1 ; i <= n ; i++)
    {
        twosExtractable.push_back(noOfTwos(i)) ;
        twos += noOfTwos(v[i-1]) ;
    }

    sort(all(twosExtractable),greater<>())  ;
    int opration = 0 ;

    for(int i = 0 ; i < twosExtractable.size() ; i++)
    {
        if(twos >= n) break;
        twos += twosExtractable[i] ;
        opration++ ;        
    }

    if(twos < n) 
    {
        cout << -1 <<  nl ;
        return ;
    }

    cout << opration << nl ;

}

signed main(){  FAST    TestCases    solve() ; }