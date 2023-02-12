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


int XORR(int a , int orr){
    return a ^ orr ;
}

int Obstical_Present(vector<int> &v, int l , int r ) {
    
    int res = 0 ;
    for(int i = l  ; i <= r ; i++){

        if(v[i]!=0) res |= v[i] ; ;
    }

    return res ;
}


void update_arr(vector<int> &v, int l , int r , int val ){

    // O(n) time 
    int orr = val ;

    // check if this segment is colliding with other seg [ previosully given]

    int Obstical =  Obstical_Present(v,l,r) ;

    if(Obstical==0){

        for(int i = l  ; i <= r ; i++){
            v[i] = val ;
        } ;
    }
    
    else {

        // ( A OR E ) = ( orr ) // E --> value to be filled in remaning block ;
        // A -> Obstical 
        
        int E = XORR(Obstical, orr) ;

        for(int i = l  ; i <= r ; i++){
           if(v[i] != 0 ) continue ;
           v[i] = val ;
        } ;

    }

    //O(1) update 
    
}

signed main()
{
    FAST 
    t_case
    {
        
        int n , m  ; cin >>  n  >>  m ; 

        vector<int> v(n,0) ;
        int l , r , orr ;

        map<int,pair<int,int>> segment_data ;
        // seg no , { val in seg , len of seg }
        
        for(int i = 0 ; i < m ; i ++){

            cin >> l >> r >> orr ;
            l-- ; r-- ;
            update_arr(v,l,r,orr) ;
        }

        for(auto x : v) cout << x << " " ; cout << "\n" ;


             
                                    
                                       
    }
}

