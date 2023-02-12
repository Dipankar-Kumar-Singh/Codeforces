#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

void solve__2(int a , int b)
{
    auto B = bitset<64>(b) ;

    int last = 0 ;
    for(int i = 0 ; i < B.size() ; i++)   
        if(B[i]) last = i ;
    
    auto ans = B ;

    if (__bit_floor(a) == __bit_floor(b))
    {

        auto A = bitset<64>(a);
        B = bitset<64>(b);

        int last1 = 0;
        for (int i = 0; i < 64; i++)   if (B[i]) last1 = i;

        int st = 0;

        for (int i = last1; i >= 0; i--)
            if ((A[i] == B[i])) st = i;  else break;

        st--;
        
        auto ANS = bitset<64>(0);
        for (int i = 0; i <= st; i++) ANS[i] = 1;
        cout << ANS.to_ullong();
        return;
    }

    for (int i = 0; i < last; i++) B[i] = 1;
    cout << B.to_ullong();
}

signed main()
{
    FAST  
    int a , b ; cin>>  a >> b ;
    if(a==b){ cout << 0 ; return 0 ;}
    solve__2(a,b) ;
}

