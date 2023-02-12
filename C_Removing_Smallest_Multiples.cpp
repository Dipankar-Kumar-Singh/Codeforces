#include <bits/stdc++.h>
using namespace std;
#define TestCases   int total ; cin >> total ;  for(test = 1 ; test <=  total ; test++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  


int const REMOVED = 2 ;
int const TO_REMOVE = 0 ;
int const KEEP = 1 ;

int test = 0 ;
void solve()
{
    int n ; cin >> n ;

    int cost = 0 ;
    string mask ; cin >> mask ;

    vector<int> state(n+1) ;
    for(int i = 0 ; i < n; i++)
    {
        if (mask[i] == '0') ;
        else
            state[i + 1] = 1;
    }


    cerr << "MASK = " << mask << "   \n" ; 

    for(int i = 1 ; i <= n ; i++)
    {
        if(state[i]==KEEP) continue;
        if(state[i]== REMOVED) continue;

        for (int j = i; j <= n; j += i)
        {
            if(state[j] == KEEP ) break;
            if(state[j] == REMOVED) continue;

            if (state[j] == TO_REMOVE)
            {
                cerr << " i = " << i << " j = " << j << nl;
                cost += i;
                state[j] = 2;
            }
        }
    }

    cerr << "MASK = " << mask << "   " ; 
    cerr << cost << nl ;

    cout << cost << nl ;

}

signed main()
{
    FAST 
    TestCases solve();

}