
// 1 - Combination Sum 
// same elt can be used again ... no sorting ? chk q
// leetcode 39

// #include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// fn prototype
void combSum(int st, vector<int>& nums, int tgt, int sm, 
    vector<int>& vc, vector<vector<int>>& comb);



int main() {
    vector<int> nums = {4,1,3,5,6,2}; int n = nums.size();
    int target = 7;


    // vector<bool> vis(n, false);  // = {false};
    vector<vector<int>> comb;   int sm = 0;
    int start = 0;    vector<int> vc; 

    combSum(start, nums, target, sm, vc, comb);

    if(comb.empty()) 
        cout << "no comb"; 
    else {
        for(const auto& vc : comb) {
            for(auto et : vc) {
                cout << et << " ";
            }
            cout << endl;
        }
    }

    return 0;
}


// fn definition
void combSum(int st, vector<int>& nums, int tgt, int sm, 
    vector<int>& vc, vector<vector<int>>& comb) 
{

    int n = nums.size();

    if(sm == tgt) {
        comb.push_back(vc); 
        //return;
    }
    if(sm > tgt || st >= n)  return; 
    
    for(int i=st; i<n; i++) {
       //  if(nums[i] + sm > tgt) break;      // use if array is sorted .. else not
        
        sm += nums[i];
        vc.push_back(nums[i]);
        
        combSum(i, nums, tgt, sm, vc, comb);     // not st
        
        sm -= nums[i];
        vc.pop_back();
    }
}


/*

4 1 1 1 
4 1 2 
4 3 
1 1 1 1 1 1 1 
1 1 1 1 1 2 
1 1 1 1 3 
1 1 1 2 2
1 1 3 2
1 1 5
1 3 3
1 6
1 2 2 2
3 2 2
5 2

*/