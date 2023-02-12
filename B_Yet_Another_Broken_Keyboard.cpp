#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()


void dp_solution()
{
    int n ; cin >> n;
    int k ; cin >> k ;

    vector<bool> typeable ( 26 ) ;
    string s ; cin >> s; 
    int ans = 0 ;

    for(int i = 0 ; i < k ; i++)
    {
        char x;
        cin >> x;
        typeable[x - 'a'] = 1 ;
    }

    vector<bool> v (n) ;
 
    for(int i = 0; i < n ; i++)
        v[i] = typeable[s[i]-'a'] ;

    vector<int> f(n + 10);

    for(int i = 0 ; i < n ; i++)
    {
        if (v[i] == 0)
            f[i + 1] = 0 ;
        else
            f[i + 1] = f[i] + 1;
    }

    cout << accumulate(begin(f),end(f),0LL) << endl ;
}

void maths_solution()
{
    int n ; cin >> n;
    int k ; cin >> k ;

    vector<bool> typeable ( 26 ) ;
    string s ; cin >> s; 
    int ans = 0 ;

    for(int i = 0 ; i < k ; i++)
    {
        char x;
        cin >> x;
        typeable[x - 'a'] = 1 ;
    }

    vector<bool> v (n) ;
 
    for(int i = 0; i < n ; i++)
        v[i] = typeable[s[i]-'a'] ;


    for(int i = 0 ; i < n ; i++)
    {
        if(!v[i]) continue;
        int start = i ;
        int end = i ;
        for(int j = i ; j < n ; j++)
        {
            i = j ;
            if( v[j] == 0) break;
            end = j ;
        }

        int n = end - start + 1 ;
        ans +=  ((n+1)*n)/2 ;

    }

    cout << ans << endl ;
}

signed main()
{
    FAST 
    // maths_solution();
    dp_solution();
}
