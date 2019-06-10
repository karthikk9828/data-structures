/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here

#include<iostream>
#include<map>
#include<iterator>
using namespace std;

int getMin(int A[], int n) {
    int min = A[0];
    for(int i=1; i<n; i++) {
        if(A[i] < min)
            min = A[i];
    }
    return min;
}

void LuckyOrNot(int A[], int n) {
    
    //cout << "function called";
    
    int min = getMin(A, n);
    
    map<int, int> m;
    for(int i=0; i<n; i++) {
        if(m.find(A[i]) != m.end())
            m[A[i]] += 1;
        else
            m[A[i]] = 1;
    }
    
    map<int, int> :: iterator it;
    
    //for(it = m.begin(); it != m.end(); it++)
    //    cout << it -> first << " " << it -> second << "\n"; 
    
    if(m[min] % 2 != 0)
        cout << "Lucky\n";
    else
        cout << "Unlucky\n";
}

int main() {
    
    int t, n, A[100000];
    cin >> t;
    
    while(t--) {
        cin >> n;
        for(int i=0; i<n; i++) {
            cin >> A[i];
        }
        LuckyOrNot(A, n);
    }
    
    return 0;
}