#include <bits/stdc++.h>
using namespace std;
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  


// class Solution {
// public:
//   bool checkmap(string s)
//   {
//     unordered_map<char,int>m;
//     for(int i=0;i<s.size();i++)
//       m[s[i]]++;
    
//     for(auto it:m)
//     {
//       if(it.second>=2)
//         return false;
//     }
//     return true;
//   }
  
 
//     void solve(int i,string s,vector<string>arr,int &maxi)
//     {
//       if(i==arr.size())
//       {
//         if(maxi<s.size())
//           maxi=s.size();
//         return;
//       }

//       for(int j=i;j<arr.size();j++)
//       {
//         if(checkmap(s+arr[j]))//y error here?
//         {
//           s+=arr[j];
//           solve(j+1,s,arr,maxi);
//           s-=arr[j];
//         }
//       }
//     }  
  
  
//     int maxLength(vector<string>& arr)
//     {
//         string s="";
//       int maxi=INT_MIN;
//       solve(0,s,arr,maxi);
//       return maxi;
//     }
// };


string string_trim(string &org , string &s)
{
    // if confirmed .. ki stirng present hai [to delete]

    int toDelete = s.size() ;
    for(int j = org.size() - 1 ; ; j--)
    {
        org.pop_back() ;
        toDelete-- ;
        if(toDelete==0) break;
    }

    return org ;
}

int main()
{

    string s1 = "hlosg" ;
    string s2 = "sgsgg" ;
    s1 += s2 ;

    string_trim(s1,s2) ;
    cout << s1 << nl ;

}