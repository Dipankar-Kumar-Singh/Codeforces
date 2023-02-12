#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()


void computeLPSArray(string &pat, int M, int* lps);

int KMPSearch(string &pat, string &txt)
{
	int M = pat.size(); 
	int N = txt.size();
	int lps[M];

	computeLPSArray(pat, M, lps);

	int i {}; 
	int j {}; 

	while (i < N) 
    {
		if (pat[j] == txt[i]) 
        {
			j++;
			i++;
		}

		if (j == M) 
        {
            return i-j ;
			j = lps[j - 1];
		}

		
		else if (i < N and pat[j] != txt[i]) 
        {
			
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}

    return -1 ;
}


void computeLPSArray(string &pat, int M, int* lps)
{
	
	int len {} ;

	lps[0] = 0; 

	int i { 1 };

	while (i < M) 
    {
		if (pat[i] == pat[len]) 
        {
			len++;

			lps[i] = len;

			i++;
		}


		else 
		{

			if (len != 0) 
            {
				len = lps[len - 1];
			}

			else 
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

// Driver program to test above function
int main()
{
	char txt[] = "ABABDABACDABABCABAB";
	char pat[] = "ABABCABAB";
	KMPSearch(pat, txt);
	return 0;
}




signed main()
{
    FAST 
    t_case
    {
        
        
                                  
                                        
                                       
    }
}

