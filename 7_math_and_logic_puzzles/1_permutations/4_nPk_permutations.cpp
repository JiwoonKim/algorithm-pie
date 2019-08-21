/**
 *  Given a set of elements and number k, 
 *  create all the possible k-sized permutations.
 *  (may contain duplicate chars)
 * 
 *  * Solutions:
 * 
 *    (1) BACKTRACKING: O( N! ) time and O(1) of O(N!) extra space
 * 
 *    (2) use STL next_permutation(?)
 * 
 * 
 *  ** What I learned
 * 
 *     ** K-sized Permutations (= nPk)
 *        : create all possible k-sized permutations
 *          -> use only k number elements of elements from set to create permutations
 * 
 *          => 경우의 수: (N! / (N-K)!)
 *                       = n * (n-1) * (n-2) * ... * (n-k+1) cases
 * 
 *             ex. 4P4 = 4 * 3 * 2 * 1 ; if (k==n) => same as creating all permutations of string
 *                 4P3 = 4 * 3 * 2
 *                 4P2 = 4 * 3
 *                 4P1 = 4
 * 
 *     ** how to use BACKTRACKING
 *        (1)
 * 
 * 
 *     ** k-length string <-> substring, subsequence
 *        - k-length string (= permutation): REARRANGEMENT of characters
 *        - substring, subsequence: must FOLLOW char order in original string
 *          -> substring: cannot take out middle chars (ex. "abc" -> "ac" X)
 *          -> subsequence: can take out middle chars (ex. "abc" -> "ac" possible)
 * 
*/

#include <bits/stdc++.h>
using namespace std;

/**
 *  (1) backtracking
 */
vector<string> permutationsOfK(string s, int k) {

    // set default available chars
    unordered_map<char, bool> available;
    for (char c : s) {
        available.[c] = true;
    }

    /** use backtracking function to build strings up to k-length
     *  -> start from empty string ""
     */ 
    go(k, available, "");
    return permutations;
}
void go(int k, unordered_map<char, bool> available, string str_sofar) {
    /** base case
     *  : if string reached length of k 
     *    -> insert string in collection and terminate
     */ 
    if (str_sofar.length() == k) {
        permutations.push_back(str_sofar);
        return;
    }
    /** recursive case
     *  : build strings up to k-length
     *    -> append one of the available chars and recurse on it
     *       (erase that char from available collection temporarily
     *        to mark that it has already been used and cannot be reused)
     */ 
    for (auto pair : available) {
        char c = pair.first;
        if (available[c]){
            available[c] = false;
            go(k, available, str_sofar + c);
            available[c] = true;
        }
    }
}