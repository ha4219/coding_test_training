#include "bj_2504.h"
#include<string>
#include<stack>

using namespace std;

void bj_2504() {
	stack <char> st;
	string input;
	cin >> input;
	int temp = 1;
	int result = 0;
	bool impossible = false;


	for (int i = 0;i < input.length();i++) {
		if (input[i] == '(') {
			temp *= 2;
			st.push('(');
		}
		else if (input[i]=='[') {
			temp *= 3;
			st.push('[');
		}

		else if (input[i] == ')' && (st.empty() || st.top() != '(')) {
			impossible = true;
			break;
		}
		else if (input[i] == ']' && (st.empty() || st.top() != '[')) {
			impossible = true;
			break;
		}

		else if (input[i] == ')'){
			if (input[i - 1] == '(')
				result += temp;
			st.pop();
			temp /= 2;
		}
		else if (input[i] == ']') {
			if (input[i - 1] == '[') {
				result += temp;
			}
			st.pop();
			temp /= 3;
		}
	}

	if (impossible || !st.empty()) {
		cout << 0 << endl;
	}
	else {
		cout << result << endl;
	}
}
