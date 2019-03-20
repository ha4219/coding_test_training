#include "bj_15734.h"

using namespace std;


void bj_15734() {
	int all = 0, left = 0, right = 0;
	cin >> left >> right >> all;

	for (;(all > 0);all--) {
		(left < right) ? left++ : right++;
	}


	int res = (left > right) ? right * 2 : left * 2;
	cout << res << endl;
}
