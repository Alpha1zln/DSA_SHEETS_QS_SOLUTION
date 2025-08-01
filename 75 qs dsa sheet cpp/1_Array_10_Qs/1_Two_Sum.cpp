
// Q .. 
// 1 Two Sum 

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

// function protoype
void twoSum(vector<int>& nums, int target, vector< pair<int, int> >& SumCombVc);
void printComb(vector< pair<int, int>  >& SumCombVc);


int main() {

    vector<int> nums = {11, -7, 9, 7, 4, -5, 9} ;  // if -ve no.s with +ve .... 
    // then use 2 ptr or un map 
    // {2, 4, 7, 11, 15};  // if only +ve no. and sorted vc
    int target = 18;
    vector< pair<int, int> > SumCombVc;

    twoSum(nums, target, SumCombVc);
    printComb(SumCombVc);
    return 0;
}


// way 1 **  use 2 ptr
// function definition
// void twoSum(vector<int>& nums, int target, vector<int>& SumCombVc) {
//     sort(nums.begin(), nums.end());

//     int n = nums.size();
//     int l=0, r=n-1;
//     ll sm = 0;     bool flag = false;

//     while(l<=r) {
//         sm = nums[l] + nums[r];

//         if(sm == target)  {
//             cout << nums[l] << " " << nums[r] << endl;
//             // SumCombVc.push_back( nums[l] );
//              // SumCombVc.push_back( nums[r]} );
//             l++; r--;
//             flag = true;
//         }
//         else if(sm < target) {
//             l++;
//         }
//         else {
//             r--;
//         }
//     }
//     if(!flag)
//         cout << -1 << endl;
// }
// TC : nlogn + n   ? ?
    // for sorting nlogn , 2ptr n
// SC :  n [for sorting]  ??


// or //
// way 2 ** use un map
// function definition
void twoSum(vector<int>& nums, int target, vector< pair<int, int> >& SumCombVc ) {
    unordered_map<int, int> mpp;
    int n = nums.size();
    int l=0, r=0;
    int rmg = 0;

    while(r <= n-1) {
        rmg = target - nums[r];    

        if(mpp.find(rmg) != mpp.end() ) {
            // cout << nums[r] << " " << rmg << endl;
            SumCombVc.push_back( {rmg, nums[r]} );
            // SumCombVc.push_back(nums[r]);
        }
        else {
            mpp[ nums[r] ] = r;
        }
        
        r++;
    }

}


void printComb(vector< pair<int, int> >& SumCombVc) {
    int n = SumCombVc.size();
    for(int i=0; i<n; i++) {
        auto pr = SumCombVc[i];
        cout << pr.first << " " << pr.second << endl ;
    }
}
