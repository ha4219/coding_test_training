#include "bj_15624.h"

using namespace std;
int f[1000000] = { 0, };


int funcd(int n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else if (f[n] != 0)
	{
		return f[n];
	}
	else {
		f[n] = (funcd(n - 1) + funcd(n - 2))% 1000000007;
		return f[n];
	}
	return 0;
}
void bj_15624() {
	int n;
	cin >> n;
	int res = funcd(n);
	cout << res << endl;
}
