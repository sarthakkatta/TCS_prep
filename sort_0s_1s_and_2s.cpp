/*
Problem: Sort an Array of 0s, 1s and 2s
(Dutch National Flag Algorithm)

Approach:
1. Maintain three pointers:
   - low  → position for next 0
   - mid  → current element being processed
   - high → position for next 2
2. Traverse while mid <= high:
   a) If arr[mid] == 0:
      - Swap arr[mid] and arr[low]
      - Increment low and mid
   b) If arr[mid] == 1:
      - Element already in correct region
      - Increment mid
   c) If arr[mid] == 2:
      - Swap arr[mid] and arr[high]
      - Decrement high
      - Do NOT increment mid because the
        swapped element must be checked.
3. After completion:
   - All 0s are at the beginning.
   - All 1s are in the middle.
   - All 2s are at the end.
4. Print the sorted array.

Key Idea:
- Divide the array into three regions:
    [0s | 1s | Unknown | 2s]
- Process the unknown region using
  three pointers in a single traversal.

Example:
Input:
6
2 0 2 1 1 0

Output:
0 0 1 1 2 2

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

    int low = 0, mid = 0, high = n - 1;

    while(mid <= high) {
        if(arr[mid] == 0) {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
