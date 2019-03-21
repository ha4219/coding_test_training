#include "bj_1697.h"
#include<queue>

using namespace std;

typedef struct {
	int n, length;
} bfs;


int check[100003] = { 0, };

void bj_1697() {
	int result = 0;
	queue<bfs> q;
	int n, k;
	cin >> n >> k;
	bfs start = { n, 0 };
	q.push(start);

	while (!q.empty()) {
		int curN = q.front().n;
		int curLenght = q.front().length;
		if (curN == k) {
			result = curLenght;
			break;
		}

		q.pop();
		check[curN] = true;

		if (curN + 1 <= 100000 && !check[curN + 1])
		{
			check[curN + 1] = 1;
			q.push({ curN + 1, curLenght + 1});
		}
		if(curN -1 >= 0 && !check[curN - 1]) {
			check[curN - 1] = 1;
			q.push({ curN - 1 , curLenght + 1 });
		}
		if (curN*2<=100000 && !check[curN * 2]) {
			check[curN * 2] = 1;
			q.push({ curN * 2, curLenght + 1 });
		}
	}


	cout << result << endl;
}
