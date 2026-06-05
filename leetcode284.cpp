/*
Problem: LeetCode 284 – Peeking Iterator

Approach:
1. Extend the given Iterator class.
2. Maintain:
   - nxt      → stores next element in advance.
   - has_next → indicates whether a next element exists.
3. Constructor:
   - Check if iterator has elements.
   - If yes, preload the first element into nxt.
4. peek():
   - Return nxt without moving iterator.
5. next():
   - Store current nxt as answer.
   - Advance iterator and preload next element.
   - Return stored value.
6. hasNext():
   - Return has_next flag.

Key Idea:
- Always keep one element preloaded so that
  peek() can return it without advancing iterator.

Time Complexity:
- peek()    : O(1)
- next()    : O(1)
- hasNext() : O(1)

Space Complexity: O(1)
*/

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 * 		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
private:
    int nxt;
    bool has_next;

public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        has_next = Iterator::hasNext();

        if (has_next) {
            nxt = Iterator::next();
        }
    }

    int peek() {
        return nxt;
    }

    int next() {
        int val = nxt;

        has_next = Iterator::hasNext();
        if (has_next) {
            nxt = Iterator::next();
        }

        return val;
    }

    bool hasNext() const {
        return has_next;
    }
};
