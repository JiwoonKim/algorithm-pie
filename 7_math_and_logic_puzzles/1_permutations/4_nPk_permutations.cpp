/**
 *  Given a set of unique elements and a number k, 
 *  create all the possible k-sized permutations.
 *  (repetition is not allowed; if one element was already used, cannot use in same permutation)
 * 
 *  * Solutions:
 * 
 *    (1) BACKTRACKING: O( k * nPk ) time and O(n) extra space
 *        -> recursively build up to k-length permutations
 *           (building one permutation = "" -> k length; O(k),
 *            total of permutation: nPk)
 * 
 *    (2) cut to k-length subvector of all permutations: O( N^2 * N! ) time and O(nPk) extra space
 *        (creating all permutations: O(N * N!),
 *         cut each permuations to subvector: O(N) )
 * 
 *  ** What I learned
 * 
 *     ** K-sized Permutations (= nPk)
 *        : create all possible k-sized permutations
 *          -> use only k number elements of elements from set to create permutations
 * 
 *        => (N! / (N-K)!)
 *            = n * (n-1) * (n-2) * ... * (n-k+1) cases
 * 
 *            ex. 4P4 = 4 * 3 * 2 * 1 ; if (k==n) => create all permutations
 *                4P3 = 4 * 3 * 2
 *                4P2 = 4 * 3
 *                4P1 = 4
 * 
 * 
 *     ** how to use BACKTRACKING
 *        (to recursively build up to k-length permutations)
 * 
 *        (1) 
 * 
 *        ex. ([], [a b c]) where k = 2
 *                          -> (A, [b c]) -> (AB, [c]) => AB
 *                                        -> (AC, [b]) => AC
 *                          -> (B, [a c]) -> (BA, [c]) => BA
 *                                        -> (BC, [a]) => BC
 *                          -> (C, [a b]) -> (CA, [b]) => CA
 *                                        -> (CB, [a]) => CB
 * 
 *     cf) cut to k-length subvector of all permutations
 *         -> create all permutations (n-length; nPn) using STL next_permutation: O(N * N!) time
 *         -> cut each permutations from (first ~ kth): * O(n)
 *         -> insert that subvector into unordered_set to make sure duplicates don't exist
 * 
 *         ex. abc
 *             -> abc: AB
 *             -> acb: AC
 *             -> bac: BA
 *             -> bca: BC
 *             -> cab: CA
 *             -> cba: CB
 * 
 *        -> inefficient in both time and space
 *        => use backtracking method instead
 * 
*/
#include <bits/stdc++.h>
using namespace std;

/** (1) backtracking
 *      -> build up permutation to length k
 */
vector<vector<int>> permute(vector<int>& nums, int k) {

    // create space to store permutations
    vector<vector<int>> permutations;

    // initialize all available numbers
    unordered_map<int, bool> available;
    for (int num : nums) {
        available[num] = true;
    }

    // use backtracking to create permutations
    vector<int> empty;
    go_back(k, empty, available, permutations);

    return permutations;
}

/** helper function
 *  : recursively build up k-length permutations
 */ 
void go_back(int k, vector<int> prefix, unordered_map<int, bool> available, vector<vector<int>> permutations) {

    /** BASE case
     *  : if prefix's length == number of elements (used all elements)
     *    -> finished creating a permutation
     */ 
    if (prefix.size() == k) {
        permutations.push_back(prefix);
    }

    /** RECURSIVE case
     *  : append each available element to prefix
     *    and call recursion on it (until prefix == permutation)
     *    backtrack to original prefix for next element
     */ 
    for (auto pair : available) {
        int key = pair.first;
        if (available[key]) {
            /** append available element to prefix
             *  and mark that element inavailable
             */ 
            prefix.push_back(key);
            available[key] = false;

            // call recursion
            go_back(k, prefix, available, permutations);

            // backtrack
            prefix.pop_back();
            available[key] = true;
        }
    }
}