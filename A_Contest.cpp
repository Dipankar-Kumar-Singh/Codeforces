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




int get_marks(int p , int t){


    return max(      (int)(3.0*p/10 ),   (int)( p- ((p/250.0)*t) )       ) ;

} 


signed main()
{
    FAST 
    int a , b , c , d ; cin >> a >> b >> c >> d ;
    int m1 = get_marks(a,c) ; 
    int m2 = get_marks(b,d) ;


    if(m1>m2) cout << "Misha" ;
    else if(m1<m2) cout << "Vasya" ;
    else cout << "Tie" ;

    // cout << m1 << " " << m2 << "\n" ;


}

