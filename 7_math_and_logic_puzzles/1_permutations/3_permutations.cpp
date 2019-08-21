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
 *        -> use swapping to create all permutations
 *           and backtrack
 * 
 *  ** What I learned
 * 
 *     * PERMUTATION (= nPn)
 *       : creating order using the given elements
 *         -> if given n elements to create permutation,
 *            in general, it means to USE ALL ELEMENTS to create permutations
 * 
 *       => nPn = N! (factorial cases)
 *          -> takes O(n) to create each permutation
 *          => O(N * N!) time (and extra space if storing)
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
 *           or use next_permutation (which functionality itself does NOT create duplicate permutations)
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

/**
 *  (2) backtracking
 */
vector<string> permute(string s) {

}