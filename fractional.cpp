#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;


void solve()
{
    int n {} ; cin >> n;
    int capacity {} ;  cin >> capacity;

    vector<pair<int,int>> items(n) ;

    for(auto& [ weight , value ] : items ) 
    {
        cin >> weight >> value ;
    }

    sort(all(items),[&](pair<int,int>&  p1 , pair<int,int>&  p2){
        
        auto [w1 , v1] = p1 ;
        auto [w2 , v2] = p2 ;

        double worth_it_ratioA = ((1.0) * v1) / w1;
        double worth_it_ratioB = ((1.0) * v2) / w2;

        return worth_it_ratioA >= worth_it_ratioB ;
    });

    for (auto [w, v] : items)
        cout << w << " " << v << nl;

    vector<pair<int,int>> taken ; 

    vector<tuple<double , int , int>> fractional_Item  ;

    double profit = 0 ;

    for(auto& [ weight , value ] : items )
    {
        if(weight <= capacity)
        {
            taken.push_back({weight , value}) ;
            capacity -= weight ;
            profit += value ;
        }
        else 
        {
            // 100 KG ---> 30KG ///

            // 100 --> x
            // 1 -> x / 100 
            // 30 -> x/100 * 30 ;

             double max_profit = capacity * ((1.0 * value) / weight);
             capacity = 0 ;
             profit += max_profit ;
             fractional_Item.push_back({max_profit , weight , value}) ;
             
             break ; 
        }
    }

    cout << "Profit = " << profit << nl << nl;


    cout << "Full Items taken : " << nl ;
    for (auto [weight, value] : items)
        cout << "weight = " << weight << " value = " << value << nl ;

    if (!fractional_Item.empty())
    {
        cout << " Fractional Taken Item =  " << nl;
        auto last = fractional_Item.front();
        auto [profit_contribution, weight_last, value_last] = last;


        cout << " weight : " << weight_last << "   Value : " << value_last << nl ; 
        cout << "Profit taken = " << profit_contribution << nl ;
        cout << "Fraction Taken = " << (profit_contribution/value_last) << nl ;
    }

    // double = 0 ;




    // profile , weigght , capcity ;








}
signed main(){   FAST      TestCases      solve() ;  }



