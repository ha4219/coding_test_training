#include "bj_1011.h"

using namespace std;

int func(int n) {
	int res = 0;
	int max = 1;
	int count = 1;
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		while (n-max*2>0) {
			res += 2;
			n = n - max * 2;
			max++;
		}
		while (n - max > 0) {
			if (n - max > 0) {
				n = n - max;
				res++;
			}
			else {
				max--;
			}
		}
	}
	return res + 1;
}

void bj_1011() {
	int T;
	cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;
		int res = func(b - a);
		cout << res << endl;
	}
}