/**
 *  Given numbers of each categories, count number of total possible unique combinations.
 * 
 *  * Solutions:

 * 
 * 
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
int countAllCombinations(vector<int> numbers) {
    if (numbers.empty()) {
        throw invalid_argument("numbers are empty");
    }
    // 
    int sum = 1;
    for (int num : numbers) {
        sum *= (num + 1);
    }
    //
    sum = sum - 1;
    return sum;
}