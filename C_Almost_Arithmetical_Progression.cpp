#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

int LIS(vector<int> &v , int s , int q)
{
    for(int i = s  ; i < v.size() ;i++)
    {
        
    }
}

void check(vector<int> &v , int s)
{
    int n = v.size() ;
    int curr = v[s] ;
    for(int i = s+1; i < n;i++)
    {
        int q = v[i] - v[s] ;
        if(i%2==0) q = -q ;
    }

}


signed main()
{   FAST  

    int n ; cin >> n;
    vector<int> v(n) ;
    for(int i = 0 ; i < n;  i ++)
    {
        check(v,i) ;
    }

}

