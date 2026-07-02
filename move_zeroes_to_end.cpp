/*
Problem: Move All Zeroes to the End of the Array

Approach:
1. Maintain a pointer j:
   - Indicates the position where the next
     non-zero element should be placed.
2. Traverse the array using pointer i.
3. For each element:
   - If arr[i] is non-zero:
       → Swap arr[i] with arr[j]
       → Increment j
4. After traversal:
   - All non-zero elements are moved
     to the front in their original order.
   - All zeroes automatically shift to the end.
5. Print the modified array.

Key Idea:
- Partition the array into:
   [Non-Zero Elements | Zeroes]
- Use two pointers to perform the operation
  in-place without extra space.

Example:
Input:
5
0 1 0 3 12

Process:
j = 0
Move 1 → [1 0 0 3 12]
Move 3 → [1 3 0 0 12]
Move 12 → [1 3 12 0 0]

Output:
1 3 12 0 0

Time Complexity: O(N)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int j = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] != 0) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
    }

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
