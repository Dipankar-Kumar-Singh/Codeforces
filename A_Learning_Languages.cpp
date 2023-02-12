#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

int n , m ; 
int store = 200 ;
set<int> langs;
set<int> g[302] ;

set<int> nodeList ;

void solve()
{
   int  k ; cin >> k ;

   if(k==0)
   {
       nodeList.insert(store++) ;
   }

   else
   {
       vector<int> nodes ; 
       for(int i = 0 ; i < k ; i++)
       {
           int x ; cin >> x ;
           nodes.push_back(x) ;
           nodeList.insert(x) ;
           langs.insert(x) ;
       }


       for(int i = 0 ; i < k ; i++)
       {
           if(i+1<k)
           for(int j = i + 1 ; j <k ; j++)
           {
               int x = nodes[i] ;
               int y = nodes[j] ;

               g[x].insert(y) ;
               g[y].insert(x) ;
           }
       }
   }
}

vector<int> vis(410) ;

void dfs(int node)
{
    if(vis[node])return ;
    vis[node] = 1 ;

    for(auto child : g[node]) 
    {
        dfs(child) ;
    }
}

signed main()
{   FAST  

    cin >> n >> m ;

    for(int i = 0 ; i < n ;i++)
    {
       solve() ;
    }

    int cc = 0 ;

    for(auto node : nodeList)
    {
        if(!vis[node])
        {
            dfs(node) ;
            cc++ ;
        }
    }

    int edges_requied = cc - 1 ;
    int new_Needed = ( store - 200)  ;

    cout << max(edges_requied,new_Needed) << nl ;


}

