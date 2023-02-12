#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e18 
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

int min_res = INF ;

void calculate(vector <int > &a , vector <int> &b)
{

    int r1 = 0 , r2 = 0 ;

    for (int i = 0; i + 1 < a.size(); i++)
    {
        for (int j = i + 1 ; j < a.size(); j++)
        {
            r1 += (a[i] + a[j]) * (a[i] + a[j]);
            if(r1>min_res) return ;
        }
    }

    for (int i = 0; i + 1 < b.size(); i++)
    {
        for (int j = i + 1; j < b.size(); j++)
        {
            r2 += (b[i] + b[j]) * (b[i] + b[j]);
            if(r2>min_res) return ;
        }
    }

    min_res = min(r1 + r2 , min_res) ;
}

void dp(int i , vector<int> a  , vector<int> b)
{
    if(i>=a.size()) return ;
    if (i == a.size() - 1)    calculate(a, b);
    dp(i+1 , a , b) ;
    swap(a[i],b[i]) ;
    if (i == a.size() - 1)  calculate(a,b) ;
    dp(i+1 , a , b) ;
}



signed main()
{
    FAST 
    t_case
    {
        min_res = INF ;
        int n ; cin >> n ;
        vector<int> a(n) ; for(int &i : a) cin>>i ; 
        vector<int> b(n) ; for(int &i : b) cin>>i ; 
        dp(0,a,b) ;
        cout << (min_res) << nl ;                                               
    }
}

