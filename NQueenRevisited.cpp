#include<bits/stdc++.h>
using namespace std ;

vector<int> queen ;
int n = 8 ;

bool check(int level, int col)
{
    for (int i = 0; i < level; i++)
    {
        int queenCol = queen[i];
        int queenRow = i;

        if ((col == queenCol) or (abs(level - queenRow) == abs(col - queenCol)))
        {
            return false;
        }

        if(abs(level-queenRow) + abs(col-queenCol) == 3) return false ;
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

    for(int c = 0 ; c < n ; c++)
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
    cin >> n ;
    queen = vector<int>(n,-1) ;
    cout << solve(0) << endl ;


}