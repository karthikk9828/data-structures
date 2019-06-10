#include<iostream>
#include <map>
#include<unordered_map>
#include<string.h>
#include<iterator>
using namespace std;

/*//##############################################################################
	// leetcode problem using map

bool isIsomorphic(string s, string t) {
    
    unordered_map<char, int> map1;
    unordered_map<char, int> map2;
    
    for(int i=0; i<s.length(); i++) {
        if(map1.find(s[i]) != map1.end())
            map1[s[i]]++;
        else
            map1[s[i]] = 1;
    }
    
    for(int i=0; i<t.length(); i++) {
        if(map2.find(s[i]) != map2.end())
            map2[s[i]]++;
        else
            map2[s[i]] = 1;
    }
    
    for(auto it1 = map1.begin(); it1 != map1.end(); it1++) {
        for(auto it2 = map2.begin(); it2 != map2.end(); it2++) {
            if(it1 -> second != it2 -> second)
                return false;
        }
    }
    
    return true;
}*/

int main() {

	map<int, int> m;

	pair<int, int> p = make_pair(12, 32);
	m.insert(p);

	m[1] = 100;
	m[3] = 21;
	m[100000232] = 18;
	m[5] = 1;

	m.insert(make_pair(23, 90));   // 23 is the key, 90 is the value
	m.insert(make_pair(23, 11));   // ignores as there is already a key 23 in the map

	for(map<int, int> :: iterator it = m.begin(); it != m.end(); it++)
		cout << it -> first << " " << it -> second << "\n";

	cout << endl << endl;

	// multimap allows multiple identical keys, multimap does not support [] operator
	multimap<int, int> mp;

	mp.insert(make_pair(12, 219));
	mp.insert(make_pair(2, 90));
	mp.insert(make_pair(31, 102));
	mp.insert(make_pair(6, 11));

	mp.insert(make_pair(23, 30));   // 23 is the key, 90 is the value
	mp.insert(make_pair(23, 11));   // executes and keeps 2 keys 23

	for(multimap<int, int> :: iterator it = mp.begin(); it != mp.end(); it++)
		cout << it -> first << " " << it -> second << "\n";

	cout << "Map size: " << m.size() << endl;/home/karthikk/Karthik K/Programs/Data Structures/AnagramUsingSorting.cpp
	cout << "Multimap size: " << mp.size() << endl;

	

    cout << "\n\n" << isIsomorphic("egg", "add");

	return 0;
}