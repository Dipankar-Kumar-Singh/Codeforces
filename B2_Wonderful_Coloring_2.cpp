#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
#define pb push_back
#define mp make_pair

 //            < -- L - O - O - P - S -- >
#define f(x,v) for(auto &x:v)
#define fl(a,b) for (ll i = a; i <= b; i++)
#define cfl(a,b,i) for (ll i = a; i <= b; i++)  

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

#define st(v) sort(all(v)) ;
#define sum(x) accumulate(all(x),0) 
#define index(x,v)  find(all(v),x) - v.begin() 
#define take_vector(size,vector_name,type)  vector<type> vector_name(size) ;  fl(0,size-1){ cin >> vector_name[i] ;} 
#define make_set(from,set_name,type) set<type> set_name; f(x,from){ set_name.insert(x);}
#define frequency_maper(from,map_name,type) map<type,ll> map_name ; f(x,from){ map_name[x]++ ;}


#define pi std::numbers::pi
#define bit bitset<50> 
#define print(x) for(auto &rand : x){ cout << rand << " " ;} cout << "\n" ;
#define print_map(map_name) f(elements,map_name){ cout << elements.first << " --> " << elements.second <<"\n" ; } cout << "\n" ;

// find if a given value is present in a container. Container version. Runs in log(n) for set and map
#define present(container,key) ((container).find(key) != (container).end())

//find version works for all containers. This is present in std namespace.
#define cpresent(container,key) (find(all(container),key) != (container).end())

//             <--- M - A - T - H - S --->
bool isprime(ll n){for(ll i=2;i*i<=n;++i){if(n%i==0){return false;}}return true;}
ll factorial(ll n){return (n==1 || n==0) ? 1:n*factorial(n-1);}
ll power(ll a, ll b){ll res=1;while(b>0){if(b&1){res=(res*a)%MOD;}a=(a*a)%MOD;b =b>>1;}return (res)%MOD;}

bool comp (vector<int> v1 , vi v2 ){ return v1.size()<v2.size() ;}

// struct cmpByStringLength {
//     bool operator()(const std::vi& a, const std::vi& b) const {
//         return a.size() < b.size();
//     }
// };

void solve(vi &v, vi &op , ll &k , ll&n )
{   
    map<int,vector<int> > m ;
    fl(0,k){m[k] ;}

    f(x,v)
    {   
        bool ins = false ;
        vi sz ; 
        vector<pair<int,int> > m_with_sizes;
        f(p,m){ if(p.F!=0) sz.pb(p.S.size()) ;}
        f(p,m){ if(p.F!=0){    int s = (p.S.size()) ; m_with_sizes.pb({p.F, s}) ;}}

        // [{m[1] : 2 } { m[2] : 2 } { m[3] : 2 }  ]

        vi szz = sz ;

        sort(all(sz)) ;
        cout << "\nORG    --- >  " ; print(szz) ;
        cout << "\nSorted --- >  " ; print(sz) ;
        
        fl(0,sz.size()-1){ sz[i] = index(sz[i],szz)+1 ;}
        cout << "\n@@MAP  --- >  " ; print(sz) ;


        f(k,sz)
        {
           if(!cpresent(m[k],x)) { m[k].pb(x) ; ins = true ; break ;}
        }

        if(!ins){(m[0]).pb(x) ;}
        
    }

    f(x,m){ cout << "For m[ " << x.F << " ]    =   " ;  print(x.S) ;} cout << endl << "_________________\n" ;


}




int main()
{
    FAST 
    t_case
    {
        ll n , k ; cin >> n >> k ;
        take_vector(n,v,int) ;
        vi output_vector(n,0) ;

        solve(v,output_vector,k,n) ;

     }
}

