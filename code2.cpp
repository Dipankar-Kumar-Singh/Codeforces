#include <bits/stdc++.h>
using namespace std;
#define nl "\n"


const int N = 1e7 ;
vector<int> lp(N + 1);
vector<int> pr;

void preCompute()
{
    // Time : O ( n )  -----> Linear Sieve  
    // CP-Algorithm : https://cp-algorithms.com/algebra/prime-sieve-linear.html

    for (int i = 2; i <= N; ++i)
    {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= N; ++j){
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) break;
        }
    }
}

int main()
{
    // preCompute() ;
    // cout << pr.size() << endl ;

    preCompute() ;
   
    int num = 75 ;

    while(num > 1)
    {
        cout << num <<  "   " ;
        cout << "Lp " << lp[num] << nl ;

        num /= lp[num] ;
    }
}