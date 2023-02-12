#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int total ; cin >> total ;  for(test = 1 ; test <=  total ; test++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  
#define print(ans) cout << "Case #" << test << ": " << ans << "\n" ;


int const INF  = 1e18 ;
int test = 0 ;


const int N = 1e5;
vector<int> lp(N+1);
vector<int> pr;
void calculate()
{
    for (int i = 2; i <= N; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
        {
            lp[i * pr[j]] = pr[j];
        }
    }
}

vector<long long> fac(long long n) {
    vector<long long> factorization;
    for (long long d : pr) {
        if (d * d > n)
            break;
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

map<int,int> requried(int nm)
{
    auto factor = fac(nm) ;
    map<int,int> req ;

    for(auto f : factor)
    {
        req[f]++ ;
    }

    return req ;
}


long long power(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve()
{
    int ans = 0 ; 
    int a , b , c , d ; 
    cin >> a >> b >> c >> d  ;

    int AB = a*b ;
    map<int,int> req = requried(AB) ;

    auto factors = fac(AB) ;

    int currA = 1 ;
    int currB = AB ;

    for(int i = 0 ; i < factors.size() ; i++)
    {   
        currA *= factors[i] ;

        if(currA > a and currA <= c)
        {
            auto RQ = req;
            auto RQ2 = requried(currA);

            int minNum = 1;

            for (auto [val, fr] : RQ)
            {
                if (RQ2[val] > 0)
                {
                    RQ[val] -= RQ2[val];
                    RQ[val] = max(RQ[val], 0LL);
                }

                if (RQ[val] > 0)
                {
                    minNum *= power(val, RQ[val]);
                }
            }

            int t = minNum;
            
            if(minNum < b) minNum = minNum * (b/minNum) ;

            for (int y = minNum; y <= d; y += t)
            {
                int XY = currA * y;
                if (XY % AB == 0 and y > b and y <= d)
                {
                    cout << currA << " " << y << nl;
                    return;
                }
            }
        }
    }

    cout << -1 << " " << -1 << nl ;
    return ;
    
}

signed main(){  FAST   calculate() ;  TestCases    solve() ; }