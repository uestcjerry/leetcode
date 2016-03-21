/*
 * DP, O(n)
 *
 * assume L[i] = s[m ... i] is the longest for i now.
 * next, we meet s[i + 1]
 * 1:   s[i + 1] is not in s[m ... i]
 *      L[i+1] = s[m ... i+1]
 * 2:   s[i + 1] is in s[m .. i], and k is the former exist location
 *      let m = max(m, k)
 *      so , L[i+1] = s(m ... i+1)
 *
 * Time requirement: O(n), just scan for once time
 */

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s);
};
int Solution::lengthOfLongestSubstring(string s)
{
    if (s.size() == 0)
        return 0; 
    vector<int> Record = vector<int>(256, -1);
    int longest = 0, start = 0;

    for (int i = 0; i < (int)s.size(); ++i) {
        start = max(start, Record[s[i]] + 1); 
        Record[s[i]] = i;
        longest = max(longest, i - start + 1);
    }
    return longest;
}

int main()
{
    Solution temp;
    std::cout << temp.lengthOfLongestSubstring("abcabcbb") << std::endl;
    return 0;
}

