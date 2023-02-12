#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()


signed main()
{
    FAST 
    t_case
    {
        
       

        vector<int> v(3) ; 
        for(auto &x : v ) cin >> x ;

        sort(all(v)) ;

        int pos = 0 ;

        int a=v.front() , c = v.back() , b = v[1] ;

        if(a+b == c) pos = 1 ;

        else if(a == b or b == c )
        {
            if(a==b){
                if(c%2==0)  pos = 1 ;
            }

            else if(b==c){
                if(a%2==0) pos = 1 ;
            }
        }

        if(pos) cout << "YES\n" ; 
        else cout << "NO\n" ;








        

        
                                  
                                        
                                       
    }
}

