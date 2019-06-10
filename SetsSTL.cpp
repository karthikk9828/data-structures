/*
set maintains ascending oredr between data after every operation
*/

#include<iostream>
#include<set>
#include<iterator>
using namespace std;

int main() {

	set<int> s;

	s.insert(1);    //  1
	s.insert(2);	//  1   2
	s.insert(-1);   // -1   1  2
	s.insert(-10);  // -10 -1  1  2

	set<int> :: iterator it;
	for(it = s.begin(); it != s.end(); it++)
		cout << *it << " ";

	cout << endl;

	// find(data) returns iterator to the data if it is present in the set, otherwise returns iterator to the end()
	set<int> :: iterator it2 = s.find(-1);
	if(it2 == s.end())
		cout << "\nNot present\n"; 
	else
		cout << *it2 << " is present\n";

	set<int> :: iterator it3 = s.upper_bound(-1);  // 1
	set<int> :: iterator it4 = s.upper_bound(1);   // 2

	cout << *it3 << " " << *it4 << "\n";

	// erase an element from the set
	s.erase(1);
	for(it = s.begin(); it != s.end(); it++)
		cout << *it << " ";

	return 0;
}