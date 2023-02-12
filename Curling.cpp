#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int total ; cin >> total ;  for(test = 1 ; test <=  total ; test++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  
#define print(x,y) cout << "Case #" << test << ": " << x <<  " " << y << "\n" ;

int const INF  = 1e18 ;
int test = 0 ;

int distance(int x , int y){
    return x*x + y*y ;
}

void solve()
{
    int ans = 0 ; 
    int rs , rh ; cin >> rs >> rh ;

    int sum_of_radius = (rs + rh) ;
    int sq_sum_radius = sum_of_radius * sum_of_radius; 

    int n ; cin >> n ;
    vector<pair<int,int>> stones ;
    // dis , color ..

    for(int i = 0 ; i < n; i++)
    {
        int x , y ; cin >> x >> y ;
        int d = distance(x,y) ;

        //  d <= (rs + rh )^2  ;

        if (d <= sq_sum_radius)
            stones.push_back( {d , 1});
    }

    int m ; cin >> m ;

    for(int i = 0 ; i < m ; i++)
    {
        int x , y ; cin >> x >> y ;
        int d = distance(x,y) ;
        if (d <= sq_sum_radius)
            stones.push_back({d , 2});
    }

    sort(all(stones)) ;

    auto [ __d , currColor ] = stones.front() ;
    int scoreA = 0  , scoreB = 0 ;

    for(auto [ dis , color ] : stones)
    {
        if(color != currColor) break ;
  
        if(currColor == 1) scoreA++ ;
        else if(currColor == 2) scoreB++ ;
    }

    print(scoreA,scoreB) ;
}

signed main(){  FAST    TestCases    solve() ; }