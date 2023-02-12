#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()




int solve(int n , vector<int> &v){


        int a = v[0] ;  // even indexed

        for(int i = 0 ; i < n ; i+= 2)
        {
            a = gcd(v[i],a) ;
        }

        int c1 = 1 ;

        for(int i = 0 ; i < n ; i+=2){
        
            c1 = c1 and (v[i]%a==0) ;
        }

        for(int i = 1 ; i < n ; i+=2){

            c1 = c1 and (v[i]%a!=0) ;
        }

        if(c1) 
        {
            return a  ;
        }
    



        int c2 = 1 ;
        int b = v[1] ;  // odd indexed

        for(int i = 1 ; i < n ; i+= 2)
        {
            b = gcd(v[i],b) ;
        }


        for(int i = 0 ; i < n ; i+=2){

            c2 = c2 and (v[i]%b!=0) ;
        }

        for(int i = 1 ; i < n ; i+=2){
        
            c2 = c2 and (v[i]%b==0) ;
        }

        if(c2){
            return b  ;
        }
    

    return 0  ;

}


signed main()
{
    FAST 
    t_case
    {
        int n ; cin >> n ;
        vector<int> v(n) ; 
        for(int &x : v ) cin >> x ;


        cout << solve(n,v) << "\n" ;

        cerr << "\n\n";
                             
                                       
    }
}

