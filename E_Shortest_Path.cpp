#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

vector<vector<int>> graph ;
vector<int> vis ;
vector<int> dis ;
vector<int> parent ;
map<tuple<int,int,int>,int> isBad ;

// vector<int> generatePath(int source , int destination)
// {

// }

void dijkstra(int source)
{
    dis[source] = 0 ;
    parent[source] = -1 ;
    set<pair<int,int>> s ;

    s.insert({0,source}) ;

    while(!s.empty())
    {
        auto [curr_dis,node] = *s.begin() ;
        s.erase(s.begin()) ;

        if(vis[node]) continue ;
        vis[node] = 1 ;

        for(auto child : graph[node])
        {
   
            if(isBad[{parent[node],node,child}]) continue;

            if(dis[child] > dis[node] + 1)
            {
                dis[child] = dis[node] +  1 ;
                s.insert({dis[child],child}) ;
                parent[child] = node ;
            }
        }
    }
}


void solve()
{
    int n , m , k ; 
    cin >> n >> m >>  k ;

    graph = vector<vector<int>> (n+10) ; 
    vis = vector<int> (n+10) ;
    parent = vector<int> (n+10,-1) ;
    dis = vector<int>(n+10,LONG_LONG_MAX) ;

    for(int i = 0 ; i < m ; i++) 
    {
        int x , y ; 
        cin >> x >> y ;
        graph[x].push_back(y) ;
        graph[y].push_back(x) ;
    }

    for(int i = 0 ; i < k ; i++)
    {
        int x , y , z ; cin >> x >> y >> z ;
        isBad[{x,y,z}]++ ;
    }

    dijkstra(1) ;

    if(parent[n]==-1)
    {
        cout << -1 << nl;
        return ;
    } 

    else 
    {
        int source = 1 ;
        auto curNode = n ;
        vector<int> path ;
        while (curNode != source)
        {
            path.push_back(curNode) ;
            curNode =parent[curNode] ;
            // if(curNode==-1) break;
        }
        path.push_back(curNode) ;

        cout << dis[n] << nl ;
        reverse(all(path)) ;
        for(auto node : path) cout << node << ' ';
    }



}
signed main(){   FAST   solve() ;  }



