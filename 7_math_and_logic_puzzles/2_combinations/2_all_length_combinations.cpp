/**
 *  Given a set of unique elements, create all the possible combinations.
 *  (contain duplicate elements)
 * 
 *  * Solutions:
 * 
 *    ex. "012"의 모든 가능한 길이의 조합 만들기 (길이 1 ~ 길이 3)
 *        prefix | available (start, end) |
 *        ""       (0, 2)
 *                 -> "" + 0 저장
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
vector<vector<int>> combinations;

void combine(vector<int> prefix, int start, int end) {
    // base case: 
    if (start > end) {
        return;
    }
    // recursive case:
    for (int i = start; i <= end; i++) {
        // 사용가능한 다음 숫자를 붙인 조합 저장
        prefix.push_back(i);
        combinations.push_back(prefix);
        // 사용가능한 숫자가 더 있다면, 재귀호출하여 숫자 더 붙일 수 있는만큼 붙이기
        if (i < end) {
            combine(prefix, i + 1, end);
        }
        // 붙였던 숫자 다시 떼기
        prefix.pop_back();
    }
}