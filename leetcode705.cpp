/*
Problem: LeetCode 705 – Design HashSet

Approach:
1. Use a boolean array (vector<bool>) of size 1,000,001.
2. Index represents the key itself.
3. Operations:
   - add(key):
       Mark mp[key] as true.
   - remove(key):
       Mark mp[key] as false.
   - contains(key):
       Return mp[key].
4. Since keys are in range [0, 10^6]:
   - Direct indexing is possible.
   - No hashing function is required.

Key Idea:
- Use direct address table technique.
- Each key maps directly to an index in the array.

Time Complexity:
- add()      : O(1)
- remove()   : O(1)
- contains() : O(1)

Space Complexity: O(10^6)
*/

class MyHashSet {
public:
    vector<bool> mp;

    MyHashSet() {
        mp.resize(1000001, false);
    }

    void add(int key) {
        mp[key] = true;
    }

    void remove(int key) {
        mp[key] = false;
    }

    bool contains(int key) {
        return mp[key];
    }
};
