
// Subsets 
// Leetcode 78 ... 


#include <iostream>    // For input/output operations (cout, cin, endl)
#include <vector>      // For std::vector
#include <algorithm>   // For std::sort (though not strictly needed for correctness here,
                       // it's good practice if you later need unique subsets from duplicates)

using namespace std; // Using the standard namespace

// Function to find all subsets of a given array using backtracking.
// Parameters:
//   startIndex: The index from which to start considering elements in the current recursive call.
//               This helps avoid duplicate subsets and ensures correct ordering.
//   nums: The input array of numbers. Passed by reference to avoid copying.
//   currentSubset: The subset being built in the current recursive path. Passed by reference.
//   allSubsets: The final list of all generated subsets. Passed by reference.
void findAllSubsets(int startIndex, const vector<int>& nums,
                    vector<int>& currentSubset, vector<vector<int>>& allSubsets);

// --- Main Function ---
int main() {
    vector<int> numbers = {1, 2, 3}; // Example input array
    int n = numbers.size();          // Size of the input array

    vector<vector<int>> allSubsets; // This will store all the generated subsets
    vector<int> currentSubset;      // This temporary vector holds the subset being built

    // Initial call to start the backtracking process.
    // We start from index 0 and with an empty currentSubset.
    findAllSubsets(0, numbers, currentSubset, allSubsets);

    cout << "Total Subsets: " << allSubsets.size() << endl;
    cout << "All Subsets:" << endl;

    // Iterate through the list of all subsets and print each one.
    for (const auto& subset : allSubsets) {
        cout << "[ "; // Start with a bracket for clarity
        for (int element : subset) {
            cout << element << " "; // Print each element
        }
        cout << "]" << endl; // End with a bracket and newline
    }

    return 0; // Indicate successful program execution
}

// --- Function Definition ---
void findAllSubsets(int startIndex, const vector<int>& nums,
                    vector<int>& currentSubset, vector<vector<int>>& allSubsets) {
    
    // --- 1. Record Current State (Base Case for Subsets) ---
    // At every step of the recursion, the 'currentSubset' represents a valid subset.
    // This includes the empty set (at the very first call) and all intermediate combinations.
    allSubsets.push_back(currentSubset);

    // --- 2. Explore Choices ---
    // Iterate from the 'startIndex' to the end of the 'nums' array.
    // This ensures that elements are considered in order and prevents duplicate subsets
    // (e.g., [1,2] and [2,1] are considered the same subset).
    for (int i = startIndex; i < nums.size(); ++i) {
        // --- Choose: Include the current element ---
        currentSubset.push_back(nums[i]);

        // --- Explore: Make a recursive call ---
        // Recursively call the function to find subsets starting from the next element (i + 1).
        // This means 'nums[i]' has been chosen, and now we look for elements after it.
        findAllSubsets(i + 1, nums, currentSubset, allSubsets);

        // --- Un-choose (Backtrack): Remove the current element ---
        // After the recursive call returns, remove the last added element from 'currentSubset'.
        // This "undoes" the choice, allowing the loop to try other elements for the current level.
        currentSubset.pop_back();
    }
}


/*  tc and sc **************
Time Complexity (TC): 
TC => O(N * 2^N)

There are 2N possible subsets for an array of size N.
For each subset, it takes O(N) time in the worst case to copy it into the allSubsets result vector (e.g., when adding a subset of size N).
Each element is pushed/popped at most once per path, and there are 2N paths.


Space Complexity (SC): ***
SC => O(N) for recursion stack + O(N * 2^N) for storing results

O(N) for the maximum depth of the recursion stack (equal to the length of the input array).
O(N * 2^N) for storing all the subsets in the allSubsets vector (each of the 2N subsets can have up to N elements).

*/



// Explanation of Corrections and Logic
// Simplified Function Signature:

// Removed n (can be obtained from nums.size()).

// Removed curr_sum (not relevant for the Subsets problem itself, which is about combinations, not sums).

// Removed vis (not needed for this type of subset generation; the startIndex parameter handles uniqueness of combinations).

// Placement of allSubsets.push_back(currentSubset):

// In the corrected code, allSubsets.push_back(currentSubset); is the first line inside findAllSubsets. This is crucial because:

// It immediately adds the empty set [] when the function is first called with an empty currentSubset.

// It captures every intermediate state of currentSubset as a valid subset. For example, if nums = {1, 2, 3}:

// Initial call: [] is added.

// After 1 is chosen: [1] is passed, [1] is added.

// After 2 is chosen (from [1]'s branch): [1,2] is passed, [1,2] is added.

// And so on.

// The for Loop and startIndex:

// The for (int i = startIndex; i < nums.size(); ++i) loop is the heart of the backtracking.

// startIndex ensures that in each recursive call, you only consider elements from that index onwards. This prevents generating duplicate subsets like [1,2] and [2,1] because 2 will only be considered after 1 if 1 was picked first.

// When nums[i] is chosen, the recursive call findAllSubsets(i + 1, ...) ensures that for the next element in the subset, we only look at numbers after nums[i]. This is how we build subsets without repeating elements within a single subset (e.g., [1,1] is not generated unless the problem explicitly allows it and the input has duplicates).

// "Choose, Explore, Un-choose" Pattern:

// Choose: currentSubset.push_back(nums[i]); (Add the element nums[i] to the current path).

// Explore: findAllSubsets(i + 1, nums, currentSubset, allSubsets); (Recursively call to find subsets with nums[i] included, starting from the next element).

// Un-choose (Backtrack): currentSubset.pop_back(); (Remove nums[i] from currentSubset to "undo" the choice, allowing the loop to try the next element at the current level without nums[i] in the path).










// ques *************************

// what is diff btw subset code that we solved , with for loop and witthout for loop.

// from next time, when u give code, plz add tc and sc of both and explain in few lines it.



// The two approaches for generating subsets (with a for loop and without a for loop, often called "take/not take") are both valid backtracking strategies, but they differ in their structure and how they manage the state of the recursion.

// 1. Subset Generation with a for loop (Iterative Backtracking)
// This method iterates through the remaining elements at each step of the recursion.

// How it works:

// The for loop iterates from startIndex to the end of the array.

// In each iteration i, it chooses nums[i], adds it to the currentSubset, and then makes a recursive call to findAllSubsets(i + 1, ...). This means it explores all subsets that include nums[i] and subsequent elements.

// After the recursive call returns, it un-chooses nums[i] (backtracks) by removing it from currentSubset, allowing the loop to try the next element nums[i+1] at the current level.

// The empty set and all subsets are captured by adding currentSubset to allSubsets at the very beginning of the function.

// Code Structure (Conceptual):

// C++

// void findAllSubsets(int startIndex, const vector<int>& nums, vector<int>& currentSubset, vector<vector<int>>& allSubsets) {
//     allSubsets.push_back(currentSubset); // Add current state as a subset

//     for (int i = startIndex; i < nums.size(); ++i) {
//         currentSubset.push_back(nums[i]); // Choose
//         findAllSubsets(i + 1, nums, currentSubset, allSubsets); // Explore
//         currentSubset.pop_back(); // Un-choose (Backtrack)
//     }
// }
// Time Complexity (TC): O(N * 2^N)

// There are 2 
// N
//   possible subsets for an array of size N.

// For each subset, it takes O(N) time in the worst case to copy it into the allSubsets result vector (e.g., when adding a subset of size N).

// Each element is pushed/popped at most once per path, and there are 2 
// N
//   paths.

// Space Complexity (SC): O(N) for recursion stack + O(N * 2^N) for storing results

// O(N) for the maximum depth of the recursion stack (equal to the length of the input array).

// O(N * 2^N) for storing all the subsets in the allSubsets vector (each of the 2 
// N
//   subsets can have up to N elements).

// 2. Subset Generation without a for loop ("Take/Not Take" or "Include/Exclude")
// This method makes a binary decision for each element: either include it or exclude it.

// How it works:

// The recursive function focuses on a single element at startIndex.

// Base Case: If startIndex reaches the end of the array, it means a complete decision has been made for all elements, so the currentSubset is added to allSubsets, and the recursion stops for that path.

// "Take" Branch: It adds nums[startIndex] to currentSubset and makes a recursive call for startIndex + 1.

// "Not Take" Branch: It then backtracks (removes nums[startIndex]) and makes another recursive call for startIndex + 1 without nums[startIndex] in the currentSubset.

// Code Structure (Conceptual):

// C++

// void findAllSubsetsWithoutLoop(int startIndex, const vector<int>& nums, vector<int>& currentSubset, vector<vector<int>>& allSubsets) {
//     // Base case: All elements considered, add the current subset
//     if (startIndex >= nums.size()) {
//         allSubsets.push_back(currentSubset);
//         return;
//     }

//     // 1. Take (Include) the current element
//     currentSubset.push_back(nums[startIndex]);
//     findAllSubsetsWithoutLoop(startIndex + 1, nums, currentSubset, allSubsets);
//     currentSubset.pop_back(); // Backtrack

//     // 2. Not Take (Exclude) the current element
//     findAllSubsetsWithoutLoop(startIndex + 1, nums, currentSubset, allSubsets);
// }
// Time Complexity (TC): O(N * 2^N)

// Similar to the for loop approach, there are 2 
// N
//   recursive calls (representing each subset).

// Each call involves constant time operations (push, pop, index increment) plus the time to copy the currentSubset to allSubsets in the base case, which is O(N).

// Space Complexity (SC): O(N) for recursion stack + O(N * 2^N) for storing results

// O(N) for the maximum depth of the recursion stack.

// O(N * 2^N) for storing all the subsets in the allSubsets vector.

// Key Differences Summarized
// Feature	for loop (Iterative Backtracking)	Without for loop ("Take/Not Take")
// Recursion Flow	One recursive call per iteration; loop handles choices.	Two recursive calls per step (one for "take," one for "not take").
// Subset Capture	allSubsets.push_back(currentSubset) is typically at the start of the function.	allSubsets.push_back(currentSubset) is typically in the base case (when startIndex == nums.size()).
// Intuition	"Pick an element, then find subsets from remaining elements."	"For each element, either include it or don't include it."
// Common Use	Often preferred for problems where you need to pick a sequence of elements or manage a starting index for combinations.	Often preferred for problems where each item has a clear binary choice (e.g., knapsack, subsets).
// Complexity	Both TC and SC are asymptotically the same.	Both TC and SC are asymptotically the same.

// Export to Sheets
// While both methods achieve the same asymptotic complexity, the "take/not take" approach can sometimes feel more intuitive for beginners learning recursion for subsets because it clearly separates the two binary choices for each element. The for loop approach is more general for combination problems where you need to pick elements from a range.



/*
Total Subsets: 8
All Subsets:
[ ]
[ 1 ]
[ 1 2 ]
[ 1 2 3 ]
[ 1 3 ]
[ 2 ]
[ 2 3 ]
[ 3 ]


*/


