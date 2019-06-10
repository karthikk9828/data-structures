
#include<iostream>
#include<string.h>

using namespace std;

bool isAnagram(string s1, string s2)
{
    int allChars[256] = {0};

    if(s1.length() != s2.length())
    	return false;

    // if(strcmp(s1, s2) == 0)
    // 	return true;

    // if(s1 == s2) 
    //     return true;

    for(int i=0; i < s1.length(); i++)
        allChars[s1[i]++];

    for(int i=0; i < s2.length(); i++)
        allChars[s2[i]--];

    for(int i=0; i<256; i++)
        if(allChars[i] != 0)
        	return false;
    return true;
}

int main()
{
    string s1, s2;
    cout << "Enter two strings: \n";
    cin >> s1 >> s2;

    if(isAnagram(s1, s2))
        cout << "strings are anagrams\n";
    else
        cout << "strings are NOT anagrams\n";

    return 0;
}
 