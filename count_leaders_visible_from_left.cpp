/*
Problem: Count Elements Greater Than All Previous Elements

Approach:
1. Read the array.
2. The first element is always counted:
   - count = 1
   - maxsofar = arr[0]
3. Traverse the array from left to right.
4. For each element:
   - If arr[i] > maxsofar:
       → It is greater than all previous elements.
       → Increment count.
       → Update maxsofar.
5. After traversal:
   - count contains the number of such elements.
6. Print count.

Key Idea:
- Keep track of the maximum element seen so far.
- An element contributes to the answer only if
  it is strictly greater than that maximum.

Example:
Input:
5
1 2 2 4 5

Process:
1 → count = 1
2 > 1 → count = 2
2 > 2 → No
4 > 2 → count = 3
5 > 4 → count = 4

Output:
4

Time Complexity: O(N)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int count = 1;
    int maxsofar = arr[0];

    for(int i = 1; i < n; i++) {
        if(arr[i] > maxsofar) {
            count++;
            maxsofar = arr[i];
        }
    }

    cout << count;

    return 0;
}
