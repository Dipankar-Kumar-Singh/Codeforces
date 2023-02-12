#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()

int const N = 1e5 ;
vector<int> g[N];
vector<int> deg;
vector<int> xor_sum ;
vector<int> con ;


signed main()
{
    FAST 
    int n ;  cin >> n  ;

    deg.resize(n) , xor_sum.resize(n,0) ; con.resize(n,0) ;
    int total= 0 ;

    vector<bool> vis(n,0) ;

    stack<int> s ;

    for(int  i =0 ; i < n ; i++)
    {
        cin  >>  deg[i]>>  xor_sum[i] ; 
        total += deg[i] ;

        if(deg[i] == 1){
            s.push(i) ;
        }
    }

    set<pair<int,int>> v ;

    while (!s.empty())
    {
        
        int i = s.top() ;  s.pop() ;
        if(deg[i]==0) continue;

        int sm = xor_sum[i] ;

        // deg[i] -- >  1 

        int j = sm ;
        v.insert({max(i,j) , min(i,j)}) ;

    
        deg[i]--; deg[j]-- ;

        xor_sum[j] = xor_sum[j] ^ i ;

        if(deg[j]==1) s.push(j) ;

    }
    
    cout << total/2 << "\n" ;


    for(auto &[ x , y ] : v) 
        cout << x << " " << y << "\n" ;
       
}

