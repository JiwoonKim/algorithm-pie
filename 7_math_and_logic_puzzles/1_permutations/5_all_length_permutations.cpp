/**
 *  Given a set of elements, create all the possible sizes of permutations.
 *  (may contain duplicate chars)
 * 
 *  * Solutions:
 * 
 *    (1) backtracking
 * 
 *    (2) k-substrings of all permutations: O(n * n!) time, 
 *        -> create k-length substrings of all permutations of the string
 *        => use unordered_set to eliminate duplicate k-permutations
 * 
 *        ex. "abc"
 *             -> "abc": "A", "AB", "ABC"
 *             -> "acb": "a", "AC", "ACB"
 *             -> "bac": "B", "BA", "BAC"
 *             -> "bca": "b", "BC", "BCA"
 *             -> "cab": "C", "CA", "CAB"
 *             -> "cba": "c", "CB", "CBA"
 * 
 * 
 *  ** What I learned
 * 
 * 
 *     ** ALL possible SIZES of permutations
 *        : create all permutations of sizes (1 <= k <= n)
 * 
 *        => nP1 + nP2 + ... + nPn-1 + nPn
 * 
 *     
 * 
*/

#include <bits/stdc++.h>
using namespace std;

/**
 *  
 */
vector<unordered_set<string>> all_k_permutations(string s) {
    
}

/**
 *  (2) k-substrings of all permutations
 */
vector<unordered_set<string>> all_k_permutations(string s) {

    /** 
     *  k_permutation[i] = all possible i-length string permutations
     */ 
    vector<unordered_set<string>> permutations(s.length() + 1);
    
    // start from very first permutation order
    sort(s.begin(), s.end());

    /** create all full-length string permutations 
     *  (length == s.original lengths)
     */ 
    do {
        /** for each permutations, 
         *  cut k-lengths from beginning to create nPk permutations
         */
        for (int k = 1, n = s.length(); k <= n; k++) {
            string k_len_str = s.substr(0, k);
            
            // 
            permutations[k].insert(k_len_str);
        }
    } while (next_permutation(s.begin(), s.end()));
}