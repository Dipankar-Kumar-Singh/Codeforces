#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int n , m ; 
    cout << " enter the number of items : " ; cin >> n ;
    cout << "enter total weight  : " ; cin >> m ;

    vector<tuple< float , int , int >> v ;

    for(int i = 0 ; i < n ; i++)
    {
        int w , val ;
        cout << "enter wt of items  :  " ;         cin >> w ;
        cout << "\enter vlaue of items  :  " ;        cin >> val ; 

        float profitRatio = val/(float)w ;
        v.push_back({profitRatio,w,val}) ;
    }

    cout << endl ;

    sort(begin(v),end(v),greater<>()) ;
    float sum = 0 ;

    int itrationCounter = 0 ;

    for(auto [ profitRatio , wt , val] : v)
    {
        cout << "\nProfit after " << ++itrationCounter << " Itration is  = " ;
        if(wt <= m)
        {
            sum += val ;
            m -= wt ;
            cout << sum << endl ;
        }

        else 
        {
            float f = m/(float)wt  ;
            sum += f*val ;
            cout << sum << endl ;
            break;
        }
    }

    cout << "\n\n Total Profit = " << sum << endl ;
    return 0 ;
}