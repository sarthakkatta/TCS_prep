/*
Problem: Maximum Count of 'a' in Fixed-Length Blocks

Approach:
1. Read:
   - Input string str
   - Block length L
2. Divide the string into consecutive blocks
   of size L.
3. For each block:
   - Count occurrences of character 'a'.
4. Track the maximum count among all blocks.
5. Print the maximum value.

Key Idea:
- Process the string block by block.
- For every block, count how many 'a'
  characters it contains.
- The answer is the largest such count.

Example:
Input:
aaabcaaa
3

Blocks:
"aaa" → 3
"bca" → 1
"aa"  → 2

Output:
3

Time Complexity: O(N)
Space Complexity: O(1)
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    int L;

    cin >> str;
    cin >> L;

    int maxi = 0;

    for(int i = 0; i < str.length(); i += L) {
        int count = 0;

        for(int j = i; j < i + L && j < str.length(); j++) {
            if(str[j] == 'a')
                count++;
        }

        if(count > maxi)
            maxi = count;
    }

    cout << maxi;

    return 0;
}
