#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 10001
#define INF (1<<29)

int main()
{
    int Tc,N;
    string s;
    cin >> Tc;
    while(Tc--)
    {
        cin >> N >> s;
        bool b[2][MAX] = {{}};
        for(int i = 0 ; i <= N ; i++)
        {
            if(i != 0 && s[2*i-1] == 'Y') b[0][i] = 1;
            if(i != N && s[2*i] == 'Y') b[0][i] = 1;
            if(i != 0 && s[2*i-1+2*N] == 'Y') b[1][i] = 1;
            if(i != N && s[2*i+2*N] == 'Y') b[1][i] = 1;
        }
        
        auto solve = [=]()
            {
                vector<vector<int>> dp(3, vector<int>(MAX, INF));
                dp[0][0] = 0; dp[1][0] = 1; dp[2][0] = 2;
		if(b[0][0] == 1 && b[1][0] == 1)
		{
		    dp[0][0] = 3;
		    dp[1][0] = 2;
		    dp[2][0] = 2;
		}
		if(b[0][0] == 1 && b[1][0] == 0)
		{
		    dp[0][0] = 1;
		    dp[1][0] = 1;
		    dp[2][0] = 2;
		}
		if(b[0][0] == 0 && b[1][0] == 1)
		{
		    dp[0][0] = 3;
		    dp[1][0] = 2;
		    dp[2][0] = 2;
		}
		if(b[0][0] == 0 && b[1][0] == 0)
		{
		    dp[0][0] = 0;
		    dp[1][0] = 1;
		    dp[2][0] = 2;
		}
		    
                for(int i = 1 ; i <= N ; i++)
                {
                    if(b[0][i] == 1 && b[1][i] == 1)
                    {
                        dp[0][i] = min(dp[0][i],dp[0][i-1]+4);
                        dp[0][i] = min(dp[0][i],dp[1][i-1]+3);
                        dp[0][i] = min(dp[0][i],dp[2][i-1]+3);
                        dp[1][i] = min(dp[1][i],dp[0][i-1]+3);
                        dp[1][i] = min(dp[1][i],dp[1][i-1]+3);
                        dp[1][i] = min(dp[1][i],dp[2][i-1]+3);
                        dp[2][i] = min(dp[2][i],dp[0][i-1]+3);
                        dp[2][i] = min(dp[2][i],dp[1][i-1]+3);
                        dp[2][i] = min(dp[2][i],dp[2][i-1]+4);
                    }
                    if(b[0][i] == 1 && b[1][i] == 0)
                    {
                        dp[0][i] = min(dp[0][i],dp[0][i-1]+2);
                        dp[0][i] = min(dp[0][i],dp[1][i-1]+2);
                        dp[0][i] = min(dp[0][i],dp[2][i-1]+3);
                        dp[1][i] = min(dp[1][i],dp[0][i-1]+2);
                        dp[1][i] = min(dp[1][i],dp[1][i-1]+2);
                        dp[1][i] = min(dp[1][i],dp[2][i-1]+3);
                        dp[2][i] = min(dp[2][i],dp[0][i-1]+3);
                        dp[2][i] = min(dp[2][i],dp[1][i-1]+3);
                        dp[2][i] = min(dp[2][i],dp[2][i-1]+4);
                    }
                    if(b[0][i] == 0 && b[1][i] == 1)
                    {
                        dp[0][i] = min(dp[0][i],dp[0][i-1]+4);
                        dp[0][i] = min(dp[0][i],dp[1][i-1]+3);
                        dp[0][i] = min(dp[0][i],dp[2][i-1]+3);
                        dp[1][i] = min(dp[1][i],dp[0][i-1]+3);
                        dp[1][i] = min(dp[1][i],dp[1][i-1]+2);
                        dp[1][i] = min(dp[1][i],dp[2][i-1]+2);
                        dp[2][i] = min(dp[2][i],dp[0][i-1]+3);
                        dp[2][i] = min(dp[2][i],dp[1][i-1]+2);
                        dp[2][i] = min(dp[2][i],dp[2][i-1]+2);
                    }
                    if(b[0][i] == 0 && b[1][i] == 0)
                    {
                        dp[0][i] = min(dp[0][i],dp[0][i-1]+1);
                        dp[0][i] = min(dp[0][i],dp[1][i-1]+2);
                        dp[0][i] = min(dp[0][i],dp[2][i-1]+3);
                        dp[1][i] = min(dp[1][i],dp[0][i-1]+2);
                        dp[1][i] = min(dp[1][i],dp[1][i-1]+1);
                        dp[1][i] = min(dp[1][i],dp[2][i-1]+2);
                        dp[2][i] = min(dp[2][i],dp[0][i-1]+3);
                        dp[2][i] = min(dp[2][i],dp[1][i-1]+2);
                        dp[2][i] = min(dp[2][i],dp[2][i-1]+1);
                    }
                }
                return dp[0][N];
            };
        
        cout << solve() << endl;
    }   
    return 0;
}
