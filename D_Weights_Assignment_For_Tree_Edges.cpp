#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long

const ll INF = numeric_limits<long long>::max();
   
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()

const int N = 1e5 + 10 ;
int w[N] ;
int dis[N] ;

void clear_vecs(){

    memset(w,0,size(w)) ;
    memset(dis,0,size(dis)) ;

}


signed main()
{
    FAST 

    t_case
    {
        clear_vecs() ;
        int n ; cin >> n ;
        
        vector<int> par(n,0) ;   for(auto &x:par){cin >> x ;}
        vector<int> permutation(n,0) ; for(auto &x:permutation) {cin >> x ;}

        int root = 0 ;

        for(int i = 0 ; i < n ;i++){

            int v = par[i] ;
            int u = i + 1 ;

            if(v==u){ root = v ; continue ;}
        }


        bool possible = 1 ;
        vector<bool> seen (n+1,0) ;
        vector<int> weight (n+1,0) ;
        
        for(int i = 0 ; i < n ; i++){

            int child = permutation[i]   ;
            seen[child] = 1 ;
            int parent = par[child-1] ;
            if(!seen[parent]){possible = 0 ; break ;}

            dis[child] =  i ;
            weight[child] =  dis[child]  - dis[parent] ;
            

        }

        if(!possible) 
        {   
            cout << -1 << "\n" ; continue;
        }


        for(int i = 1 ; i <= n; i++){
            cout << weight[i] << " " ;
        }
        
        cout << "\n" ;


                         
                                        
                                       
    }
}

