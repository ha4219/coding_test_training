#include "bj_1076.h"

#include<string>

using namespace std;

int check_string(string param) {
	if (param == "black") {
		return 0;
	}
	else if (param == "brown") {
		return 1;
	}
	else if (param == "red") {
		return 2;
	}
	else if (param == "orange") {
		return 3;
	}
	else if (param == "yellow") {
		return 4;
	}
	else if (param == "green") {
		return 5;
	}
	else if (param == "blue") {
		return 6;
	}
	else if (param == "violet") {
		return 7;
	}
	else if (param == "grey") {
		return 8;
	}
	else if (param == "white") {
		return 9;
	}
	else
		return 0;
}

void bj_1076() {
	string a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;
	long long res = 0;
	res += check_string(a) * 10;
	res += check_string(b);
	for (int i = 0;i < check_string(c);i++) {
		res *= 10;
	}
	cout << res << endl;
}