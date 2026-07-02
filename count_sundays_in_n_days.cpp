/*
Problem: Count Sundays in the Next N Days

Approach:
1. Convert the starting day into a number:
   - sun = 0
   - mon = 1
   - tue = 2
   - wed = 3
   - thu = 4
   - fri = 5
   - sat = 6
2. Traverse all days from:
      0 to n
3. For each day:
   - Compute current weekday:
       (start + i) % 7
4. If the result is 0:
   - It is a Sunday.
   - Increment count.
5. After checking all days,
   return the total number of Sundays.

Key Idea:
- Days repeat every 7 days.
- Using modulo 7 helps determine the
  weekday for any future day.

Example:
Input:
mon
10

Days:
mon tue wed thu fri sat sun mon tue wed thu

Sundays = 1

Output:
1

Time Complexity: O(N)
Space Complexity: O(1)
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string day;
    int n;

    cin >> day;
    cin >> n;

    int start;

    if(day == "sun") start = 0;
    else if(day == "mon") start = 1;
    else if(day == "tue") start = 2;
    else if(day == "wed") start = 3;
    else if(day == "thu") start = 4;
    else if(day == "fri") start = 5;
    else start = 6;   // sat

    int count = 0;

    for(int i = 0; i <= n; i++) {
        if((start + i) % 7 == 0)
            count++;
    }

    cout << count;

    return 0;
}
