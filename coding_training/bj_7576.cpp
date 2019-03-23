#include "bj_7576.h"
#include<queue>

using namespace std;

typedef struct {
	int y, x, lenght;
}tomato;

int tomato_field[1001][1001] = { 0, };
bool tomato_check[1001][1001] = { 0, };

void bj_7576() {
	queue<tomato> q;
	tomato start;
	int M, N;
	int result = 0;
	int count = 0;
	cin >> M >> N;

	//ют╥б
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> tomato_field[i][j];
			if (tomato_field[i][j] == 1) {
				start = { i,j,0 };
				q.push(start);
				tomato_check[start.y][start.x] = true;
			}
			else if (tomato_field[i][j] == 0)
				count++;
			else if (tomato_field[i][j] == -1)
				tomato_check[i][j] = true;
		}
	}

	
	while (count != 0) {
		int curY = q.front().y;
		int curX = q.front().x;
		int curLength = q.front().lenght;
		q.pop();
		tomato_check[curY][curX] = true;
		
		if (curX - 1 >= 0 && !tomato_check[curY][curX - 1]) {
			tomato west = { curY, curX - 1,curLength + 1 };
			tomato_check[curY][curX - 1] = true;
			q.push(west);
			count--;
			if (count == 0) {
				result = curLength + 1;
				break;
			}
		}
		
		if (curX + 1 < M && !tomato_check[curY][curX + 1]) {
			tomato east = { curY,curX + 1, curLength + 1 };
			tomato_check[curY][curX + 1] = true;
			q.push(east);
			count--;
			if (count == 0) {
				result = curLength + 1;
				break;
			}
		}
		if (curY - 1 >= 0 && !tomato_check[curY - 1][curX]) {
			tomato north = { curY - 1, curX, curLength + 1 };
			tomato_check[curY - 1][curX] = true;
			q.push(north);
			count--;
			if (count == 0) {
				result = curLength + 1;
				break;
			}
		}
		if (curY + 1 < N && !tomato_check[curY + 1][curX]) {
			tomato south = { curY + 1,curX, curLength + 1 };
			tomato_check[curY + 1][curX] = true;
			q.push(south);
			count--;
			if (count == 0) {
				result = curLength + 1;
				break;
			}
		}

		if (count > 0 && q.empty()) {
			result = -1;
			break;
		}
	}
	cout << result << endl;
}
