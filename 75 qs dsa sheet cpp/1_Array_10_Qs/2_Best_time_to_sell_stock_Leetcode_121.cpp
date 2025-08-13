
// Q .. 
//   .. best Time To buy and Sell Stock
// _Leetcode_121


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

// function prototype
void bestTimeToSellStock(vector<int>& nums, int& maxProfit);



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

/*
Method – Single Pass (Min Buy Tracking)
How It Works (Step-by-Step):
Step 1: Initialize minBuy as the first price in the array. 
This will store the lowest price we’ve seen so far (best buy day).

Step 2: Initialize maxProfit as negative infinity (or 0 if you want no-transaction case).

Step 3: Loop through the array starting from day 1:
If current price is higher than minBuy, calculate profit = current price - minBuy.
Update maxProfit if this profit is greater than the current maxProfit.
Update minBuy to be the minimum between minBuy and current price.

Step 4: At the end of the loop, maxProfit contains the largest possible profit from one buy-sell transaction.

Step 5: Return or print maxProfit.

Time Complexity:
Loop through array once: O(n)
No sorting, no nested loops.
Total: O(n)

Space Complexity:
Uses only constant extra space (minBuy, maxProfit, profit variables).
Total: O(1)


Pros:
Extremely efficient — only one pass through the prices.
Uses O(1) extra space.
Easy to code and debug.
Handles large input sizes easily.
Works for both increasing and decreasing stock prices.

Cons:
Only works for one buy-sell transaction.
Doesn’t handle multiple transactions unless modified.
No record of actual days (indices) unless we track them separately.
Assumes at least one price is available.
Fails if input array is empty (needs a check).


Interview Tip:
If interviewer says “only one transaction allowed” → 
immediately use minBuy tracking method.

Mention that brute-force (checking all pairs) is O(n²), but this method optimizes to O(n).
If they ask for indices of buy/sell days, mention you can store the day when 
minBuy updates and when maxProfit updates.

5 Interview Questions & Answers
Q1: Why do we update minBuy after checking profit?
A1: Because we want to calculate profit using the lowest buy price so far before 
possibly replacing it with the current price. This ensures we don't "sell before we buy."

Q2: What happens if prices are strictly decreasing?
A2: maxProfit will remain negative or zero (depending on initialization). 
You can return 0 if no profit is possible.

Q3: Can we use this method for multiple transactions?
A3: Not directly. This method is for one transaction. 
For multiple, we’d sum all positive differences or use DP.

Q4: Why is space O(1) here?
A4: We don’t store extra arrays — just a few variables regardless of input size.

Q5: How to modify the code to also return buy/sell days?
A5: Keep track of the index when minBuy changes (buy day) and when maxProfit changes (sell day).
*/