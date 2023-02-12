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

vector<int> v ;
int n = 0 ;

// bool isPossible(int ans){

//     for(int i = 0 ; i < n ; i++){
//         ;
//     };

// }

signed main()
{
    FAST 

    cin >> n ;
    vector<int> input(n,0 ) ; for(auto &x : input) cin >> x ;
    v = input ;

    int real_max  =  0 ;
    for(int &x :v)  real_max = max(real_max,x) ;


    bool reached_full_hight = 0 ;

    int ans  =  0;

    t_case
    {
        int w , h ; cin >> w >> h ;
        int m =  0;

            int top1 = max(m,v[w-1]) ;

            int top2 = v[0] ;

            int top = max(top1,top2) ;

            ans = top ;

            v[0] =  v[w-1] = top  + h ;

        cout << ans << "\n" ;
                                                      
                                       
    }
}

