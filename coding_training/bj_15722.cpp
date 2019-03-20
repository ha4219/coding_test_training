#include "bj_15722.h"

using namespace std;

enum direction {
	up = 0,
	rright = 1,
	lleft = 2,
	down = 3
};

void bj_15722() {
	int n;
	cin >> n;
	int x = 0, y = 0;
	direction d = up;
	int range = 1;
	int count = 0;
	bool stop = true;

	while (stop) {
		for (int j = 0;j < 2;j++) {
			for (int i = 0;i < range;i++) {
				if (d == up) {
					y++;
					n--;
				}
				else if (d == rright) {
					x++;
					n--;
				}
				else if (d == down) {
					y--;
					n--;
				}
				else if (d == lleft) {
					x--;
					n--;
				}
				if (n == 0) {
					stop = false;
					break;
				}
			}
			if (d == up) {
				d = rright;
			}
			else if (d == rright) {
				d = down;
			}
			else if (d == down) {
				d = lleft;
			}
			else if (d == lleft) {
				d = up;
			}
			if (n == 0) {
				stop = false;
				break;
			}
		}
		range++;
	}
	
	

	

	cout << x <<" "<< y << endl;
}