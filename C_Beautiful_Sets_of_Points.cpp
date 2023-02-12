#include <bits/stdc++.h>
using namespace std;

#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define nl "\n" ;


signed main()
{
    FAST 
    int n , m ; 
    cin >> n >> m ;
    int  a = min(m,n) , b = 0 ;
    cout << min(m,n) + 1 << nl ;
    if(m > n) swap(a,b) ;

    if(n>=m)
    for(int i = 0 ; i <= min(n,m) ; i++)
    {
        cout << a << " " <<  b  << nl;
        a-- ; b++; 
    }

    else 
    {

        for(int i = 0 ; i <= min(n,m) ; i++)
        {
            cout << a << " " <<  b << nl ;
            a++ ; b--; 
        }

    }
    


}

