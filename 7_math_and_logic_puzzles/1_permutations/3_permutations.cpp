/**
 *  Given a set of unique elements, create all the possible permutations
 *  (contain duplicate elements)
 * 
 *  * Solutions:
 * 
 *    (1) brute-force: O( N * N! ) time and O(n) extra space
 *        -> use STL next_permutations to iterate over all permutations
 * 
 *    (2) backtracking: O( N * N! ) time and O(n) extra space
 *        
 *        (2-a) use swap + backtracking to create all permutations
 *              -> swap n element w/ (n-1) elements
 *              -> repeat recursively until done
 *              -> backtrack back to previous step and move to next element
 *              => swap values in N-for-N loops (using recursion)
 *              (building one permutation = swap n times; O(n),
 *               total of permutation: N!)
 * 
 *        (2-b) recursively build up to k-length permutations
 *              -> same as (7(1)-4. nPk permutations) problem solution
 *                 where (k == total number of elements; nPn)
 *              (building one permutation = "" -> n length; O(n),
 *               total of permutation: N!)
 * 
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
 *     ** BACKTRACKING
 *        : an algorithm for finding all solutions by EXPLORING ALL POTENTIAL CANDIDATES 
 *          -> if the candidate turns to be NOT A SOLUTION (or at least not the last one), 
 *             DISCARD it by making some CHANGES on the PREVIOUS STEP
 *        => BACKTRACK to PREVIOUS STEP and TRY OTHER CANDIDATE
 * 
 * 
 *     * use backtracking to create permutations
 *       (using swap and backtracking)
 * 
 *       (1) for each place (start ~ last) in vector,
 *       (2) swap with each other place (start + 1 ~ last) in vector and recurse to (1) w/ start + 1
 *       (3) if recursion over, backtrack to previous state by swapping back
 * 
 *       ex. ABC -> (start: 1, i: 1) => ABC -> (start: 2, i: 2) => ABC -> (start: 3, i: 3) => [ ABC ]
 *                                          -> (start: 2, i: 3) => ACB -> (start: 3, i: 3) => [ ACB ]
 * 
 *               -> (start: 1, i: 2) => BAC -> (start: 2, i: 2) => BAC -> (start: 3. i: 3) => [ BAC ]
 *                                          -> (start: 2, i: 3) => BCA -> (start: 3, i: 3) => [ BCA ]
 * 
 *               -> (start: 1, i: 3) => CBA -> (start: 2, i: 2) => CBA -> (start: 3. i: 3) => [ CBA ]
 *                                          -> (start: 2, i: 3) => CAB -> (start: 3, i: 3) => [ CAB ]
 * 
 *     ** DUPLICATE elements
 *        - if all elements are NOT unique, duplicate permutations exists
 *          -> need to ELIMINATE duplicate permutation
 * 
 *        => (N! / a! b!)
 *           - if there are (a) number of duplicates of one element
 *             and (b) number of duplicates of one element,
 *             -> divide the total number of permutations by (a!) and (b!)
 * 
 *        => take advantage of using UNORDERED_SETS to eliminate duplicates
 *           or use next_permutation (which functionality itself does NOT create duplicate permutations)
 * 
*/
#include <bits/stdc++.h>
using namespace std;

/**
 *  (1) brute-force
 */
vector<vector<int>> permute(vector<int> v) {

    // create space to store permutations
    vector<vector<int>> permutations;

    // make sure to start from very first permutation
    sort(v.begin(), v.end());

    // create all permutations possible
    do {
        permutations.push_back(v);
    } while (next_permutation(v.begin(), v.end()));

    // return collection
    return permutations;
}

/**
 *  (2-a) use swap and backtracking
 */
vector<vector<int>> permute(vector<int>& nums) {

    // create space to store all permutations
    vector<vector<int>> permutations;
        
    /** use exhaustive search (backtracking)
     *  to create all permutations
     */ 
    go_back(nums, 0, nums.size(), permutations);
        
    return permutations;
}

/** helper function
 *  : use swap and backtracking to create all permutations
 */     
void go_back(vector<int>& nums, int start, int end, vector<vector<int>>& permutations) {
        
    /** BASE case
     *  : if no more elements to swap (= finished creating permutation)
     *    -> insert result into collection of permutations
     */ 
    if (start == end) {
        permutations.push_back(nums);
    }

    /** RECURSIVE case
     *  : swap start value w/ each value in range (start ~ last)
     *    -> repeat on range (start + 1 ~ last)
     *    backtrack back to original to try next cases
     */ 
    for (int i = start; i < end; i++) {
        // swap
        swap(nums[start], nums[i]);

        // call recursion
        go_back(nums, start + 1, end, permutations);

        // backtrack
        swap(nums[start], nums[i]);
    }
}

/**
 *  (2-b) build up permutation lengths
 */
vector<vector<int>> permute(vector<int>& nums) {

    // create space to store permutations
    vector<vector<int>> permutations;

    // initialize all available numbers
    unordered_map<int, bool> available;
    for (int num : nums) {
        available[num] = true;
    }

    // use backtracking to create permutations
    vector<int> empty;
    go_back(nums.size(), empty, available, permutations);

    return permutations;
}

/** helper function
 *  : recursively build up k-length permutations
 */ 
void go_back(int n, vector<int> prefix, unordered_map<int, bool> available, vector<vector<int>> permutations) {

    /** BASE case
     *  : if prefix's length == number of elements (used all elements)
     *    -> finished creating a permutation
     */ 
    if (prefix.size() == n) {
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
            go_back(n, prefix, available, permutations);

            // backtrack
            prefix.pop_back();
            available[key] = true;
        }
    }
}