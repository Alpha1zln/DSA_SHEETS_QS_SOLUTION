

// 2 - Reverse Bits ... 32 bits no.
// Leetcode 190


// Corrected Code (with Binary Representation)
// To test your reverseBits function with a specific binary pattern, you have a few options:

// Use a Hexadecimal Literal: This is the most common way to represent specific bit patterns in C++. Each hexadecimal digit corresponds to 4 binary bits.

// Use an Integer Literal that Represents the Decimal Value: Convert your desired binary string to its decimal equivalent.

// Construct the uint32_t from individual bits (more verbose).

// Here's the corrected main function using a hexadecimal literal, which is the most practical way to represent a 32-bit pattern. I'll use 0x00000001 as an example, which is ...0001 in binary.

// C++

#include <iostream> // For std::cout, std::endl
#include <cstdint>  // For uint32_t (ensures 32-bit unsigned integer)

// Using the standard namespace
using namespace std;

// Function prototype
uint32_t reverseBits(uint32_t n); // Renamed 'vc' to 'n' for common convention

int main() {
    // Example 1: Reversing 000...0001 (decimal 1)
    // In binary: ...0000 0000 0000 0000 0000 0000 0000 0001
    // In hexadecimal: 0x00000001
    uint32_t num1 = 0x00000001; 
    uint32_t reversedNum1 = reverseBits(num1);
    // Expected output for 0x00000001: 0x80000000 (1000...0000 in binary)
    cout << "Original: " << hex << num1 << endl; // Print in hex for clarity
    cout << "Reversed: " << hex << reversedNum1 << endl; 
    cout << dec << endl; // Switch back to decimal for subsequent outputs

    // Example 2: Reversing 000...1110 (decimal 14)
    // In binary: ...0000 0000 0000 0000 0000 0000 0000 1110
    // In hexadecimal: 0x0000000E
    uint32_t num2 = 0x0000000E; 
    uint32_t reversedNum2 = reverseBits(num2);
    // Expected output for 0x0000000E: 0x70000000 (0111...0000 in binary)
    cout << "Original: " << hex << num2 << endl;
    cout << "Reversed: " << hex << reversedNum2 << endl;
    cout << dec << endl;

    // To test with your original intended binary pattern (000111000101)
    // Convert this binary string to hexadecimal or decimal first.
    // 0001 1100 0101 (binary) = 1 C 5 (hex)
    uint32_t num3 = 0x000001C5; 
    uint32_t reversedNum3 = reverseBits(num3);
    cout << "Original (000111000101 binary): " << hex << num3 << endl;
    cout << "Reversed: " << hex << reversedNum3 << endl;
    cout << dec << endl;

    return 0;
}

// Function definition for reversing bits
uint32_t reverseBits(uint32_t n) { // Renamed 'vc' to 'n'
    uint32_t reversed_n = 0; // Initialize the result to 0

    // Iterate 32 times, once for each bit in a 32-bit unsigned integer
    for (int i = 0; i < 32; ++i) {
        // 1. Shift the 'reversed_n' left by 1:
        // This makes space for the next bit from 'n' at the least significant position.
        // E.g., if reversed_n is 01, it becomes 010.
        reversed_n = reversed_n << 1;

        // 2. Get the least significant bit (LSB) of 'n':
        // 'n & 1' performs a bitwise AND with 1. This isolates the LSB of 'n'.
        // E.g., if n is ...101, n & 1 gives 1. If n is ...100, n & 1 gives 0.
        // Then, OR this LSB with 'reversed_n'. This places the LSB of 'n' into the
        // newly created space in 'reversed_n'.
        reversed_n = reversed_n | (n & 1);

        // 3. Shift 'n' right by 1:
        // This discards the LSB of 'n' (which we just processed) and moves the next
        // bit to the LSB position for the next iteration.
        // E.g., if n is ...101, it becomes ...10.
        n = n >> 1;
    }

    return reversed_n; // Return the fully reversed 32-bit integer
}

/*

Original: 1
Reversed: 80000000

Original: e
Reversed: 70000000

Original (000111000101 binary): 1c5
Reversed: a3800000

*/



// Time and Space Complexity
// Time Complexity (TC): O(1)

// The loop runs exactly 32 times, which is a constant number of iterations regardless of the input value (as uint32_t is fixed at 32 bits).

// Each operation inside the loop (left shift, bitwise AND, bitwise OR, right shift) takes constant time.

// Therefore, the total time complexity is constant.

// Space Complexity (SC): O(1)

// Only a few constant-size variables (reversed_n, i, n) are used.

// No additional data structures that grow with the input size are allocated.

// Therefore, the space complexity is constant.

// This algorithm is very efficient for bit reversal.


/*

Your C++ code for reversing bits (LeetCode 190) is logically correct for the bit manipulation part! The algorithm you've implemented is a standard and efficient way to reverse bits.

However, the issue lies in how you're initializing uint32_t vc = 000111000101; in your main function.

The Problem in main()
The number 000111000101 is interpreted by C++ as an octal (base-8) literal, not a binary (base-2) literal.

In C++, a number prefixed with 0 (zero) is treated as an octal number.

Octal digits can only be 0 through 7. When you have 8 or 9 in an octal literal (which you don't here, but it's a common mistake), it would be a compilation error.

Your number 000111000101 in octal translates to a different decimal value than what you might expect if you were thinking of it as a binary string.

If you intend to represent a binary sequence, you cannot directly write it like that in C++ as a number literal.
*/













// #include<iostream>
// #include<vector>
// using namespace std;

// uint32_t reverseBits(uint32_t vc) ;

// int main() {
//     //vector<int>
//     uint32_t vc = 000111000101; // {0,0,0, 1,1,0,0,1,0,1};
//     uint32_t rev = reverseBits(vc);
//     cout << "Rev Bits: " << rev;

//     return 0;
// }

// uint32_t reverseBits(uint32_t vc) {

//     uint32_t rev = 0;
//     for(int i=0; i<32; i++) {
//         rev = rev << 1;     //  0*2 = 0 
//         rev = (rev) | vc&1 ;   // 0 | 1 = 1
//         vc = vc >> 1;        // 1011 -> 101  .... vc/2
//     }

//     return rev;
// }



// 9*****************
// Your C++ code for reversing bits (LeetCode 190) is logically correct for the bit manipulation part! The algorithm you've implemented is a standard and efficient way to reverse bits.

// However, the issue lies in how you're initializing uint32_t vc = 000111000101; in your main function.

// The Problem in main()
// The number 000111000101 is interpreted by C++ as an octal (base-8) literal, not a binary (base-2) literal.

// In C++, a number prefixed with 0 (zero) is treated as an octal number.

// Octal digits can only be 0 through 7. When you have 8 or 9 in an octal literal (which you don't here, but it's a common mistake), it would be a compilation error.

// Your number 000111000101 in octal translates to a different decimal value than what you might expect if you were thinking of it as a binary string.

// If you intend to represent a binary sequence, you cannot directly write it like that in C++ as a number literal.