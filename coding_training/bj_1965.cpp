#include "bj_1965.h"

using namespace std;

void bj_1965() {
	int n;
	int max = 0;
	int arr[1001] = { 0, };
	int dp[1001] = { 0, };
	cin >> n;

	for (int i = 1;i <= n;i++) {
		cin >> arr[i];
	}

	for (int i = 1;i <= n;i++) {
		dp[i] = 1;
		for (int j = 1;j < i;j++) {
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
		max = (max > dp[i]) ? max : dp[i];
	}

	cout << max << endl;
}
