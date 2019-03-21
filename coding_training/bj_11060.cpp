#include "bj_11060.h"


using namespace std;

void bj_11060(){
	int N;
	int dp[1001] = { 0, };
	int input;

	cin >> N;
	dp[1] = 1;

	for (int i = 1;i <= N;i++) {
		cin >> input;
		
		if (dp[i] == 0)
			continue;

		for (int j = 1;(j <= input) && (j + i <= 1000);j++) {
			if ((dp[i + j] > dp[i] + 1) || (dp[i + j] == 0))
				dp[i + j] = dp[i] + 1;
		}
	}

	cout << dp[N] - 1 << endl;
}
