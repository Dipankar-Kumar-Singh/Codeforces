#include <bits/stdc++.h>
using namespace std;

#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()

int main()
{
    FAST 
    t_case
    {
        int n;cin>>n ; vector<int> v(n,0) ;
        for(auto &x : v)  cin >> x ; sort(all(v)) ;
        for(int i = 1 ; i <= (int)(n/2) ; i++ ) 
            cout << v[i] << " " << v[0] << "\n" ;          
    }
}

