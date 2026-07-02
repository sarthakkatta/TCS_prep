/*
Problem: Find the Complement of a Number

Approach:
1. Count the number of bits required to
   represent the given number.
2. Create a mask containing all 1's
   for those bit positions.
   Example:
      n = 5 (101)
      bits = 3
      mask = 111 (7)
3. Perform XOR of n with the mask:
      complement = n ^ mask
4. XOR flips every bit:
      101
   XOR111
      ---
      010
5. Print the complement.

Key Idea:
- A mask of all 1's ensures only the
  significant bits of the number are flipped.

Example:
Input:
5

Binary:
5 = 101
Mask = 111

101 ^ 111 = 010 = 2

Output:
2

Time Complexity: O(log N)
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int temp = n;
    int bits = 0;

    while(temp > 0) {
        bits++;
        temp /= 2;
    }

    int mask = (1 << bits) - 1;

    cout << (n ^ mask);

    return 0;
}
