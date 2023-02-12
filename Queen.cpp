#include<bits/stdc++.h>
using namespace std ;

vector<int> queen ;
vector<vector<int>> isFree(8,vector<int>(8)) ;
int n = 8 ;

bool check(int level, int col)
{
    if (!isFree[level][col])
        return false;

    for (int i = 0; i < level; i++)
    {
        int queenCol = queen[i];
        int queenRow = i;

        if ((col == queenCol) or (abs(level - queenRow) == abs(col - queenCol)))
        {
            return false;
        }
    }
    
    return true;
}

int solve(int level)
{
    if(level == n)
    {
        // because we Have to Place 8 Queen [ NO OTHER CHOICE LEFT ] //
        // thus we must reach level == n ; thus returning 1 as -> ture --> possible 
        return 1 ;
    }

    int ans = 0 ;

    for(int c = 0 ; c < 8 ; c++)
    {
        if(check(level,c))
        {
            // place 
            queen[level] = c ;

            // calculate

            ans += solve(level + 1) ;

            // revert back --> UNDO

            queen[level] = -1 ;

        }
    }

    return ans ;
}

int main()
{
    queen = vector<int>(8,-1) ;

    for(int i = 0 ; i < 8 ; i++)
    {
        for(int j = 0 ; j < 8 ; j++)
        {
            char c ; cin >> c ; 
            isFree[i][j] = (c == '.') ;
        }
    }

    cout << solve(0) << endl ;
}