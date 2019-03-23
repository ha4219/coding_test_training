#include "bj_10844.h"

using namespace std;

int dp[101][10] = { 0, };
const int mod = 1000000000;
void bj_10844() {
	int N;
	cin >> N;

	for (int i = 1;i < 10;i++) {
		dp[1][i] = 1;
	}
	for (int i = 2;i <= N;i++) {
		for (int j = 0;j < 10;j++) {
			if (j - 1 >= 0)
				dp[i][j] += dp[i - 1][j - 1];
			if (j + 1 <= 9)
				dp[i][j] += dp[i - 1][j + 1];
			dp[i][j] %= mod;
		}
	}

	long long res = 0;
	for (int i = 0;i < 10;i++)
	{
		res += dp[N][i];
	}
	res %= mod;
	cout << res << endl;
}
