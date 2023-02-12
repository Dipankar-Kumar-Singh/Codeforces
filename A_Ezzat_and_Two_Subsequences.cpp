#include <bits/stdc++.h>

using namespace std;


// Debugg
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << endl; err(++it, args...);}

// < ---- DATA-TYPE --->
#define int long long
#define ar array
#define ll long long
#define str string 
#define II int,int
#define CI char,int
#define M map
#define UM unordered_map
#define ST set

//  <  ---- vectors ---- >
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define vs vector<string> 
#define vc vector<char>
#define vvi vector<vector<int>>

//     <---- maps ---- >
#define um unordered_map
#define mi map<int,int>
#define mci map<char,int>
#define miv map<int,vector<int>>

//     < ---- set ---- >
#define us unordered_set
#define ms multiset
#define si set<int> 
#define sc set<char>
#define ss set<string>

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
#define print(x) for(auto &rand : x){ cout << rand << " " ;} cout << "\n" ;
#define print_map(map_name) f(elements,map_name){ cout << elements.first << " --> " << elements.second <<"\n" ; } cout << "\n" ;
#define print_2D(vector_name) f(x,vector_name){ f(y,x){ cout << y << " " ;} cout << "\n" ;}
#define ln cout << "\n-----------------------------------\n" ;
#define nl cout << "\n" ;

// find if a given value is present in a container. Container version. Runs in log(n) for set and map
#define present(container,key) ((container).find(key) != (container).end())

//find version works for all containers. This is present in std namespace.
#define cpresent(container,key) (find(all(container),key) != (container).end())

//             <--- M - A - T - H - S --->
bool isprime(ll n){for(ll i=2;i*i<=n;++i){if(n%i==0){return false;}}return true;}
ll factorial(ll n){return (n==1 || n==0) ? 1:n*factorial(n-1);}
ll power(ll a, ll b){ll res=1;while(b>0){if(b&1){res=(res*a)%MOD;}a=(a*a)%MOD;b =b>>1;}return (res)%MOD;}

signed main()
{
    FAST 
    t_case
    {
        int n ; cin >> n ;
        tv(n,v,int) ;
        st(v) ;  cout << fixed << setprecision(10)  ;
        int x = v[n-1] ; 
        int s = sum(v) ; s = 0 ;
        for(auto &y:v){s+=y;}
        double ans =  (1.0*(s - x)/(n-1))  + x;
        cout <<  ans << endl;   
    }
}

