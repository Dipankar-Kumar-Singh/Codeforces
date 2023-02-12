#include <bits/stdc++.h>
using namespace std;

#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

const int N = 2e5 + 10 ;
int h[N+100][33] ;
vector<bitset<32>> v ;

signed main()
{
    FAST 

    memset(h,0,sizeof(h)) ;

    for(int i = 0 ; i < N ; i++)
    {
        auto x = bitset<32>(i) ;
        v.push_back(x) ;
    }

    for(int BIT = 0 ; BIT < 32 ; BIT++)
    {   
        for(int NUM = 1 ; NUM <= N ; NUM++)
        {  
            h[NUM][BIT] = v[NUM][BIT]  +  h[NUM-1][BIT] ;
        }    
    }

    t_case
    {
        int a , b ; 
        cin >> a >> b ;
        int m = 0 ;

        int nums_with_one = 0 ;

        for(int i = 0 ; i < 32 ; i++)
        {
            int dif = h[b][i] - h[a-1][i] ;
            nums_with_one = max(nums_with_one , dif ) ;
        }

        int total_number_between_a_and_b = b - a + 1;
        int to_remove = total_number_between_a_and_b - nums_with_one ;
        cout << to_remove << "\n" ;
                              
    }
}

