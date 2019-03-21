
#include "bj_2178.h"


using namespace std;
/*



void bj_2178() {
	bool field[100][100] = { 0, };
	queue<Pos> q;
	vector<Pos> v[100][100];
	bool check[100][100] = { 0, };
	bool first_check[100][100] = { 0, };
	int row, col;

	cin >> row >> col;
	for (int j = 0;j < row;j++) {
		for (int i = 0;i < col;i++)
		{
			int input;
			cin >> input;
			if (input == 1)
				field[j][i] = true;
			else
				field[j][i] = false;
		}
	}

	first_check[0][0] = true;

	for (int j = 0;j < row;j++) {
		for (int i = 0;i < col;i++)
		{
			if (field[j][i] == true) {
				if ((j<row-1&&i<col-1)) {
					if (field[j + 1][i] && first_check[j+1][i] != true) {
						v[j][i].push_back(Pos{ i,j + 1 });
						first_check[j + 1][i] = true;
					}
					if (field[j][i + 1] && first_check[j][i+1] != true) {
						v[j][i].push_back(Pos{ i + 1, j });
						first_check[j ][i + 1] = true;
					}
				}
				if (j == row -1 ) {
					if (field[j][i + 1] && first_check[j][i+1] != true) {
						v[j][i].push_back(Pos{ i + 1,j });
						cout << "½ÇÇà" << endl;
					}
				}
				if (i == col - 1) {
					if (field[j + 1][i] && first_check[j + 1][i] != true) {
						v[j][i].push_back(Pos{ i, j + 1});
					}
				}
				if (j != 0) {
					if (field[j - 1][i] && first_check[j - 1][i] != true) {
						v[j][i].push_back(Pos{ i, j - 1 });
					}
				}
			}
		}
	}

	for (int j = 0;j < row;j++) {
		for (int i = 0;i < col;i++)
		{
			cout << (int)field[j][i];
		}
		cout << endl;
	}

	q.push(Pos{ 0,0 });
	check[0][0] = true;
	int count = 0;
	while (!q.empty()) {
		Pos tmp = q.front();
		q.pop();
		cout <<"tmp y: "<< tmp.y << "\ttmp x: " << tmp.x << endl;
		for (int i = 0;i < v[tmp.y][tmp.x].size();i++) {
			Pos ch_tmp = v[tmp.y][tmp.x][i];
			if (!check[ch_tmp.y][ch_tmp.x]) {
				q.push(ch_tmp);
				check[ch_tmp.y][ch_tmp.x] = true;
			}
		}
	}
}



*/

int n, m;
bool check[100][100] = { 0, };
int field[100][100] = { 0, };

int min(int y, int x, int pathLenghth) {
	queue<dir> q;
	int result = 0;
	dir start = { y,x,pathLenghth };
	q.push(start);

	while (!q.empty()) {
		int curY = q.front().y;
		int curX = q.front().x;
		int curLength = q.front().pathLength;

		if (curY == n - 1 && curX == m - 1) {
			result = curLength;
			break;
		}
		q.pop();
		check[curY][curX] = true;

		//E
		if (curX + 1 < m && field[curY][curX + 1] && !check[curY][curX + 1]) {
			dir east = { curY, curX + 1, curLength + 1 };
			check[curY][curX + 1] = true;
			q.push(east);
		}
		//W
		if (curX - 1 >= 0 && field[curY][curX - 1] && !check[curY][curX - 1]) {
			dir west = { curY, curX - 1, curLength + 1 };
			check[curY][curX - 1] = true;
			q.push(west);
		}
		//S
		if (curY + 1 < n && field[curY + 1][curX] && !check[curY + 1][curX]) {
			dir south = { curY + 1, curX, curLength + 1 };
			check[curY + 1][curX] = true;
			q.push(south);
		}
		//N
		if (curY - 1 >= 0 && field[curY - 1][curX] && !check[curY - 1][curX]) {
			dir north = { curY - 1, curX, curLength + 1 };
			check[curY - 1][curX] = true;
			q.push(north);
		}
	}

	return result;
}

void bj_2178() {
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0;j < m;j++) {
			field[i][j] = tmp[j] - '0';
		}
	}
	cout << min(0, 0, 1) << endl;
}