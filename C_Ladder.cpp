#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  

// BATTRERY DEAD HONEY SEY PEHLEY HO GAyA .... 😂😂😂✌️✌️✌️

// missing this case in test case 19

    // \                /
    //  \              /
    //   \ __________ /
    

signed main()
{
    FAST 

    int n , m ; cin >> n >> m ; 
    vector<int> a(n) ; for(auto &x : a ) cin >> x ;
    vector<int> point , up , down; 

    for(int i = 1 ; i + 1 < n ; i++)
    {
        if((a[i-1]>a[i]) and (a[i]<a[i+1])) point.push_back(i) ;  // down then up point ..
        if(a[i]<a[i-1])  down.push_back(i) ;
        if(a[i]<a[i+1]) up.push_back(i) ;
    }

    while (m--)
    {
        int l , r ; cin >> l >> r ; --l , --r ;
        auto it = upper_bound(all(point),l) ;
        if(it!=point.end() and *it<r) { cout << "No\n" ;  continue ;}
           
        auto it1 = upper_bound(all(down),l) ;
        if(it1==down.end()){ cout << "Yes\n" ; continue ; } // Non Decreacign .. Kabhi down hua hi nahi ..yes laddder

        auto it2 = upper_bound(all(up),*it1) ;
        if(it2==up.end()){ cout << "Yes\n" ; continue ;} // No increaesing ... kabhi up hua hi nahi ...yes ladder
        if((*it1<r and *it2<r)) cout << "No\n" ; // NOT A LADDER 
        else cout << "Yes\n" ;
    }
}

