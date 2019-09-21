/**
 *  Given a set of unique elements and integer k, 
 *  create all the possible combinations of length k. (nCk 구하기)
 *  (contain duplicate elements)
 * 
 *  * Solutions:
 * 
 * 
 *  ** What I learned
 * 
 * 
*/
#include <bits/stdc++.h>
using namespace std;

/**
 *  (1) 
 */
vector<vector<int>> combs;
vector<vector<int>> combine(vector<int> v, int k) {
    vector<int> empty;
    get(v.size(), k, 0, empty);
    return combs;
}

void get(int n, int k, int index, vector<int> prefix) {
    // if reached length k,
    if (prefix.size() == k) {
        combs.push_back(prefix);
        return;
    }

    // recursive case
    for (int i = index + 1; i <= n; i++) {
        prefix.push_back(i);
        get(n, k, i, prefix);
        prefix.pop_back();
    }
}