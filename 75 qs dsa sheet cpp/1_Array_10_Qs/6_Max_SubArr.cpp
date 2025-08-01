
// Q 6 .. 
// 238  .. PRODUCT OF ARRAY EXCEPT SELF 

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef pair<int , int> pi;

// function protoype
void findMaxSubArrSum(vector<int>& nums, int& maxLen, int& maxSubArrSum, vector<int>& maxSubArr);
void printArray(vector<int>& maxSubArr, int& maxLen);


int main() {

    vector<int> nums = {1, 2, -10,  6, 7, -9, 4, -2, 8}; 
    // vector<int> nums = {1, 2, -1,  3, 4, 5};     
    int n = nums.size();
    vector<int> maxSubArr(1);
    int maxSubArrSum = INT_MIN;   int maxLen = 1;

    findMaxSubArrSum( nums, maxLen, maxSubArrSum, maxSubArr);
    printArray(maxSubArr, maxLen);

    return 0;
}


// fn defntn
void findMaxSubArrSum(vector<int>& nums, int& maxLen, int& maxSubArrSum, vector<int>& maxSubArr)
{
    int n = nums.size();   int endIdx = n -1 ;
    int currSubArrSum = 0;
    int l = 0, r = 0;

    while(r <= endIdx && l <= endIdx) {
        currSubArrSum += nums[r];

        if(currSubArrSum > maxSubArrSum) {
            maxSubArrSum = currSubArrSum;
            maxSubArr[0] = maxSubArrSum;
            int ln = r-l + 1;
            maxLen = max(ln, maxLen);
        }

        if(currSubArrSum < 0) {
            currSubArrSum = 0;
            l = r+1;
        }

        r++;
    }

}


void printArray(vector<int>& maxSubArr, int& maxLen) {

    cout << "maxSubArr :: ";
    for(auto e : maxSubArr) {
        cout << e << endl;
    }

        cout << "max len :: " << maxLen  << endl;
        //cout << maxLen 
}


// op ---
//  vector<int> nums = {1, 2, -10,  6, 7, -9, 4, -2, 8}; 
// maxSubArr :: 14
// max len :: 6

