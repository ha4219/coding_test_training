#include "bj_11022.h"

using namespace std;

void bj_11022() {
	int T;
	cin >> T;
	int count = 0;
	while (T--) {
		count++;
		int a, b;
		cin >> a >> b;

		cout << "Case #" << count << ": " << a << " + " << b << " = " << a + b << endl;
	}
}
