
// Q .. 
// 88  .. MERGE SORTED ARRAY 

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

// function protoype
void mergeSortedArray(vector<int>& nums1, int& maxProfit);



int main() {

    vector<int> nums = {10, 2, 14, 7, 11, 10};
    //int target = 18;

    int maxProfit = INT_MIN;
    bestTimeToSellStock(nums, maxProfit);

    cout << "maxprofit : " << maxProfit << endl;
    return 0;
}


// function definition
void bestTimeToSellStock(vector<int>& nums, int& maxProfit) {
    int n = nums.size();
    int profit = 0;
    int minBuy = nums[0];

    for(int i=1; i<=n-1; i++) {
        int sell = nums[i];

        if(sell > minBuy) {
            profit = sell - minBuy;
            maxProfit = max( maxProfit, profit);
        }

        minBuy = min(nums[i], minBuy);
    }



}

