#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl endl


int ask(int a, int b)
{
    cout << "? "<< a << " " << b << endl ;
    int x ; cin>> x ;
    return x ;
}

void print(int len)
{
    cout << "! " << len << endl;
}

void solve()
{
    for(int i = 2 ; i <= 25 ; i++)
    {
        int x = ask(1,i) ;
        int y = ask(i,1) ;

        if(x == -1 or y == -1) 
        {
            // I --> it is one more than N .. thus ..  ===> i -  1  <==== is the N for sure ...
            print(i -  1) ;
            return ;
        }

        if(x != y)
        {
            print(x+y) ;
            return ;
        }
    }
}
signed main(){    solve() ;  }



