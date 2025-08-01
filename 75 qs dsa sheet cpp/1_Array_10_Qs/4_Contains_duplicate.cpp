
// Q 4 .. 
// 217  .. CONTAINS DUPLICATE 

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef pair<int , int> pi;

// function protoype
void findDuplicates(vector<int>& nums);



int main() {

    vector<int> nums = {10, 2, 11,  7, 11, 7};
        
    findDuplicates( nums);

    return 0;
}


// 1st way *********
// fn  definition
// void findDuplicates(vector<int>& nums) {
//     int n = nums.size();
//     bool flag = false;
//     sort(nums.begin(), nums.end() );             // tc -  nlogn , sc - n

//     for(int i=1; i<n; i++) {                    //  tc - n
//         if(nums[i] == nums[i-1]) {
//             flag = true;
//             cout << nums[i] << endl;  // return;
//         } 
//     }

//     if(false)
//         cout << -1 << endl;
// }


// 2nd way ****
// fn  definition
void findDuplicates(vector<int>& nums) {
    unordered_map<int , int >  mpp;            // n or n^2
    int n = nums.size();
    bool flag = false;

    // for(int i=0; i<n; i++) {
    for( auto e : nums) {                // n 
        if(mpp.find(e) != mpp.end() ) {
            cout << e << endl;
            flag = true;
        }
        else {
            mpp[e]++;
        }
    }

    //int ans = (flag == false ? -1 : 1); 
    if (!flag)
        cout << -1;

 }