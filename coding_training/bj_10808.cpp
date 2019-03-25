#include "bj_10808.h"


using namespace std;

int arr[27] = { 0, };

void bj_10808() {
	string input;
	cin >> input;
	for (int i = 0;i < input.length();i++) {
		arr[(int)input[i] - 97]++;
	}

	for (int i = 0;i < 26;i++) {
		cout << arr[i];
		if (i != 25)
			cout << " ";
	}
}