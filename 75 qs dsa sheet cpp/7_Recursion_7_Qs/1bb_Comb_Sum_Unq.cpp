
// comb sum ...   uniq elts [each elt 1 time even same num at dft pos] .. unique comb
// $$$ for uniq elts .. sorting is needed .. vip 

#include <iostream>    // For input/output operations (cout, cin, endl)
#include <vector>      // For std::vector
#include <algorithm>   // For std::sort

// Using the standard namespace to avoid std:: prefix
using namespace std;

// Function to find unique combinations that sum up to the target,
// where each number from the input array can be used at most once.
// Parameters:
//   startIndex: The starting index for the current level of recursion. This ensures
//               we consider numbers in increasing order of their original index (after sorting)
//               and helps prevent duplicate combinations (e.g., [2,3] vs [3,2]).
//   candidates: The array of candidate numbers. It should be sorted for this algorithm.
//   targetSum: The overall target sum we are trying to achieve.
//   currentSum: The sum accumulated in the 'currentCombination' for the current path.
//   currentCombination: The vector representing the combination being built in the current recursive call.
//   allCombinations: The final list of all valid and unique combinations found.
void findUniqueCombinations(int startIndex, vector<int>& candidates, int targetSum,
                            int currentSum, vector<int>& currentCombination,
                            vector<vector<int>>& allCombinations);

int main() {
    vector<int> numbers = {4, 1, 3, 3, 5, 6, 2}; // Example input with duplicates
    int target = 7;

    // IMPORTANT: For "Combination Sum II" (unique elements, unique combinations),
    // sorting the input array is essential. It enables efficient pruning and
    // correct handling of duplicate numbers in the input.
    sort(numbers.begin(), numbers.end());
    // After sorting, 'numbers' will be: {1, 2, 3, 3, 4, 5, 6}

    vector<vector<int>> allCombinations; // Stores all valid and unique combinations
    int currentSum = 0;                  // Current sum of the combination being built
    int start_index_for_recursion = 0;   // Starting index for the initial recursive call
    vector<int> tempCombination;         // Vector to build the current combination

    // Start the backtracking process
    findUniqueCombinations(start_index_for_recursion, numbers, target,
                           currentSum, tempCombination, allCombinations);

    // Print the results
    if (allCombinations.empty()) {
        cout << "No unique combinations found for target " << target << "." << endl;
    } else {
        cout << "Unique combinations for target " << target << ":" << endl;
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
void findUniqueCombinations(int startIndex, vector<int>& candidates, int targetSum,
                            int currentSum, vector<int>& currentCombination,
                            vector<vector<int>>& allCombinations) {

    // --- Base Case 1: Target Sum Achieved ---
    // If the current sum equals the target, we've found a valid combination.
    if (currentSum == targetSum) {
        allCombinations.push_back(currentCombination); // Add the combination to results
        return; // Stop exploring this path
    }

    // --- Base Case 2: Invalid Path ---
    // If the current sum exceeds the target, or we've exhausted all candidates,
    // this path is invalid.
    if (currentSum > targetSum || startIndex >= candidates.size()) {
        return; // Stop exploring this path
    }

    // --- Recursive Step (Explore Possibilities) ---
    // Iterate through candidate numbers starting from 'startIndex'.
    // 'i' represents the index of the number we are currently considering.
    for (int i = startIndex; i < candidates.size(); ++i) {
        // --- Duplicate Handling (Crucial for Unique Combinations) ---
        // If the current number is the same as the previous number AND
        // we are not at the very first element of the current recursive level (i > startIndex),
        // then we skip this number to avoid duplicate combinations.
        // Example: For sorted {1, 2, 2, 3}, if we just processed the first '2' at index 'i-1',
        // and now 'i' points to the second '2', we skip it.
        if (i > startIndex && candidates[i] == candidates[i-1]) {
            continue; // Skip this duplicate number
        }

        // --- Pruning Optimization (Requires Sorted Array) ---
        // If adding the current number 'candidates[i]' to 'currentSum'
        // would exceed the 'targetSum', then any subsequent numbers (since sorted)
        // will also exceed the target. So, we can stop exploring this branch.
        if (currentSum + candidates[i] > targetSum) {
            break; // Exit the for loop for this branch
        }

        // --- 1. Choose ---
        // Add the current number to the combination.
        currentCombination.push_back(candidates[i]);
        // Update the current sum.
        currentSum += candidates[i];

        // --- 2. Explore ---
        // Make a recursive call:
        // - Pass 'i + 1' as the new starting index. This ensures that each number
        //   from the 'candidates' array is used at most once in a combination.
        // - Pass the updated 'currentSum' and 'currentCombination'.
        findUniqueCombinations(i + 1, candidates, targetSum,
                               currentSum, currentCombination, allCombinations);

        // --- 3. Un-choose (Backtrack) ---
        // After the recursive call returns, remove the last added number.
        // This "undoes" the choice, allowing the loop to try other options.
        currentCombination.pop_back();
        // Subtract the number's value from the sum to reset 'currentSum' for the next iteration of the loop.
        currentSum -= candidates[i];
    }
}

// Key Changes and Explanations:
// Sorting the Input Array:

// Added sort(numbers.begin(), numbers.end()); in main. This is essential for the duplicate skipping logic (if (i > startIndex && candidates[i] == candidates[i-1]) continue;) to work correctly and for the pruning optimization (if (currentSum + candidates[i] > targetSum) break;) to be effective.

// Duplicate Handling Logic:

// if (i > startIndex && candidates[i] == candidates[i-1]) continue;

// i > startIndex: This condition ensures that we only check for duplicates after we've considered the first instance of a number at the current recursion level. If i == startIndex, it's the first time we're considering candidates[startIndex] for this branch, so we should always include it.

// candidates[i] == candidates[i-1]: This checks if the current number is the same as the previous one. If both conditions are true, it means we've already processed this value (or a duplicate of it) at the current startIndex level, so we continue to the next unique number to avoid duplicate combinations.

// Pruning Optimization:

// if (currentSum + candidates[i] > targetSum) { break; }

// This line is now correctly placed. Since the candidates array is sorted, if adding the current number candidates[i] makes the sum too large, any subsequent numbers (candidates[i+1], candidates[i+2], etc.) will also be too large (or equal), so there's no need to check them. break efficiently exits the for loop.

// Recursive Call for Unique Elements:

// findUniqueCombinations(i + 1, ...): The i + 1 in the recursive call is crucial. It means that once candidates[i] is chosen for a combination, it cannot be chosen again in the subsequent recursive calls for that specific combination path. This ensures that each number from the input array is used at most once per combination.

// Meaningful Names and Comments:

// Variable names like candidates, targetSum, currentCombination, allCombinations, and startIndex are used for better clarity.

// Extensive comments explain the purpose of each section, base cases, the "Choose, Explore, Un-choose" backtracking pattern, and the specific logic for duplicate handling and pruning.

// This corrected code provides a professional and efficient solution for the "Combination Sum II" problem.