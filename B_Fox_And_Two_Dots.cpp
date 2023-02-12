#include <bits/stdc++.h>
using namespace std;

#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()





/* -------------------------------ERROR STR----------------------------------- */
#define F first 
#define S second 

template <typename T>
void prte(T t){ cerr << t << " "<< endl;}

template <typename T , typename U>
void prte(pair<T,U> &p){ cerr << "(" << p.F << "," << p.S  << ") " ;}

template <typename T>
void prte(vector<T> v) { cerr << "[ " ; for(auto x:v){cerr << x << " ";} cerr<<" ] \n" ; } ;

template <typename T , typename U>
void prte(vector<pair<T,U>> v) { cerr << "[ " ; for(auto x:v){cerr << "[ " <<x.F << " " << x.S << " ] "; } cerr<<" ] \n" ; } ;

template <typename T>
void prte(vector<vector<T>> v) {cerr<<"\n";  for(auto x:v){ cerr<<"[ " ; for(auto y:x){ cerr << y << " " ; } cerr << " ]"; cerr<<"\n" ;} cerr<<"\n"  ;} ;

template <typename T, typename U>
void prte(map<T,U> m){ cerr << "MAP :::\n" ; for(auto x:m){cerr << x.F << " ---> " << x.S << "\n"; }cerr << "\n" ;  } ;

template <typename T, typename U>
void prte(unordered_map<T,U> m){ cerr << "MAP :::\n" ; for(auto x:m){cerr << x.F << " ---> " << x.S << "\n"; }cerr << "\n" ;  } ;

template <typename T>
void prte(set<T> s) {cerr << "[ " ;  for(auto x:s){ cerr << (x) << " "; } cerr << " ]" ; cerr<<"\n" ;} ;  

template <typename T>
void prte(multiset<T> s) {cerr << "[ " ;  for(auto x:s){ cerr << (x) << " "; } cerr << " ]" ; cerr<<"\n" ;} ;  

template <typename T>
void prte(stack<T> s){ cerr << "[ " ; while(!s.empty()){ cerr<< s.top() << " " ; s.pop();} cerr <<"]\n";}

template <typename U>
void ptre(queue<U> q){cerr << "[ "  ; while(!q.empty()){ cerr << q.front() << " " ; q.pop();};cerr <<"]\n";}

/*__________________  MASTER ERROR _____________________ */
void mprte () { }
template <typename T, typename... Args>
void mprte (T& t, Args&... args) {	prte(t) ;	mprte(args...);}
/* -------------------------------------------------------------------------- */
/*                                 SUPER DEBUG                                */
/* -------------------------------------------------------------------------- */
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " ; mprte(a) ; ; err(++it, args...);}
// ------------------------------------
#define dbg error
// ----------------------------------------------------------------------------------------





const int N = 1e2 ;
bool vis[N][N] ;
vector<string>  v ;
int dx[] = { 1 , -1 , 0 , 0  } ;
int dy[] = { 0 ,  0 , 1, -1 } ;
int n , m ;
bool under_limits( int i , int j){
    if(i >= n or j >= m) return 0 ;
    if(i<0 or j<0) return 0 ;
    return 1 ;   
}


void dfs(int i , int j  , int px , int py )
{
    if(!under_limits(i,j)) return ;
    char P ;
    char C = v[i][j] ;

    if(px == -1 or py == -1)  P = v[i][j] ; 
    else  P  = v[px][py] ;
    if(P!=C) return ;
    
    if(vis[i][j]==1){ cout << "Yes" ;  exit(0) ;  }
    vis[i][j] = 1 ;

    for(int k = 0 ; k < 4 ; k++)
    {   
        int x = i + dx[k] , y =  j + dy[k] ;
        if(x==px and y == py) continue ;
        dfs(x,y,i,j) ;     
    }

}

signed main()
{
    FAST 

    memset(vis,0,size(vis)) ;

    cin >> n >> m ;
    v.resize(n) ; v.clear() ;

    set<char> unique ;
    
    for(int i = 0 ; i < n ; i++){
        string s ; 
        cin >> s ;
        v[i] = s ;
    }

    for(auto a:v)
        for(auto c:a)
            unique.insert(c) ;


    for(int i = 0 ; i < n ; i++){

        for(int j = 0 ; j < m ; j++){


            if(!vis[i][j])
                {   
                    dfs(i,j,-1,-1);
                } 
        }
    }
    cout << "No" ;

}

