/**
 *  Given a set of elements, create all the possible permutations
 *  (contain duplicate elements)
 * 
 *  * Solutions:
 * 
 *    (1) brute-force: O( N * N! ) time and O(1) extra space
 *        -> use STL next_permutations to iterate over all permutations
 * 
 *    (2) backtracking: O( N * N! ) time and O(1) extra space
 *        -> 
 * 
 *  ** What I learned
 * 
 *     * PERMUTATION
 *       : creating order using the given elements
 *         -> if given n elements to create permutation,
 *            in general, it means to USE ALL ELEMENTS to create permutations
 * 
 *       => total of N! (factorial cases)
 *          -> takes O(N!) time (and extra space if storing)
 * 
 * 
 *     ** DUPLICATE elements
 *        - if all elements are NOT unique, there can be duplicate permutations
 *          -> need to eliminate duplicates
 * 
 *        => total of (N! / a! b!)
 *           - if there are (a) number of duplicates of one element
 *             and (b) number of duplicates of one element,
 *             -> divide the total number of permutations by (a!) and (b!)
 * 
 *        => take advantage of using UNORDERED_SETS to eliminate duplicates
 *           or use next_permutation (which functionality itself does not create duplicate permutations)
 * 
 * 
 *     * NEXT_PERMUTATION function
 *       = increasingly changing order from ascending to descending order (ascending -> descending 바꿔나가기)
 *         (cf. prev_permutation = descending -> ascending 바꾸기)
 * 
 *       -> returns BOOL value: check is next permutation exists and updates to that
 * 
 *       (1) find SWAP POINT
 *           -> find RIGHTMOST value (i-1) index that is a[i-1] < a[i] 
 *              (가정: permutation progressing in ascending order)
 * 
 *       (2) find SMALLEST value that is LARGER than SWAP POINT's value in range (i ~ end)
 *       (3) SWAP the two values
 *       (4) REARRANGE the rightside of swap point in ascending order (sort)
 * 
 * 
 *     ** BACKTRACKING
 *        : an algorithm for finding all solutions by EXPLORING ALL POTENTIAL CANDIDATES 
 *          -> if the candidate turns to be NOT A SOLUTION (or at least not the last one), 
 *             DISCARD it by making some CHANGES on the PREVIOUS STEP
 * 
 *        => BACKTRACK to PREVIOUS STEP and TRY OTHER CANDIDATE
 * 
*/

#include <bits/stdc++.h>
using namespace std;

/**
 *  (1) brute-force
 */
vector<string> permute(string s) {

    /** use set to filter out duplicate permutations
     *  (if all chars in given input string are unique,
     *   can use simply vector to store permutations instead)
     */ 
    vector<string> permutations;

    // make sure to start from very first permutation version
    sort(s.begin(), s.end());

    // create all permutations possible
    do {
        permutations.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    // return collection of all permutations
    return permutations;
}

/** helper function
 *  : custom next_permutation function (-> idential to STL one)
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
 *  (2) backtracking
 */
vector<string> permute(string s) {

}