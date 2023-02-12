#include "bits/stdc++.h"
using namespace std;

#define double long double 
#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()

double PI = 3.141592653589793238 ;
signed main()
{
    FAST 
    double MX = 0  , MN = INF ; 
    vector<double> v ;
    t_case
    {  
        int x , y ; cin >> x >> y ;
        double res = (atan2(abs(y),abs(x))*(180/PI)) ;
        
        double xx = atan2((y),(x)) ;
        // if( xx < -1e9) xx += xx + 2*PI ;
        v.push_back(xx) ;
    
    }
    sort(all(v)) ;
    double ans  =  v.back( ) - v.front();
    for(int i = 1 ; i <  v.size() ; i++)
    {
        double dif =  v[i] - v[i-1] ;
        double remaning =  2*PI - dif  ;
        ans = min(remaning,ans) ;
    }
    cout << setprecision(10) << fixed  ;

    cout << ans*180/PI ;

}
 