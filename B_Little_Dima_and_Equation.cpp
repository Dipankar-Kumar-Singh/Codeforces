#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" ;

int a ,  b  , c ;

int s(int x)
{
    int sum = 0 ;
    while (x)
    {
       sum  +=  x%10 ;
       x/=10 ;
    }

    return sum ; 
}


#define ll long long 
ll power(ll a, ll b){ll res=1;while(b>0){if(b&1){res=(res*a);}a=(a*a);b =b>>1;}return (res);}

signed main()
{
    FAST 
    cin >> a >> b >> c ;

    vector<int> sol ; 

    for(int num = 1 ; num <= 82 ; num++)
    {
        int n  = b * ( power(num,a)) + c ;

        if(s(n) == num  and n<(int)(1e9))
        {
            sol.push_back(n) ;
        }        
    }

    cout << sol.size()  << nl ;

    if(sol.empty()) 
    {
        exit(0) ;
    }

    for(auto &n : sol) cout << n << " " ;


}

