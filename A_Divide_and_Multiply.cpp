#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
const ll INF = numeric_limits<long long>::max();     
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()


ll power(ll a, ll b){ll res=1;while(b>0){if(b&1){res=(res*a);}a=(a*a);b =b>>1;}return (res);}



signed main()
{
    FAST 
    t_case
    {  

        int n ; cin >> n ; 
       
        int k = 0;
        vector<int> v(n,0 ) ; 
        for(auto &x : v)
        { 
            cin >> x ; 
            while (x%2==0)
            {
                x/=2 ; k++ ;
            }
        }; 

        sort(all(v)) ; reverse(all(v)) ;

        v[0] = v[0]*power(2,k) ;


        int ans = accumulate(all(v),0LL);

        cout << ans << "\n" ; 
        
    }
}

