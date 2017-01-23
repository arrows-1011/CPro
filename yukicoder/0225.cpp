#include <iostream>

using namespace std;

int levenshtein_distance(string& s, string& t,
			 int incost = 1, int rmcost = 1, int recost = 1)
{
    int N = s.size(), M = t.size();
    int dp[N + 1][M + 1];

    for (int i = 0; i <= N; i++) {
	dp[i][0] = i * incost;
    }
    for (int i = 0; i <= M; i++) {
	dp[0][i] = i * rmcost;
    }
    
    for (int i = 1; i <= N; i++) {
	for (int j = 1; j <= M; j++) {
	    int rcost = (s[i - 1] == t[j - 1] ? 0 : recost);
	    dp[i][j] = min(dp[i - 1][j] + incost,
			   min(dp[i][j - 1] + rmcost, dp[i - 1][j - 1] + rcost));
	}
    }
    return dp[N][M];
}

int main()
{
    int N, M;
    string S, T;
    cin >> N >> M >> S >> T;
    cout << levenshtein_distance(S, T) << endl;
    return 0;
}
