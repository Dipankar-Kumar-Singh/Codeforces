#include <bits/stdc++.h>
using namespace std;


// WHAT I LEARNT --->
//   how rohit use to do 4 , 5 nested ( for loops 😂😂 ) and
//   it used to blow my mind ...... how can someone use 4,5 loops 🥶 [ LGM things]

//     finally I also learnt it's appplication -->
//         used to oprate on GRID // MATRIX 
//         to select each possible cell in it ... 
//         if(intter loop)
//             p -> 0 | take each and every cell 
//             q -> 0 |    

//             p -> i | search in limit range .... 
//             q -> j |    --> 🟥 --> (p,q) --> (i,j) --> 

//             🟦🟦🟦🟦🟦🟦🟦
//             🟦🟦🟦🟦🟦🟦🟦
//             🟦🟦🟥🟩🟩🟩🟩 -->
//             🟦🟦🟩🟩🟩🟩🟩 -->
//             🟦🟦🟩🟩🟩🟩🟩 -->  selected cells 🟩
//             🟦🟦🟩🟩🟩🟩🟩 -->
//             🟦🟦🟩🟩🟩🟩🟩 -->
//                   | |  | |  |
//                   v v  v v  v

//                   selected cells 🟩
 
        
//             for(i )
//                 for ( j)
//                     for(p = i )
//                         for(q = j)
//                             if(p==i and j == i )[ 🟥 ] continue ;
//                             do opration on selected cell ... 🟩





#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end() ;

int const N = 55 ;
bool vis[55][55];
int n , m ;

map<pair<int,int>,int> state ;

int dx[] = {1 , -1 , 0 , 0 } ;
int dy[] = {0 , 0 , 1 , -1 } ; 

int vi[N][N][4][2] ;

void dfs(int i , int j , vector<string> &v , int dir , int change){
    if( (i >= n or j>=m)  or (i<0 or j < 0) ) return ;

    if( v[i][j] == 'W'  or  vi[i][j][dir][change]) return ;

    if(change>1) return ;

    // I still don't understand it properly that why we are doing v[i][j][dir][change] /
    vi[i][j][dir][change] = vis[i][j] = 1 ;
    // 🅱️ at this cell .... is this visited with same mood [ dir same ] North S E W?] AND changed dir[ 1 time or 0]?]
    //  🚩 
    // 
    // note ... [dir][change] --> 4! X 2! --> so simple visit will not work in this case ..
    // 🔥 we will  reutrn ONLY IF cercumtance/ state was "exactly" same .... [ came from same dir , with same dir change ] 
    

    for(int t = 0 ; t < 4 ; t++)
    {   
        // 😡😡😡POINT OF MISTAKE ::: I was doing change += (dir!=t) ;
        // 😅😅😅 but it should be + not += 

        dfs(i+dx[t] , j + dy[t] , v , t , change+(dir!=t)) ;
    }
}

signed main()
{
    FAST 
    cin >> n >> m ;

    memset(vis , 0 , sizeof(vis)) ;

    vector<string> v(n) ;

    for(int i = 0 ; i < n ; i++)
        cin >> v[i] ;


    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(v[i][j]=='B')
            {
            
                memset(vis,0,sizeof(vis)) ;
                memset(vi,0,sizeof(vi) ) ;

                vis[i][j] = 1 ;

                for(int k = 0 ; k < 4 ; k++){
                    dfs(i+dx[k],j+dy[k],v,k,0) ;
                }
                
                bool check = 1 ;

                for(int p = 0 ; p < n ; p++)
                {   
                     // ---😎-- // ---😁--- // ------🚩🚩🚩🌀🌀🌀----//---🥳-- // ------ //
                    //  START P and Q from 0 not from i and j 
                    // by doing so we are just making sure ..
                    // from every black cell it is possible to reach other black cell'
                    // ----- // ------ // ---------//----- // ------ // ---------//

                    for(int q = 0 ; q < m ; q++){
                        
                        if(v[p][q]=='B'){
                                check &= vis[p][q] ;
                        }
                    }
                }
                if(!check){
                    cout << "NO" ; return 0 ;
                }
            }  
            
        }
    }


    cout << "YES" ;

}

