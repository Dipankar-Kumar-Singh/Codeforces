#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define nl "\n" ;


int mana_for_slab(pair<int,int> slab)
{
    int slab_len = abs(slab.first - slab.second ) ;
    int mana = (slab_len*(slab_len+1))/2 ;

    return mana ;
}

void print(auto v)
{
    for(auto x : v) cout << x << " " ;
    cout << "\n" ;
}

signed main()
{
    FAST 
    t_case
    {
        
        int n ; cin >> n ;

        vector<int> t(n,-1) ; 
        for(int & x : t) cin>> x ;  

        vector<int> h(n,-1) ; 
        for(int & x : h) cin>> x ;

        pair<int,int> slab {INF,INF} ;

        int mana_req {} ;

        for(int i = n - 1 ; i >= 0 ; i--)
        {
            if( i  ==  n - 1 )
            {
                // last element .. start of the slab ;

                int time = t[i] , req = h[i] ; 
                slab.first =    time - req    ; // end
                slab.second =   time    ;    // start  --> [ end , start ] 
            }

            if(t[i] > slab.first)
            {
                slab.first = min(slab.first , t[i] - h[i] ) ;
            }

        
            if(t[i] <= slab.first)
            {
                // addding old value 
                mana_req += mana_for_slab(slab) ;

                // new slab --> not updating end , but crearing whole new slab . 
                int end = slab.first , start = slab.second ;
                slab.first =  t[i] - h[i] ;
                slab.second = t[i] ;
            }

            if(i == 0)
            {
                mana_req += mana_for_slab(slab) ; break ;
            }
   
        }

        cout << mana_req << nl ;
    
                                       
    }
}

