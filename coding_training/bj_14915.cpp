#include "bj_14915.h"
#include<stack>


using namespace std;

void n_2(int m) {
	int rest = 0;
	stack <char> q;
	while (m > 1) {
		if (m % 2 == 1)
			q.push('1');
		else
			q.push('0');
		m /= 2;
	}
	q.push('1');
	for (int i = 0;i < q.size();i++) {
		cout << q.top() << endl;
		q.pop();
	}
}

void bj_14915() {
	int m, n;
	cin >> m;

	n_2(m);
}