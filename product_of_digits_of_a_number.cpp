/*
Problem: Product of Digits of a Number

Approach:
1. Read the input number n.
2. Special Case:
   - If n == 0:
       → Product of digits is 0.
       → Print 0 and return.
3. Initialize:
   - product = 1
4. Extract digits one by one:
   - lastDigit = n % 10
   - product *= lastDigit
   - n /= 10
5. Continue until all digits are processed.
6. Print the final product.

Key Idea:
- Use modulo (%) to get the last digit.
- Use division (/) to remove the last digit.
- Multiply all extracted digits together.

Example:
Input:
234

Process:
2 × 3 × 4 = 24

Output:
24

Time Complexity: O(log10 N)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    if(n == 0) {
        cout << 0;
        return 0;
    }

    int price = 1;

    while(n > 0) {
        int last = n % 10;

        price *= last;

        n /= 10;
    }

    cout << price;

    return 0;
}
