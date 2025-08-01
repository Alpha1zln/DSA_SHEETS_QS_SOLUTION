
// Q 7 .. 
// 15  .. THREE SUM QS

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef pair<int , int> pi;

// function protoype
void find3Sum(vi& nums, int& target, vvi& threeSumVec);
void printArr(vvi& threeSumVec);



int main() {
    
    // vector<int> nums = {1, 2, 0,  3, 4, 5}; // wtt reptn  
    //   0 1 2 3 4 5 ... 0 1 5, 0 2 4, 1 2 3

    vector<int> nums = {1, 2, 0, 1, 3, 4, 2, 5}; // wth reptn 

    int target = 6;

    int n = nums.size();
    vvi threeSumVec;
    
find3Sum(nums,  target, threeSumVec);
printArr(threeSumVec);

    return 0;
}


// fn defntn
void find3Sum(vi& nums, int& target, vvi& threeSumVec) {
    sort( nums.begin(), nums.end() );
    int n = nums.size();
    int sm = 0;

    for(int i=0; i<n; i++) {
        sm = nums[i];
        int l = i+1,  r=n-1;

        if(i>=1) { // check duplication
            if(nums[i]==nums[i-1]) 
                continue;
        }

        while(l < r) {
            while(l+1<=n-1 && nums[l] == nums[l+1]) l++;  // handle reptn
            while(r+1<=n-1 && nums[r] == nums[r+1]) r--;  // handle reptn
             
            int sm2 = nums[l] + nums[r];
            int totalSum = sm + sm2;

            if(totalSum == target) {
                threeSumVec.push_back({nums[i], nums[l], nums[r] });
                l++;
            }
            else if(totalSum < target) {
                l++;
            }
            else {
                r--;
            }
            
        } // while end 
    } // for 
}


void printArr(vvi& threeSumVec) {
    int idx;

    for(auto vc : threeSumVec) {
        for(auto e : vc) {
            cout << e  ;
            cout << (idx != 2 ? " " " " : " " );
        }
        cout << endl;
    }
}



// op ------
// 0  1  5  
// 0  2  4
// 1  1  4
// 1  2  3


