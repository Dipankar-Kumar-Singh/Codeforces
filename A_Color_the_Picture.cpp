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

bool possible(int n , int m , vector<int> &v)
{
    bool oddPresent = 0 ;
    int sum = 0 ;
    for(int &i : v) 
    {
        sum += i/n ;

    }
}


void solve()
{
    int ans = 0 ; 
    int n , m ;
    cin >> n >> m ;

    int k ; cin >> k ;
    vector<int> v(k) ; for(auto &x : v) cin >> x ; 




    
    

    

    print(ans) ;
}

signed main(){  FAST    TestCases    solve() ; }