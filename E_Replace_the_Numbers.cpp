#include <bits/stdc++.h>
using namespace std;

// #define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()

int const N = 1e7 ;
vector<int> dsu [N] ;
vector<int> v ;


void merge(int x , int y )
{
    if(x==y) return ;  // IMP MISSING CODE --> DIDN't thought of this case

    vector<int> &a = dsu[x] , 
                &b = dsu[y] ;

    size(a) > size(b) ? swap(a,b) : (void()) ;

    for(auto &i : a) b.push_back(i) ;

    dsu[x].clear() ;
}


signed main()
{
    FAST 
    int n {} ;
    t_case
    {   
       
        int op ; cin >> op ;

        if( op == 1)
        {
            int x ; cin >> x ;
            v.push_back(x) ;
            dsu[x].push_back(n++) ; 
        }

        else if(op == 2)
        {   
            int x , y ; 
            cin >> x >> y ;
            merge(x,y) ;
        }
                           
    }

    for(int i = 0 ; i < N ; i++)
    {
        for(auto &child : dsu[i])
        {
            v[child] = i ;
        }
    }

  
    for(auto &x : v) cout << x << " " ; 
    
}

