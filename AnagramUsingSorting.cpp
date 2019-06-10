#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

bool isAnagram(string s1, string s2) {

	if(s1.length() != s2.length())
		return false;
	if(s1 == s2) {
		cout << "\nyou entered same strings\n";
		return true;
	}

	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());

/*	for(int i=0; i<s1.length(); i++) {
		if(s1[i] != s2[i])
			return false;
	}
	return true;
*/

	return (s1 == s2);

}

int main(int argc, char const *argv[]) {
	
	string s1, s2;
	cout << "Enter two strings: ";
	cin >> s1 >> s2;

	if(isAnagram(s1, s2))
		cout << "Strings are anagrams";
	else
		cout << "Strings are Not anagrams";
	return 0;
}