#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findKth(vector<int>::iterator, int, vector<int>::iterator, int , int);
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2);
};
double Solution::findKth(vector<int>::iterator a, int m, vector<int>::iterator b, int n, int k)
{
    if (m > n)
        return findKth(b, n, a, m, k);
    if (m == 0)
        return *(b + k - 1);
    if (k == 1)
        return min(*a, *b);

    int pa = k / 2 < m ? k / 2 : m;
    int pb = k - pa;
    if (*(a + pa - 1) == *(b + pb - 1))
        return *(a + pa - 1);
    else if (*(a + pa - 1) < *(b + pb - 1))
        return findKth(a + pa, m - pa, b, n, k - pa);
    else
        return findKth(a, m, b + pb, n - pb, k - pb);
}

double Solution::findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{ 
    vector<int>::iterator a = nums1.begin();
    vector<int>::iterator b = nums2.begin();

    int length = nums1.size() + nums2.size();
    if (length & 0x1)
        return findKth(a, nums1.size(), b, nums2.size(), length/2 + 1);
    else
        return ((findKth(a, nums1.size(), b, nums2.size(), length/2)) + 
                (findKth(a, nums1.size(), b, nums2.size(), length/2 + 1))) / 2;
}

int main()
{
    Solution obj;
    vector<int> data1 = {1,3,5,7,9,11};
    vector<int> data2 = {2,4,6,8,10,12}; 
    std::cout << obj.findMedianSortedArrays(data1, data2) << std::endl;

    return 0;
}
