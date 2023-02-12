#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  
#define Google_Output(t,ans) cout << "Case #" << t << ": " << ans << "\n" ;

void solve(int Test)
{
    int l , a , b ; cin >> l >> a >> b ;

    int x = l*l ;
    int y = a*b ;

    if(x>y)
    {
        cout << "Chef\n" ;
    }

    else if(x<y)
    {
        cout << "Divyam\n" ;
    }

    else if(x==y)
    {
        cout << "Draw\n" ;
    }

}

signed main(){

    FAST 
    int Total_Test ; cin >> Total_Test ;
    for(int TEST = 1 ; TEST <=  Total_Test ; TEST++)
    {
        solve(TEST) ;
    }
}