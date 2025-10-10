
// Subsets 
// Leetcode 78 ... 


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// fn prototype
void findAllSubsets(int startIdx, vector<int>& nums, int n, int curr_sum, 
    vector<bool>& vis, vector<int>& subset, vector<vector<int>>& allSubsets);



int main() {
    vector<int> nums = {1,2,3}; int n = nums.size();

    vector<bool> vis(n, false);  // = {false};
    vector<vector<int>> allSubsets;   int curr_sum = 0;
    int startIdx = 0;    vector<int> subset; 

    findAllSubsets(startIdx, nums, n, curr_sum, vis, subset, allSubsets);

    cout << "Total Subsets : " << allSubsets.size() << endl;;
    cout << "All Subsets :: " << endl;   bool once = true;
        for(const auto& vc : allSubsets) {
            if(vc.empty()) {
                cout << "{}" << endl;
                continue;
            }

            for(auto et : vc) {
                cout << et << " ";
            }
            cout << endl; 
        }


    return 0;
}


// fn definition
void findAllSubsets(int startIdx, vector<int>& nums, int n, int curr_sum, 
    vector<bool>& vis, vector<int>& subset, vector<vector<int>>& allSubsets)
{
    
    if(startIdx >= n) {
        allSubsets.push_back(subset); 
        return;
    }

    
    subset.push_back(nums[startIdx]);
    findAllSubsets(startIdx+1, nums, n, curr_sum, vis, subset, allSubsets);
    subset.pop_back();
    findAllSubsets(startIdx+1, nums, n, curr_sum, vis, subset, allSubsets);
    
}



/*
Total Subsets : 8
All Subsets :: 
1 2 3 
1 2 
1 3 
1 
2 3
2
3
{}
*/


