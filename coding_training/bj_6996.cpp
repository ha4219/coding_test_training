#include "bj_6996.h"
#include<string>

using namespace std;

int* check_string(string param) {
	int *arr = new int[26];
	for (int i = 0;i < param.length();i++) {
		arr[(int)param[i] - (int)'a']++;
	}
	return arr;
}

bool check_anagram(string a, string b) {
	if (a.length() != b.length())
		return false;
	int *a_tmp = check_string(a);
	int *b_tmp = check_string(b);
	for (int i = 0;i < 26;i++) {
		if (a_tmp[i] != b_tmp[i])
			return false;
	}
	return true;
}


void bj_6996() {
	int T;
	cin >> T;

	while (T--) {
		string a, b;
		cin >> a >> b;
		if (check_anagram(a, b))
			cout << a << " & " << b << " are anagrams." << endl;
		else
			cout << a << " & " << b << " are NOT anagrams." << endl;
	}
}