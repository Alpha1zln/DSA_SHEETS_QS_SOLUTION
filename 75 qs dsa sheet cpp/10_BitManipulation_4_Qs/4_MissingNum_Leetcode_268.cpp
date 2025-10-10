

// 4 - Missing Num
// Leetcode 268

#include<iostream>
#include<vector>
using namespace std;

int findMissingNum(vector<int>& vc) ;

int main() {
    vector<int> vc = {1, 3,4,5};
    int missingNum = findMissingNum(vc);
    cout << "Missing Num : " << missingNum;

    return 0;
}


int findMissingNum(vector<int>& vc) {
        int missingNum = 0;
        int xorNum = 0;
        int n = vc.size();

    for(int i=1; i<=n+1; i++) {
        missingNum = missingNum ^ i;
    }

    for(int i=0; i<n; i++) {
        xorNum = xorNum ^ vc[i];
    }

    return missingNum ^ xorNum;
}

// op ----
// 1 3 4 5
// Missing Num : 2