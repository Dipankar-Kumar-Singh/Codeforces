#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  

vector<int> odds ;

void solve()
{
    
    int n ; cin >> n ; 
    vector<int> v(n) ;


    if(n==3)
    {
        string ss = "3 2 1\n1 3 2\n3 1 2\n" ;
        cout << ss ;
        return ;
    }
    

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i ; j < n ; j++)
        {
            cout << n - j  << " " ;
        }

        for(int j = 0 ; j < i ; j++)
        {
            cout << n - j  << " " ;
        }

        cout << "\n" ;
    }

    

}

signed main()
{   FAST  



    TestCases  
    solve() ;  



}

