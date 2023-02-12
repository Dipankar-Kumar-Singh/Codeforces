#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 998244353 ;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()





/* -------------------------------ERROR STR----------------------------------- */
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




// IMPORTANT : NOTE : DO INSITIALIZE FACTS....
int const N = 1e6 + 10 ;
long long fact[N + 1];
int modulo = 998244353  ; 

long long binpow(long long val, long long deg, long long mod) {
    if (!deg) return 1 % mod;
    if (deg & 1) return binpow(val, deg - 1, mod) * val % mod;
    long long res = binpow(val ,deg >> 1, mod);
    return (res*res) % mod;
}
void initfact() {
    // IMPORTANT : NOTE : DO INSITIALIZE ....
    fact[0] = 1;
    for(int i = 1; i <= N; i++) {
        fact[i] = (fact[i-1] * i);
        fact[i] %= modulo;
    }
}
long long nCr_mod(int n, int i) {
    long long res = fact[n];
    long long div = fact[n-i] * fact[i];
    div %= modulo;  div = binpow(div, modulo - 2, modulo);
    return (res * div) % modulo;
}

vector<int> vis(5000+100) ;



signed main()
{
    FAST 
    initfact() ;


    int n , k ; cin >> n >> k ;

    int ans = 0;

    string s ; cin >> s; 

    int one_fr = count(all(s),'1') ;

    if(one_fr<k or k==0)
    {
        cout << 1 << "\n" ;
        return 0 ;
    }

    for(int i = 0 ; i < n ; i++)
    {
        if(vis[i]) continue ;

        if(s[i]== '1' )
        {
            int j = i ;
            int got_one = 0 ;
            vis[i] = 1 ;

            while (s[j]=='1')
            {
               got_one++ ;
               j++ ;

               if(j>=n) break ;
               if(got_one == k) break ;
            }

            if(got_one == k)
            {
                for(int k = i ; k  <= min(j,n-1) ; k++)
                {
                    vis[k] = 1 ;
                }

                int start  = max((i-1),0LL) ; int end = min(j + 1,n-1) ; 

                
                while(s[start] == '0')
                {
                    start-- ;

                    if(start>=0)
                        if(s[start]=='1') {start++ ; break ;}

                    if(start<=0){  start = 0 ;  break ;  }
                    if(start == 0) break ;
                    

                    cerr << "😇\n" ;
                }

                while (s[end]== '0')
                {
                   end++ ;
                   if(end<n)
                     if(s[end]=='1') {end-- ; break ;}
                   if(end==n-1) break ;
                   if(end >= n) {end = n-1 ; break ;}
                  
                }

                int rg = end - start + 1  ;

                if(rg<0) cerr << "🔥HOT eRROR\n" ;

                int zero_ct = 0 , one_ct = 0 ;

                for(int k = start ; k <= end ; k++)
                {   
                    zero_ct += (s[k]=='0') ;
                    one_ct  += (s[k]=='1') ;
                }

                if(one_ct > k ) cerr << "EROOR ONE > K🥶🥶\n" ;
                cerr << "ONE = " << one_ct << " \n" ;
                cerr << "range = "<< rg << "\n" ;
                dbg(one_ct , start , end , i ) ;
                


                int res = nCr_mod(rg,k) ;

                ans = (ans%MOD + res%MOD)%MOD ;

                cerr << "RES = " << res << "\n" ;

                cerr << "\n-------------\n" ;

                // int nt = fact[rg] ;
                // int dt = fact[0] ;

                // long long res = fact[rg];
                // long long div = fact[one_ct] * fact[zero_ct];
                // div %= modulo;  div = binpow(div, modulo - 2, modulo);
                // return (res * div) % modulo;

                // int val = (res * div) % modulo ; 



                // long long res = fact[n];
                // long long div = fact[n-i] * fact[i];
                // div %= modulo;  div = binpow(div, modulo - 2, modulo);
                // return (res * div) % modulo;

                

            }
        }

    }


    cout << ans ;

}

