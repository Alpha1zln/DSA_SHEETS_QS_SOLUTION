
// Q .. 
// 1 Two Sum 
// _Leetcode_1

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



/*
Way 1 – Two Pointer Method (with Sorting)
How It Works:

First, check whether the array is sorted. If it is not sorted, sort the array using an efficient O(n log n) algorithm like mergesort or quicksort.
Set one pointer (l) at the start of the array and another pointer (r) at the end of the array.
Calculate the sum of the elements at these two pointers: sum = nums[l] + nums[r].
If the sum is equal to the target, store this pair in the result list and move both pointers inward (l++, r--) to check for other possible pairs.
If the sum is less than the target, move the left pointer forward (l++) to increase the sum.
If the sum is greater than the target, move the right pointer backward (r--) to decrease the sum.
Continue this process until the two pointers meet or cross each other.

Time Complexity:
Sorting → O(n log n)
Two-pointer scan → O(n)
Total → O(n log n + n) = O(n log n)
Already sorted → O(n)

Space Complexity:
In-place sorting → O(1) extra space
Recursive sort stack → O(log n) space

Pros:
Very space-efficient as it requires constant extra space apart from the input array.
Predictable performance and not affected by hash function quality.
Best suited for sorted data, especially when multiple queries are made on the same sorted array.

Cons:
Needs sorting first if the array is unsorted, which increases time complexity.
Loses original index information unless stored separately before sorting.


Interview Tip:
If the interviewer mentions the array is already sorted, you should mention the two-pointer approach immediately and state that it can be done in O(n) time after sorting. This shows you understand how problem constraints can help optimize solutions.

5 Interview Questions & Answers:

Why does this method require sorting?
Sorting ensures that moving pointers changes the sum in a predictable way. Without sorting, there is no guarantee that increasing the left pointer or decreasing the right pointer will get us closer to the target sum.

How can we get the indices after sorting?
Before sorting, store the original index along with each element as a pair (value, index). After finding the pair in the sorted array, you can easily map back to their original positions in the input.

Why is this method O(n) after sorting instead of O(n²)?
Because each pointer moves in only one direction, and each move reduces the search space by one element. There are at most n moves total, making the scanning step O(n).

What sorting algorithm is best for this?
Any O(n log n) sorting algorithm is fine, but stable sorts like mergesort can be preferred if maintaining relative order is important. Quicksort is faster in practice but may degrade to O(n²) in rare cases.

How do we avoid duplicate pairs in the result?
After finding a valid pair, increment the left pointer while the next value is the same as the previous one, and similarly decrement the right pointer while the next value is the same as the previous one. This ensures each pair is unique.

Interview Tip:
19. If interviewer says “array is sorted” → jump to two-pointer solution immediately.
20. Mention that this is a deterministic O(n) method after sorting.


5 Interview Questions & Answers:

Q: Why does this need sorting?
A: Sorting ensures pointer movement changes sum predictably — without it, logic breaks.

Q: Can you get indices with this method?
A: Yes, store (value, index) pairs before sorting, then map back.

Q: Why is TC not O(n²)?
A: Because pointers move only one step per iteration, total O(n) after sorting.

Q: Best sorting method here?
A: O(n log n) algorithms like mergesort/quick sort; avoid O(n²) like bubble sort.

Q: How to avoid duplicate pairs?
A: Skip over identical values after finding a pair.
*/



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


/*
Way 2 – Hash Map Method
How It Works:

Create an empty unordered_map to store numbers you have already visited, with the number as the key and its index as the value.
Iterate through the array one element at a time.
For the current number, calculate the remaining value needed to reach the target: remaining = target - nums[i].
Check if the remaining value exists in the map. If it does, it means you have found a pair that sums to the target. Store this pair in the result.
If it does not exist, add the current number to the map with its index.
Continue until the end of the array is reached.


Time Complexity:
Average case → O(n), because hash map lookups and insertions are O(1) on average.
Worst case → O(n²), but this only happens with excessive hash collisions, which is rare with a good hash function.

Space Complexity:
Hash map can store up to n elements → O(n) space.

Pros:
Does not require sorting, so it works in a single pass for unsorted arrays.
Naturally preserves the original index positions.
Very efficient for large datasets in average-case scenarios.

Cons:
Requires extra memory proportional to the array size.
Performance depends on hash function quality; in extreme collision cases, time complexity can degrade significantly.


Interview Tip:
When the array is unsorted and n is large, highlight that the hash map method achieves O(n) average time. 
Also mention the worst-case behavior to show you understand the data structure limitations.

5 Interview Questions & Answers:

Why is this faster than sorting for unsorted arrays?
The hash map allows constant-time lookups for complements, so you avoid the O(n log n) cost of sorting entirely and finish in O(n) average time.

How do you handle duplicates with a hash map?
You can store all occurrences of the same value by using a vector of indices as the map value, or allow the latest index to overwrite the previous if only one pair is needed.

Why can unordered_map degrade to O(n²) in the worst case?
If many elements hash to the same bucket, lookups and insertions become linear in the bucket size, and with n elements this can degrade to quadratic time overall.

What happens if you use ordered_map instead?
Each lookup and insertion becomes O(log n) instead of O(1), making the total complexity O(n log n), which is still fine but slower than the average case for unordered_map.

How can we reduce space usage?
If you only need one pair, you can remove each element from the map once it has been processed. This way, the map never grows beyond O(n) in the worst case but may often be smaller in practice.

Interview Tip:
15. If input is unsorted and you need indices, this is the best method.
16. Mention that it’s optimal for competitive programming when memory isn’t a bottleneck.

5 Interview Questions & Answers:

Q: Why is hash map faster for unsorted arrays?
A: Avoids sorting, giving O(n) average time.

Q: How to handle duplicates?
A: Allow multiple same values in map, but decide based on index order.

Q: Why can unordered_map be slow in worst case?
A: Too many elements in same bucket → long chains to traverse.

Q: Can you do it with ordered_map?
A: Yes, but ordered_map is O(log n) per lookup → total O(n log n).

Q: How to reduce space?
A: Remove elements from map once processed (works if only one pair needed).
*/


/*
Feature	Two Pointer (Sorted)	Hash Map (Unsorted)
TC (avg)	O(n log n)	O(n)
TC (best, sorted)	O(n)	O(n)
SC	O(1) / O(log n)	O(n)
Preserves index order?	❌	✅
Works on unsorted?	Needs sort	✅
Memory usage	Low	High
*/

/*

*/