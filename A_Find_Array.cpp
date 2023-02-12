#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()

const int N = 1e7;
vector<bool> is_prime(N + 1, true);
void sev()
{
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= N; i++)
    {
        if (is_prime[i] && (long long)i * i <= N)
        {
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = false;
        }
    }
}

signed main()
{
    FAST 
    vector<int> primes ;
    sev() ;

    for(int i = 2 ; i <= N-1 ; i++)
    {
        if(is_prime[i]) primes.push_back(i) ;
    }
    
    t_case
    {
        
        int n ; cin >> n ;

        for(int i = 0 ; i < n ; i++)
        {
            cout << primes[i] << " " ;
        }
        cout << "\n" ;                                               
    }
}

