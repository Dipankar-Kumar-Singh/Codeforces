#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" ;

int n,m ;
vector<vector<int>> matrix ;

int d ;

bool isPossible (int target , int &moves)
{
   
    for(int row = 0 ; row < n ; row++)
    {
        for(int col = 0 ; col < m ; col++)
        {   
            int hight = matrix[row][col] ;

            int dif = abs(target - hight ) ;

            if(dif%d != 0 ) {moves = -1 ; return 0 ;}

            moves += dif/d ;
        }
    }

   return 1 ;
}



void solution1()
{
    cin >> n >> m >> d ;
    matrix.clear() ;
    matrix.resize(n,vector<int> (m,0)) ;

    int l = 0 , r  = 1e15 ;

     for(int row = 0 ; row < n ; row++)
        for(int col = 0 ; col < m ; col++)
             cin >> matrix[row][col] ;

    int ans = INF ;
        
    for(int h =0 ; h <= 1e4 ; h++)
    {   
          int moves = 0 ;
          if(isPossible(h,moves))  ans = min(moves,ans) ;
    }

    if(ans == INF) { cout << -1 ; return  ; }

    cout << ans ;

}

signed main()
{
    FAST 

    // BETTER SOL THAN MINE [ SOL1]

    cin >> n >> m >> d ; 

    int total = m * n ;  int ans {} ;

    vector<int> v(total) ;
    for(int &x :  v ) cin >> x ;   sort(all(v)) ;

    int mid = v[total/2] ;

    for(auto &x : v)
    {
        ans += abs(x-mid)/d ;
        if((x-mid)%d != 0) { cout << -1  ; exit(0) ;}
    }

    cout << ans ;


}

