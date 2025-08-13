
// Q 4 .. 
// _Leetcode_217  .. CONTAINS DUPLICATE 

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




/*
The provided code snippet aims to find and print duplicate numbers in a given vector by first sorting it.

Time and Space Complexity Analysis
Let N be the number of elements in the input vector<int> nums.

Sorting the array:

sort(nums.begin(), nums.end());

Time Complexity (TC): O(N log N)

std::sort in C++ typically uses an IntroSort algorithm (a hybrid of QuickSort, HeapSort, and InsertionSort), which guarantees O(N log N) time complexity in the average and worst cases.

Space Complexity (SC): O(log N) to O(N)

The space complexity for std::sort depends on its implementation. QuickSort uses O(log N) space for its recursion stack in the average case (O(N) in worst case), while MergeSort typically uses O(N) auxiliary space.

Traversing the sorted array:

for(int i=1; i<n; i++) { if(nums[i] == nums[i-1]) { ... } }

Time Complexity (TC): O(N)

This loop iterates through the array once, performing constant-time operations (comparison, access, print) for each element.

Space Complexity (SC): O(1)

Only a few constant-size variables (i, flag) are used.

Total Complexity:

Total Time Complexity (TC): O(N log N)

The sorting step (O(N log N)) dominates the traversal step (O(N)).

Total Space Complexity (SC): O(log N) to O(N)

The space used by the sorting algorithm dominates any additional constant space used by the loop.

Interview Tips (5 lines)
Always clarify if duplicates need to be returned or just their presence.

Discuss trade-offs: sorting is simple but not O(N). Hash maps offer O(N) but use more space.

Consider constraints: range of numbers (can we use an array as a frequency map?), memory limits.

Explain your chosen approach, including its time and space complexity.

Handle edge cases like empty arrays or arrays with no duplicates.

Interview Q&A (5 questions with 3-line answers)
Q: Can you find duplicates without modifying the input array?

A: Yes, using a hash set (std::unordered_set) or a frequency map (std::unordered_map) allows you to track seen elements without altering the original array. This would involve iterating through the array and checking for existence in the map/set.

Q: What if the numbers are within a specific range, say 1 to N?

A: If numbers are in the range [1, N] and the array size is N+1, you can use the "Floyd's Cycle-Finding Algorithm" (like finding a cycle in a linked list) to find a duplicate in O(N) time and O(1) space. Alternatively, you can use the array itself as a hash map by marking visited elements.

Q: How would you find all duplicate numbers, not just the first occurrence of each?

A: After sorting, you'd iterate and print every time nums[i] == nums[i-1]. If using a hash map, you'd store counts instead of just presence, and then iterate through the map to find elements with counts greater than one.

Q: Why is the std::sort time complexity O(N log N) and not O(N^2)?

A: std::sort uses efficient comparison-based sorting algorithms (like IntroSort) that leverage divide-and-conquer strategies. These algorithms perform comparisons and swaps in a way that scales logarithmically with the number of elements, unlike simpler O(N^2) sorts like Bubble Sort.

Q: When would you prefer the sorting approach over a hash map approach for finding duplicates?

A: You'd prefer sorting if memory is extremely constrained (hash maps use O(N) space) or if the array needs to be sorted for other subsequent operations anyway. If the problem allows modifying the array and O(N log N) time is acceptable, it's a simple solution.
*/



// 2nd way *************************************
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

 /*
 Method – Hash Map Method (Detect Duplicates in One Pass)
How It Works (Step-by-Step):
Step 1: Initialize an empty hash map (or hash set) to store numbers we have already seen.

Step 2: Iterate over each element in the array.

Step 3: For each number:

If it exists in the hash map already → duplicate found → print it (or return true).

Otherwise → add it to the hash map.

Step 4: If the loop ends without finding a duplicate → return -1 (or false).

Time Complexity:
Iterating through all n elements → O(n).

Each hash map lookup/insertion → average O(1).

Total: O(n) average case, O(n²) worst case if many hash collisions (rare with good hash functions).

Space Complexity:
We store up to n elements in the hash map → O(n).

Pros:
Fast average-case performance (O(n)).

Simple to implement and easy to read.

Works on unsorted arrays without extra sorting step.

Can detect duplicates in one pass (no need to scan twice).

Flexible — can also track counts of each element.

Cons:
Requires extra space O(n).

Hash map worst-case degradation possible (rare in practice).

Slightly more memory overhead than sorting-based method.

Hashing might be slower for extremely large datasets compared to sorting in some cases.

Not ideal if memory is very constrained.

Interview Tip:
If interviewer says “array is sorted” → go for sorting + adjacent comparison (O(1) space).
If array is unsorted and we can use extra space → hash map / set method is fastest.
If interviewer is testing space optimization, mention the sorting method as a trade-off.

5 Interview Questions & Answers
Q1: Why use a hash map instead of sorting?
A1: Sorting is O(n log n), while a hash map allows O(n) average time detection without changing the original order.

Q2: What happens if the hash function is poor?
A2: Poor hashing can cause collisions, degrading performance to O(n²) in the worst case, but this is rare with good default implementations.

Q3: How do you handle duplicates in a stream of data (no full array)?
A3: Use a hash set to store seen elements as data arrives — this works even for streaming inputs.

Q4: Can we solve this without extra space?
A4: Yes, by sorting first and then checking adjacent elements. This reduces space to O(1) but increases time to O(n log n).

Q5: What’s the difference between using unordered_map and unordered_set here?
A5: unordered_set stores only keys (no counts), which is enough for duplicate detection, while unordered_map can also store and track frequencies.
 
 */