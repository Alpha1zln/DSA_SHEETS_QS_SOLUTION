

// 1 - Single Num
// Leetcode 136

#include<iostream>
#include<vector>
using namespace std;

int findSingleNum(vector<int>& vc) ;

int main() {
    vector<int> vc = {1,1,2,3,3,4,4,5,5};
    int single = findSingleNum(vc);
    cout << "Single Num : " << single;

    return 0;
}

int findSingleNum(vector<int>& vc) {
        int single = 0;

    for(int i=0; i<vc.size(); i++) {
        single = single ^ vc[i];
    }

    return single;
}

// op ----
// Single Num : 2