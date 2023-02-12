#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
int _case = 1 ;

int const N = 1e5 + 1e3 ;

vector<vector<int>> g(N) ;
vector<int> value(N) ;  
vector<int> up(N) , down(N) ;


void dfs(int node , int parent)
{
	for(int &child : g[node]) 
	{
		if(child == parent) continue ;
		dfs(child , node) ;
		
		up[node] = max(up[node] , up[child]) ;
		down[node] = max(down[node] , down[child]) ;
		
	}
	
	value[node] += up[node] - down[node] ;
	
	if(value[node] < 0 ) up[node] += abs(value[node]) ;
	else if(value[node] > 0) down[node] += abs(value[node]) ;
}

void solve()

{
   int n;   cin >> n;
   
   for(int i = 0 ; i < n - 1 ;i++) 
   {
   		int x , y ; cin >> x >> y ;
   		g[x].push_back(y) ;
   		g[y].push_back(x) ;
   }
   
   	for(int i = 1 ; i <= n ;i++) cin >> value[i] ;  
   	dfs(1,-1) ;
  
	cout << up[1] + down[1] ;
   
}
signed main(){   FAST  solve() ;  }



