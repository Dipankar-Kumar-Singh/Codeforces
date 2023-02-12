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

double l = 0 , r = 1e200 + 10000000 ;

signed main()
{
    FAST 
    char c ;
    int stone = 0 ;

    vector<int> r , l ;
    
    while (cin>>c)
    {
        stone++ ; 
        if(c=='l') {   l.push_back(stone)  ; }
        else r.push_back(stone)  ; 
    }


    reverse(all(l)) ; 

    for(int &x : r) cout << x << "\n" ; 
    for(int &x : l) cout << x << "\n" ; 



}

