#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 


int digitSum(int a)
{
    int sum = 0;
    while (a > 0)
    {
        sum += (a % 10);
        a /= 10;
    }

    return sum;
}

void solve(int& __case__)
{

    int num ; cin >> num ;

    for(int i = num/2 ; i <= num ; i++)
    {
        int a = num - i ; 
        int b = i ;

        int suma = digitSum(a) ;
        int sumb = digitSum(b) ;

        if(a < 0 or b < 0) continue;

        if (abs(suma - sumb) <= 1)
        {
            cout << a << " " << b << nl;
            return;
        }
    }
    
}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}
