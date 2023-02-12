#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
const ll MOD = 1e9 + 7;
const ll INF = numeric_limits<long long>::max();
#define F first      
#define S second     
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()


signed main()
{
    FAST 
   
        
        int n ; cin >> n ; 
        vector<int> v(n,0) ; for(auto &x:v) cin >> x ;

        int j = n-1 ;

        if(n==1){ cout << v[0] ; return 0 ;}

        int cur = 0 ;

        int eng = v[0] ;

        int power = 0;

        while (j!=0)
        {
            int now = v[cur] - v[cur+1] ;

            power += (now) ; 
            if(power<0)
                {         
                    eng += abs(power) ;
                    power = 0 ;

                }
           
            cur++ ; j-- ;
        }

        cout << eng ;
        

                                  
                                        
                                       
    
}

