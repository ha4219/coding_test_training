#include "bj_10953.h"
#include<string>

using namespace std;

void bj_10953() {
	int T;
	cin >> T;
	while (T--) {
		string tmp;
		cin >> tmp;
		cout << (int)tmp[0] + (int)tmp[2] - 2 * (int)'0' << endl;
	}
}
