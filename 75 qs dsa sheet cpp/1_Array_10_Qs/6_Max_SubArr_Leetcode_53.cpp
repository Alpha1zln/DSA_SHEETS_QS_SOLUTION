
// Q 6 .. 
// _Leetcode_53 .. MAX SUBARRAY 

#include <iostream>  // For std::cout, std::endl
#include <vector>    // For std::vector
#include <algorithm> // For std::max
#include <climits>   // For INT_MIN
// #include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef pair<int , int> pi;

// function protoype
void findMaxSubArrSum(vector<int>& nums, int& maxLen, int& maxSubArrSum, 
        vector<int>& maxSubArr);
void printArray(vector<int>& maxSubArr, int& maxSubArrSum, int& maxLen);


int main() {

    // vector<int> nums = {-5, -3, -7, -10, -2,  -4 };
     vector<int> nums = {1, 2, -10,  6, 4, -7, 9, -12, 8}; 
    // vector<int> nums = {1, 2, -1,  3, 4, 5};     
    int n = nums.size();
    vector<int> maxSubArr;
    int maxSubArrSum = INT_MIN;   int maxLen = 1;

    findMaxSubArrSum( nums, maxLen, maxSubArrSum, maxSubArr);
    printArray(maxSubArr, maxSubArrSum, maxLen);

    return 0;
}


// fn defntn
void findMaxSubArrSum(vector<int>& nums, int& maxLen, int& maxSubArrSum, vector<int>& maxSubArr)
{
    int n = nums.size();   int endIdx = n -1 ;
    int currSubArrSum = 0;         int max_startIdx=0, max_endIdx=0;
    int l = 0, r = 0;

    while(r <= endIdx && l <= endIdx) {
        currSubArrSum += nums[r];

        if(currSubArrSum > maxSubArrSum) {
            maxSubArrSum = currSubArrSum;
            max_startIdx = l;
            max_endIdx = r;
            int ln = r-l + 1;
            maxLen = max(ln, maxLen);
        }

        if(currSubArrSum < 0) {
            currSubArrSum = 0;
            l = r+1;
        }

        r++;
    }

    // store the max subarray
    for(int i = max_startIdx; i <= max_endIdx; i++) {
        maxSubArr.push_back(nums[i]);
    }

}


void printArray(vector<int>& maxSubArr, int& maxSubArrSum, int& maxLen) {

    cout << "maxSubArr :: ";
    for(auto e : maxSubArr) {
        cout << e << " ";
    }
    cout << endl;

    cout << "Max Sub Array Sum: " << maxSubArrSum << endl;
    
    cout << "max len :: " << maxLen  << endl;
        //cout << maxLen 
}


// op ---
//   vector<int> nums = {1, 2, -10,  6, 4, -7, 9, -12, 8}; 
// maxSubArr :: 6 4 -7 9 
// Max Sub Array Sum: 12
// max len :: 4

/* 
vector<int> nums = {-5, -3, -7, -10, -2,  -4 };    
maxSubArr :: -2 
Max Sub Array Sum: -2
max len :: 1
*/

/*


Time Complexity
O(n) → Single pass through the array.

Space Complexity
O(1) extra space → Only using a few variables.

Output array storage is O(k) where k = length of the max subarray.




5 Interview Tips for This Problem
Always mention Kadane’s Algorithm by name; it shows awareness of standard algorithms.

When asked for space complexity, clarify if they mean extra space or total space (including output).

Be prepared to return both sum and subarray — your code already does it, which is a big plus.

Mention edge case handling — all-negative arrays, single-element arrays, and arrays with zeros.

Bring up extensions — 2D Kadane’s, circular arrays, and variations where you find max product instead of sum.

5 Interview Questions & Answers
Q1: What’s the intuition behind resetting currSubArrSum to 0?
A: A negative sum will only decrease the sum of any subarray it’s part of. Resetting allows us to start fresh with a potentially larger sum.

Q2: How would you handle an array with all negative numbers?
A: Initialize maxSubArrSum = nums[0] and avoid resetting to zero. Instead, compare currSubArrSum directly with maxSubArrSum without the currSubArrSum < 0 reset.

Q3: How to adapt this for a circular array?
A: Run Kadane’s once for normal max subarray. Then, run it for min subarray sum, and subtract that from total sum to get circular max. Return max of the two.

Q4: Can Kadane’s be used for streams of data?
A: Yes, because it only depends on the current sum and max so far — you can process elements as they arrive without storing the whole array.

Q5: What’s the difference between your version and the standard Kadane’s?
A: Standard Kadane’s only returns the sum, mine additionally tracks start and end indices so I can output the actual subarray.


Interview Q&A (5 questions with 3-line answers) gmni
Q: What is the core idea behind Kadane's Algorithm?

A: Kadane's algorithm maintains a current_sum and a max_so_far. If current_sum becomes negative, it's reset to zero (or the current element if all numbers can be negative), as a negative prefix will only decrease future sums.

Q: How does this algorithm handle an array where all numbers are negative?

A: If all numbers are negative, the maximum subarray sum will be the single largest (least negative) number in the array. Kadane's correctly identifies this by initializing maxSubArrSum to INT_MIN and updating it even with negative current_sum values.

Q: Can this algorithm be adapted to find the maximum product subarray?

A: No, not directly. For maximum product, you need to track both the maximum and minimum product ending at the current position, because multiplying by a negative number can turn a small negative into a large positive.

Q: Why is the time complexity O(N) and not O(N^2)?

A: It's O(N) because it only requires a single pass through the array. Unlike brute-force methods that check all possible subarrays (which would be O(N^2)), Kadane's makes local optimal decisions that lead to the global optimum.

Q: What are the space complexity trade-offs if you only need the maximum sum, not the subarray elements?

A: If only the maximum sum is required, the space complexity becomes O(1). You only need a few variables to store current_sum and maxSubArrSum, without needing to store the actual subarray elements.





**********


Code Review & Improvements
✅ Good things in your code:

You replaced <bits/stdc++.h> with specific includes (<iostream>, <vector>, <algorithm>, <climits>) → This is best practice.

Now you track start and end indices so the actual subarray is returned. This is often a follow-up interview question — good move.

Code is clear and beginner-friendly, variables are decently named.

🔹 Possible Improvements:

Variable Naming:

l, r → could be start, end for readability.

max_startIdx and max_endIdx are clear, so that’s good.

Length Calculation:

Instead of maxLen = max(ln, maxLen), you can simply do maxLen = ln when maxSubArrSum is updated (since that’s the only time length changes).

Edge Case Handling:

If all numbers are negative, current reset-to-zero step may skip the best single-element array. Fix by initializing currSubArrSum = nums[0] and adjusting logic to handle negatives.

Const References:

In printArray(), vector<int>& maxSubArr could be const vector<int>& since you’re not modifying it. Same for maxSubArrSum and maxLen.

Remove Unused Variables:

n in main() isn’t used after initialization, so you could skip it.

Steps of the Algorithm (Kadane’s Algorithm with Indices)
Initialize Variables:

maxSubArrSum to smallest possible value (INT_MIN).

currSubArrSum to 0.

Two pointers: l (start of current subarray) and r (end index).

Variables max_startIdx and max_endIdx to store best subarray indices.

Traverse the Array:

Add nums[r] to currSubArrSum.

If currSubArrSum > maxSubArrSum, update maxSubArrSum and best indices.

If currSubArrSum < 0, reset currSubArrSum to 0 and move l to r+1.

Store Result Subarray:

After loop, push all elements from max_startIdx to max_endIdx into maxSubArr.

Output Results:

Print subarray, max sum, and max length.


*/

