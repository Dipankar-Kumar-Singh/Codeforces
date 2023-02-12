#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define nl "\n" 

signed main()
{   FAST  
    int n , m ;
    cin >> n >> m;
 
    int curr = 0 ;
    int time = 0 ;
    while(m--)
    {
    	int target ; cin >> target ;
    	target-- ;
    	int d = target - curr ;
    	int t = ((d >= 0) ? d : (n-abs(d))) ;
    	time += t;
    	curr = target ;
    }
    cout << time << nl ;
}

