
// Q .. 
// 1 Two Sum 

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

// function protoype
void mergeSortedArray(vector<int>& nums1, vector<int>& nums2 , int m, int n);
void printArray(vector<int>& nums1);


int main() {

    int m=6, n=2;
    vector<int> nums1(m);     vector<int> nums2; 
    nums1 = {2, 4, 0 , 0 ,0 , 0};
    nums2 = {1, 5, 6, 8};
    // cout << nums1.size() << endl;
    // cout << nums2.size();
    
    mergeSortedArray(nums1, nums2, m , n);
    printArray(nums1);
    return 0;
}


// function definition
void mergeSortedArray(vector<int>& nums1, vector<int>& nums2 , int m, int n) 
{
    int n1_total = m-1;    int n2 = nums2.size();
    int n1_part = n ;
    
    // cout << "n1_part : " << n1_part << " & n1_total : " << m <<endl;
    // cout<< nums1[5] << " 5th" << endl;

    // for(auto e : nums1) 
    //     n1_part++;

    int r1=n1_part-1, r2=n2-1; 
 
    while(r1>=0 && r2>=0) {
        if(nums1[r1] > nums2[r2]) {        // imp
            nums1[ n1_total ] = nums1[r1];
            r1--;
        }
        else {
            nums1[n1_total] = nums2[r2];
            r2--;
        }
        cout << nums1[n1_total] << endl;
        n1_total--;
    }

     while(r1>=0 ) {
            nums1[n1_total] = nums1[r1];
            cout << nums1[n1_total] << endl;
            r1--;
            n1_total--;
            
    }


    while(r2 >= 0 ) {
        nums1[n1_total] = nums2[r2];
        cout << nums1[n1_total] << endl;
        r2--;
        n1_total--;
    }

}


void printArray(vector<int>& nums1) {

    cout << "Merge sorted elts :: " << endl;
    for(auto e : nums1) {
        cout << e << " " ;
    }
}