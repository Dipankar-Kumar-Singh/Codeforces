#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>




int main()
{
    
    int n{} ; int k{} ; 

    cin >> n >> k ;
    if(n==1){cout << 1 ; return 0 ;}
    vector<int> v(n) ; for(auto &x:v){ cin >> x ;}
    int mx = 1e9 ;
    int s = accumulate(v.begin(),v.begin()+k,0) ;  

    mx = min(s,mx) ;
    int j  = 0 ;



    for(int i = 1 ; i <=n-k ; i++ )
    {
        
        int k1 = i-1 ; 
        int k2 = i+k-1 ;
        s -= v[k1] ;
        s += v[k2] ;
        
        // cout << "i : " << i << " \n s = " << s << "\n\n" ;

        if(s<mx){
            mx = s ; j = i ;
        }
    }

    cout << j+1 ;
    
}


