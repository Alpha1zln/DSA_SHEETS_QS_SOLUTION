#include<bits/stdc++.h>
using namespace std;

// 6 NGE I ... 
// LEETCODE ... 496


int main() {
    vector<int> vc  = {2,9,6,8,1,5};
    int n = vc.size();
    vector<int> nge(n);
    stack<int> stk;

    for(int i=n-1; i>=0; i--) {
        while(!stk.empty() && stk.top() <= vc[i]) {
            stk.pop();
        }
        if(stk.empty()) {
            nge[i] = -1;
        }
        else {
            nge[i] = stk.top();
        }
        

        stk.push(vc[i]);
    }

    // print nge
    for(int i=0; i<n; i++) {
        cout << "elt : " << vc[i] << " - " << "nge : " << nge[i] << endl;
    }
}



// // **********
// elt : 2 - nge : 9
// elt : 9 - nge : -1
// elt : 6 - nge : 8
// elt : 8 - nge : -1
// elt : 1 - nge : 5
// elt : 5 - nge : -1