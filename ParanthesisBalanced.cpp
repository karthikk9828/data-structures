
/* program to check if a string containing paranthesis is balanced  using stack

	(){}[] -> balanced
	({})[] -> balanced
	({)}[] -> not balanced
  */

#include<iostream>
#include<string.h>
#include<stack>

using namespace std;

bool AreMatching(char open, char close) {

	if(open == '(' && close == ')')
		return true;
	else if(open == '[' && close == ']')
		return true;
	else if(open == '{' && close == '}')
		return true;

	return false;
}

bool IsParanthesisBalanced(char input[]) {

	stack<char> S;
	
	for(int i=0; i< strlen(input); i++) {
		if(input[i] == '(' || input[i] == '[' || input[i] == '{')
			S.push(input[i]);

		else if(input[i] == ')' || input[i] == ']' || input[i] == '}') {
			if(S.empty() || !AreMatching(S.top(), input[i])) 
				return false;
			else
				S.pop();
		}
	}

	while(!S.empty()) {
		cout << S.top() << endl;
		S.pop();
	}

	return S.empty() ? true : false;
}

int main() {

	char input[] = "(){[}]";

	if(IsParanthesisBalanced(input))
		cout << "balanced";
	else
		cout << "not balanced";

	return 0;
}