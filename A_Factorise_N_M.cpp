#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

const int N = 1e7;
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



vector<bool> is_prime(N+1, true);
void calculate1()
{
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= N; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = false;
        }
    }
}

void solve()
{
   int n;   cin >> n;

   for (auto &m : pr)
   {
       if (m == n)
           continue;
       if (!is_prime[m + n])
       {
           cout << m << nl ;
           return;
       }
   }
}
signed main(){   FAST  calculate();  calculate1();    TestCases      solve() ;  }



