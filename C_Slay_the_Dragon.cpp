#include <bits/stdc++.h>

using namespace std;


// Debugg
// #define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
// void err(istream_iterator<string> it) {}
// template<typename T, typename... Args>
// void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << endl; err(++it, args...);}

// < ---- DATA-TYPE --->
#define int long long
#define ar array
#define ll long long
#define str string 
#define II int,int
#define CI char,int


//  <  ---- vectors ---- >
#define vi vector<int>
#define vii vector<pair<int,int>>
#define vvi vector<vector<int>>
#define VS vector<string> 



//     <---- maps ---- >
#define UM unordered_map
#define MII map<int,int>
#define MCI map<char,int>
#define MIV map<int,vector<int>>

//     < ---- set ---- >
#define US unordered_set
#define MS multiset
#define SI set<int> 
#define SC set<char>
#define SS set<string>

#define lb lower_bound
#define ub upper_bound
#define endl "\n"
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define sz(container) container.size()

 //            < -- L - O - O - P - S -- >
#define f(x,v) for(auto &x:v)
#define fl(a,b) for (ll i = a; i <= b; i++)
#define cfl(a,b,i) for (ll i = a; i <= b; i++)  
#define fo(i,n) for(ll i = 0 ; i < n ; i++)
#define ff(n) fo(i,n)
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))


#define IOS ios_base::sync_with_stdio(0); //to synchronize the input of cin and scanf
#define PI 3.1415926535897932384626
const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
#define F first
#define S second
#define t_case   int t {} ; cin >> t ; while(t--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  x.begin() , x.end()

// < ----- TOOLS ----- > 
#define st(v) sort(all(v)) ;
#define sum(x) accumulate(all(x),0) 
#define index(x,v)  find(all(v),x) - v.begin() 
#define id index
#define take_vector(size,vector_name,type)  vector<type> vector_name(size) ;  fl(0,size-1){ cin >> vector_name[i] ;} 
#define tv take_vector
#define make_set(from,set_name,type) set<type> set_name; f(x,from){ set_name.insert(x);}
#define frequency_maper(from,map_name,type) map<type,ll> map_name ; f(x,from){ map_name[x]++ ;}
#define hash_alpha_Lower(string_name,hash_name) vi hash_name(27,0) ;f(x,string_name) { hash_name[(x-'a'+1)]++; }
#define hash_alpha_Upper(string_name,hash_name) vi hash_name(27,0) ;f(x,string_name) { hash_name[(x-'A'+1)]++; }

#define pi std::numbers::pi
#define bit bitset<64> 

//  <----- Print ----- >
#define ln cout << "\n-----------------------------------\n" ;
#define nl cout << "\n" ;
#define print(x) for(auto &val : x){ cout << val << " " ;} cout << "\n" ;
#define print_map(map_name) f(elements,map_name){ cout << elements.first << " --> " << elements.second <<"\n" ; } cout << "\n" ;
#define print_2D(vector_name) f(x,vector_name){ f(y,x){ cout << y << " " ;} cout << "\n" ;}


// find if a given value is present in a container. Container version. Runs in log(n) for set and map
#define present(container,key) ((container).find(key) != (container).end())

//find version works for all containers. This is present in std namespace.
#define cpresent(container,key) (find(all(container),key) != (container).end())

//             <--- M - A - T - H - S --->
bool isprime(ll n){for(ll i=2;i*i<=n;++i){if(n%i==0){return false;}}return true;}
ll factorial(ll n){return (n==1 || n==0) ? 1:n*factorial(n-1);}
ll power_Mod(ll a, ll b){ll res=1;while(b>0){if(b&1){res=(res*a)%MOD;}a=(a*a)%MOD;b =b>>1;}return (res)%MOD;}
ll power(ll a, ll b){ll res=1;while(b>0){if(b&1){res=(res*a);}a=(a*a);b =b>>1;}return (res);}

// <----- Read / Write ---->
void read () { }
template <typename T, typename... Args>
void read (T& t, Args&... args) {	cin >> t;	read(args...);}

void write () { }
template <typename T, typename... Args>
void write (T& t, Args&... args) {	cout << t << " ";	write(args...);}

void write_error () { }
template <typename T, typename... Args>
void write_error (T& t, Args&... args) {	cerr << t << " ";	write_error(args...);}

#define RD read
#define WR write 
#define WRE write_error


template <typename T>
void prt(T& t){  cout << t << " "<< endl;}

template <typename T>
void prt(vector<T> &v) { f(x,v){cout << x << " ";} nl } ;
void prt(vii &v) { f(x,v){cout << "[" <<x.F << " " << x.S << "] "; } nl } ;
void prt(vvi &v) { f(x,v){ WR("[") ; f(y,x){ cout << y << " " ; } WR("]"); nl ;} nl ;} ;

template <typename T>
void prt(vector<set<T>> v) { f(x,v){cout << "[ " ; f(y,x){ cout << y << " " ;} cout <<   "]\n";  };}


template <typename T, typename U>
void prt(map<T,U> &m){nl f(x,m){cout << x.F << " ---> " << x.S << "\n"; } nl } ;

template <typename T>
void prt(set<T> &s) {nl f(x,s){ cout << (x) << " "; } nl ;} ; 

template <typename T>
void prt(stack<T> s){ while(!s.empty()){ cout << s.top() << " " ; s.pop();};}

template <typename U>
void ptr(queue<U> q){ while(!q.empty()){ cout << q.front() << " " ; q.pop();};}

/* -------------------------------ERROR STR----------------------------------- */

template <typename T>
void prte(T& t){ cerr << t << " "<< endl;}

template <typename T>
void prte(vector<T> &v) { f(x,v){cerr << x << " ";} cerr<<"\n" ; } ;
void prte(vii &v) { f(x,v){cerr << "[" <<x.F << " " << x.S << "] "; } cerr<<"\n" ; } ;
void prte(vvi &v) {cerr<<"\n"; f(x,v){ cerr<<"[ " ; f(y,x){ cerr << y << " " ; } WRE("]"); cerr<<"\n" ;} cerr<<"\n"  ;} ;

template <typename T, typename U>
void prte(map<T,U> &m){ cerr << "MAP :::\n" ; f(x,m){cerr << x.F << " ---> " << x.S << "\n"; }cerr << "\n" ;  } ;

template <typename T>
void prte(set<T> &s) {cerr << "[ " ;  f(x,s){ cerr << (x) << " "; } cerr << " ]" ; cerr<<"\n" ;} ;  

template <typename T>
void prte(stack<T> s){ while(!s.empty()){ cerr<< s.top() << " " ; s.pop();};}

template <typename U>
void ptre(queue<U> q){ while(!q.empty()){ cerr << q.front() << " " ; q.pop();};}


// ____________ MASTER PRINT________________________// 
// Print Supported --> Maps , Sets , Vector , Vector of Vector , Vector of pair , All premitive data types 
// !!!!!! Queue not supported yet , use ptre , ptr for Queue...
void mprt () { }
template <typename T, typename... Args>
void mprt (T& t, Args&... args) {	prt(t) ;	mprt(args...);}


/*__________________  MASTER ERROR _____________________ */
// !!!!!! queue not supported yet , use ptre , ptr for quee ...
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



// <------ Sol starts ---> 

class Dragon{
public:

    int defence = 0  ; 
    int attack = 0  ; 
    Dragon(int x, int y){
        defence = x ;
        attack = y ; 
    }


};


signed main()
{
    FAST 
    int n ; cin >> n ; tv(n,a,ll) ; st(a) ;
    int s =  accumulate(a.begin(), a.end(), 0LL);
    int m ; cin >> m ; 

    while (m--)
    {   int sm = s ;
        long long ans = (long long) 9e18;
        int coin{} ; 
        int Dragon_Defence {} ; cin >> Dragon_Defence ; 
        int Dragon_Attack {} ; cin >> Dragon_Attack  ;

        auto pos = lower_bound(all(a),Dragon_Defence) ;
        auto prv = pos ; 

        if(pos!=a.end()){
            int p = *pos ; 
            int coin = max(Dragon_Attack - (s-p), 0LL) ; 
            ans = min(ans,coin) ;
        }

        if(pos!=a.begin()){
            int p = *(--pos) ; 
            int coin  = max(Dragon_Defence - p,0LL ) ; 
            coin += max(Dragon_Attack - (s-p), 0LL) ; 
            ans = min(ans,coin) ;
        }

        cout << ans << endl ; 

    }
}

