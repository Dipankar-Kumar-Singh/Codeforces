#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
const ll MOD = 1e9 + 7;
const ll INF = numeric_limits<long long>::max();
#define F first      
#define S second     
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


signed main()
{
    FAST 

        int a , b , c , d ; 
        cin >> a >> b >> c >> d ;

        int screen_Area = a * b ;

        int vd_area = c * d ;


        double Ratio1 = ((double)a)/b , Ratio2 = ((double)c)/d ; 

        if(Ratio1 == Ratio2){ cout << 0 << "/" << screen_Area ; return 0 ;}

        int na = 0 , nb = 0 ;

        double f = (a*1.0) /c   ;   // c * f = a ;  

        if(d*f <= b){

            // cout << "😁1️⃣🌀";

            // cout << "\n  f = " << f << "\n";

            double new_Area = vd_area * (f * f) ;
            double remaning_area = screen_Area - new_Area ;


            if(remaning_area < 1 and remaning_area>0 ){

                    // ra *  x = 1 ;
                    // x = 1/ra    ;

                    double ff = 1.0/remaning_area ;

                    // dbg(ff,screen_Area) ;

                    remaning_area  =  1 ;
                    double var  = (static_cast<double>(screen_Area) * (double)ff) ;

                    // dbg(ceil(var));

                    screen_Area = ceil(var) ;

            }

            // int HCF = gcd(remaning_area,screen_Area) ;

            int HCF = gcd((int)(remaning_area*10),(int)(screen_Area*10)) ;

             if(HCF<=10) HCF = 10 ;

            cout << (int)remaning_area/(HCF/10) << "/" << (int)screen_Area/(HCF/10) ;

            // dbg(screen_Area,vd_area,new_Area,remaning_area);

            // cout << remaning_area/HCF << "/" << screen_Area/HCF ;
            // cout << remaning_area << "/" << screen_Area ;.......................

        }

        else {

            // cout << "😂2️⃣😂👍" ;

            f =  (b*1.0)/d   ;  // d * f = b ;

            // cout << "\n  f = " << f << "\n";

            double new_Area = vd_area * f * f ;
            double remaning_area = screen_Area - new_Area ;


             if(remaning_area < 1 and remaning_area>0){

                    // ra *  x = 1 ;
                    // x = 1/ra    ;

                    double ff = 1.0/remaning_area ;

                    // dbg(ff,screen_Area) ;

                    remaning_area  =  1 ;
                    double var  = (static_cast<double>(screen_Area) * (double)ff) ;

                    // dbg(ceil(var));

                    screen_Area = ceil(var) ;

            }

             int HCF = gcd((int)(remaning_area*10),(int)(screen_Area*10)) ;


            // dbg(HCF) ;

            if(HCF<=10) HCF = 10 ;

            cout << (int)remaning_area/(HCF/10) << "/" << (int)screen_Area/(HCF/10) ;

        }    
}

