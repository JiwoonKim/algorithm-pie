/**
 *  Given a string s, update to next permutation.
 * 
 *  * Solutions:
 * 
 *    (1) swap and sort: O(n) time, O(1) space
 *        -> next permutaton = change (ascending order -> descending order)
 *           -> find rightmost value satisfying ascending order
 *           -> find next value to swap that with
 *           -> sort the rest right side in ascending order
 * 
 *    (2) use STL next permutation: O(n) time, O(1) space
 * 
 * 
 *  ** What I learned
 * 
 *     * PERMUTATION
 *       : a way elements are ordered
 * 
 * 
 *     ** NEXT_PERMUTATION function
 *        = increasingly changing order from ascending to descending order (ascending -> descending 바꿔나가기)
 *          (cf. prev_permutation = descending -> ascending 바꾸기)
 * 
 *        (1) find SWAP POINT
 *            -> find RIGHTMOST value (i-1) index that is a[i-1] < a[i] 
 *               (가정: permutation progressing in ascending order)
 *  
 *        (2) find SMALLEST value that is LARGER than SWAP POINT's value in range (i ~ end)
 *        (3) SWAP the two values
 *        (4) SORT the rightside of swap point in ascending order
 * 
 *        ex. 723|6541 -> 3: swap point
 *                    -> 4: other wap point
 *            -> swapped: 7246531
 *            -> sorted right side: 724|1356
 *            => next permutation = 7241356
 * 
 *        => returns BOOL value: check is next permutation exists and updates to that
 * 
*/

#include <bits/stdc++.h>
using namespace std;

/** 
 *  (1) swap and sort
 */
bool nextPermutation(string& s) {

    int last = s.length() - 1;

    // find rightmost char satisfying ascending order
    int swapPoint = last;
    for (int i = last; i > 0; i--) {
        if (s[i] > s[i-1]) {
            swapPoint = i - 1;
            break;
        }
    }

    /** if rightmost char is last char, no next permutation
     *  (bcuz current state already is the last permutation)
     */ 
    if (swapPoint == last) return false;

    /** next, find char next in order to swap with
     *  -> on the right side of swapPoint,
     *     find smallest value that is larger than swapPoint's value
     */ 
    int otherPoint = swapPoint + 1;
    for (int i = swapPoint + 1; i <= last; i++) {
        if (s[i] > s[swapPoint] && s[i] < s[otherPoint]) {
            otherPoint= i;
        }
    }

    /** swap two values
     *  -> updating to next permutation order (start ~ lastIndex)
     */ 
    swap(s[swapPoint], s[otherPoint]);

    /** reorder the rest in ascending order
     *  => update rest part (lastIndex + 1 ~ end)
     */ 
    sort(s.begin() + swapPoint + 1, s.end());
    return true;
}

/** 
 *  (2) use STL next_permutation
 */
next_permutation(s.begin(), s.end());