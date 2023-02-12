#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()


set<int> candles; 
int m, t, r ; 

void light_up(int w)
{
    if(t<r)
    {
        cout <<  -1  ; 
        exit(0) ;
    }

    int rem_candles = r ;

    for(auto start_time : candles)
    {
        if(w-t <= start_time  and start_time <= w-1  )
        {
            rem_candles-- ;
            // if candle's start time is between our requirement ... 
            //remaning candle to burn-- ;
        }
    }

    for(int i = w-1 ; rem_candles > 0 ; i--)
    {
        // IMP LEARNING --> i--> neagive bhi jaa raha hai.... 
        // but that is not the main priority ...
        //  Main Task -->>> To light up new candles -->>> equal to reming count ...

        if(candles.count(i))
        {
            continue ;
        }

        else 
        {
            // if not already present in the set ... this time is free [ not bussy ] .
            rem_candles-- ; 
            candles.insert(i) ;
            // because this time is free thus we can make it bussy and start new light
        }
    }
}


signed main()
{
    FAST 
  
    cin >> m >> t >> r ;

    for(int i = 0 ; i < m ; i++)
    {
        int w ; cin >> w ;
        light_up(w) ;
    }

    cout << size(candles) ;                                
}

