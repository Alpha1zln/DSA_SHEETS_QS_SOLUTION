

// 1 - Num of 1 bits
// Leetcode 191

#include<iostream>
#include<vector>
using namespace std;

int findNumOf1Bits(int vc);

int main() {
    int vc = 11;
    int ct = findNumOf1Bits( vc);
    cout << "Num of 1 bits : " << ct;

    return 0;
}

int findNumOf1Bits(int vc)  {
    int ct = 0;

    while(vc > 0) {
        ct = ct + (vc&1);
        vc = vc >> 1;
    }
    return ct;
}

// op *********
// n = 11
// Num of 1 bits : 3