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


vector<pair<int,int>> arr ;
// bool vis[111] ;

vector<bool> vis(111,0) ;
int strix = 1 ;

void dfs(int node)
{

 
    if(vis[node]) return ; 

    vis[node] = true ;

    int a = arr[node].first , b = arr[node].second ; 


    for(int i = 1 ; i <= arr.size() -1  ; i++){

        int x = arr[i].first , y = arr[i].second ;

        // if(arr[i].first == arr[i].second == 0 ) continue ;

        if     (    a > x      and      a < y )
            dfs(i) ;

        else if(    b > x      and      b < y  )
            dfs(i) ;
    }

}

signed main()
{
    FAST 
    // for(auto &x:vis) x = 0 ;
    arr.push_back({0,0});
    
    t_case
    {
        int Query , A , B ; cin >> Query >> A >> B ;

        if(Query==1){  arr.push_back({A,B});  strix++ ;}
        // 1 1️⃣ Based Indexing ....... 1️⃣🔥😁

        else
        {   
            for(int i = 0 ; i < vis.size() ; i++) vis[i] = 0 ;

            dfs(A) ;
            cout << (vis[B]?"YES\n":"NO\n") ;
        }
    }

}

