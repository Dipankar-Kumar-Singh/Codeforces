#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()

const int N  = 555 ;
int v[N][N] ;
int n , m , k;
int WALL = -2 ;
int EMPTY = 0 ;
int XWALL = -1;
bool vis[N][N] ;
int dx[] = {  1  ,  -1  ,  0  ,   0  } ;
int dy[] = {  0  ,   0  ,  1  ,  -1  } ;

void BFS(pair<int,int> first_point, int dis){

    queue< pair<int,int> > q ; 
    q.push(first_point) ;

    auto [fx,fy] =  first_point ;

    v[fx][fy] = dis ;

    while (!q.empty())
    {
        ++dis ;

        auto [x,y] = q.front() ;
        q.pop() ;

        for(int k = 0 ; k < 4 ; k++){
            int nx = x + dx[k] , ny = y + dy[k] ;

            if( nx < 0 || ny < 0 ||  nx >= n || ny >= m ) continue ;

            if( v[nx][ny] == EMPTY){
                q.push({nx,ny}) ;
                v[nx][ny] = dis ;
            }   
        }   
    }
}


void print(){

    for(int i  = 0 ;  i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if      ( v[i][j]  == WALL  ) cout << '#' ;
            else if ( v[i][j]  == EMPTY ) cout << '.' ;
            else                          cout << 'X' ;
        }
        
        cout << "\n" ;
    }
}

signed main()
{
    FAST 
    cin >> n >> m >> k ;

    set<pair<int,int>> emptyCells ; 

    for(int i  = 0 ;  i < n ; i++){
        for(int j = 0 ; j < m ; j++){

            char c ; cin >> c ; 
            if(c == '#')  v[i][j] = WALL ;
            else { v[i][j] = EMPTY ; emptyCells.insert({i,j});}
        }
    }

    if(k==0){    print() ;  exit(0) ;  }

    pair FirstPoint = *emptyCells.begin()  ;
    BFS( FirstPoint , 1 ) ;

    vector< pair<int,pair<int,int>> > DistanceOFCells ;

    for(int i = 0 ; i <  n ; i++){
        for(int j = 0 ; j < m ; j++){
            if( v[i][j] >= 0){
                DistanceOFCells.push_back({v[i][j],{i,j}}) ; 
            }
        }
    }

    sort(all(DistanceOFCells)) ;
    reverse(all(DistanceOFCells)) ;

    for(int i = k ; i < DistanceOFCells.size() ; i++){
        auto [val,p] = DistanceOFCells[i] ;
        auto [x,y] = p ;
        v[x][y] = EMPTY ; 
    }

    print() ;
}