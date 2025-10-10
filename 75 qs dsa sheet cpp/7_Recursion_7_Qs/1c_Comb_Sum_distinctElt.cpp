
// comb sum 
// using only distinct elt from arr ... 
// $$$$ so, use SET first .. to get distinct elts ...
// then, get distinct comb sum


#include <iostream>    // For input/output operations (cout, cin, endl)
#include <vector>      // For std::vector
#include <algorithm>   // For std::sort, std::unique
#include <set>         // To easily get unique elements

// Using the standard namespace to avoid std:: prefix
using namespace std;

// Function to find unique combinations that sum up to the target,
// where each distinct number (value) from the input array can be used at most once.
// Parameters:
//   startIndex: The starting index for the current level of recursion.
//   candidates: The array of unique candidate numbers (already sorted).
//   targetSum: The overall target sum we are trying to achieve.
//   currentSum: The sum accumulated in the 'currentCombination' for the current path.
//   currentCombination: The vector representing the combination being built.
//   allCombinations: The final list of all valid and unique combinations found.
void findCombinationsWithUniqueValues(int startIndex, const vector<int>& candidates, int targetSum,
                                      int currentSum, vector<int>& currentCombination,
                                      vector<vector<int>>& allCombinations);

int main() {
    vector<int> original_nums = {4, 1, 3, 3, 5, 6, 2}; // Original input with duplicates
    int target = 7;

    // --- Step 1: Get unique values from the input array ---
    // Using a set to automatically handle uniqueness and sorting
    set<int> unique_set(original_nums.begin(), original_nums.end());

    // Convert the set back to a vector. It will be sorted and contain only unique values.
    vector<int> unique_candidates(unique_set.begin(), unique_set.end());
    // After this, unique_candidates will be: {1, 2, 3, 4, 5, 6}

    vector<vector<int>> allCombinations; // Stores all valid and unique combinations
    vector<int> tempCombination;         // Stores the combination being built

    // Start the backtracking process
    findCombinationsWithUniqueValues(0, unique_candidates, target,
                                     0, tempCombination, allCombinations);

    // Print the results
    if (allCombinations.empty()) {
        cout << "No unique combinations found for target " << target << "." << endl;
    } else {
        cout << "Unique combinations for target " << target << " (using each distinct value at most once):" << endl;
        for (const auto& combo : allCombinations) {
            cout << "[ ";
            for (int val : combo) {
                cout << val << " ";
            }
            cout << "]" << endl;
        }
    }

    return 0;
}

// Function Definition
void findCombinationsWithUniqueValues(int startIndex, const vector<int>& candidates, int targetSum,
                                      int currentSum, vector<int>& currentCombination,
                                      vector<vector<int>>& allCombinations) {

    // --- Base Case 1: Target Sum Achieved ---
    if (currentSum == targetSum) {
        allCombinations.push_back(currentCombination);
        return;
    }

    // --- Base Case 2: Invalid Path ---
    if (currentSum > targetSum || startIndex >= candidates.size()) {
        return;
    }

    // --- Recursive Step (Explore Possibilities) ---
    for (int i = startIndex; i < candidates.size(); ++i) {
        // Pruning Optimization (effective because 'candidates' is sorted):
        // If adding the current number would exceed the target, stop exploring this branch.
        if (currentSum + candidates[i] > targetSum) {
            break;
        }

        // --- 1. Choose ---
        currentCombination.push_back(candidates[i]);
        currentSum += candidates[i];

        // --- 2. Explore ---
        // Pass 'i + 1' as the new startIndex. This ensures that the current number
        // (candidates[i]) is used at most once in this specific combination.
        // Since 'candidates' already contains only unique values, no further duplicate
        // handling (like `if (i > startIndex && candidates[i] == candidates[i-1]) continue;`)
        // is needed here.
        findCombinationsWithUniqueValues(i + 1, candidates, targetSum,
                                         currentSum, currentCombination, allCombinations);

        // --- 3. Un-choose (Backtrack) ---
        currentCombination.pop_back();
        currentSum -= candidates[i];
    }
}


// op---------
// Unique combinations for target 7 (using each distinct value at most once):
// [ 1 2 4 ]
// [ 1 6 ]
// [ 2 5 ]
// [ 3 4 ]