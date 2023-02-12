#include <bits/stdc++.h>
using namespace std;



int main(){

    int l = -1 , r = 10 ;

    vector<bool> v = {1 , 0 , 0 , 0 ,0 ,0 ,0  , 0 , 0 , 0 } ;

    // cout << v.size() << "\n" ;

    int ans = 0 ;


    while (r-l>1)
    {
        int m = (l + r )/2 ;
        
        if(v[m]){ 
            ans = m ;
            l = m ;
        }

        else 
        {
            r = m ;
        }

    }


    cout << l << "\n" ;

    cout << "ans = " << ans ;
    


}