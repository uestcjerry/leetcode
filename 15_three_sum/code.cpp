#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums);
    std::vector<int> getOrder(int a, int b, int c);
    bool testTripple(std::vector<int> &, std::vector<int> &);
};

std::vector<std::vector<int>> Solution::threeSum(std::vector<int> &nums)
{
    std::vector<std::vector<int>> totalVec;

    if (nums.size() == 0)
        return totalVec;

    std::vector<int> resVec;
    unsigned int length = nums.size();
    for (unsigned int i = 0; i < length; ++i) {
        for (unsigned int j = i + 1; j < length; ++j) {
            for (unsigned int k = j + 1; k < length; ++k) {
                if (i == j || j == k || i == k) 
                    continue;
                if (nums.at(i) + nums.at(j) + nums.at(k) == 0) {
                    std::cout<<"i="<<i<<",j="<<j<<",k="<<k<<std::endl;//////////////////////
                    resVec.clear();
                    resVec = getOrder(nums.at(i), nums.at(j), nums.at(k));
                    bool goon = true;
                    for (auto &elem : totalVec)
                        if (testTripple(elem, resVec) == true)
                            goon = false;
                    if (goon == false)
                        continue;
                    totalVec.push_back(resVec);
                }
            }
        }
    }
    return totalVec;
}
std::vector<int> Solution::getOrder(int a, int b, int c)
{
    std::vector<int> result = {a, b, c};
    std::sort(result.begin(), result.end());
    return result;
}
bool Solution::testTripple(std::vector<int> &a, std::vector<int> &b)
{
    if (a.size() != b.size())
        return false;
    for (unsigned int i = 0; i < 3; ++i)
        if (a.at(i) != b.at(i))
            return false;
    return true;
}

void printRes(std::vector<std::vector<int>> &elem)
{
    for (const auto &i : elem) {
        for (const auto &j : i)
            std::cout<< j << " ";
        std::cout<<std::endl;
    }
}
int main()
{
    Solution obj;
    std::vector<std::vector<int>> total;
    std::vector<int> data = {-1, 0, 1, 2, -1, -4};
    total = obj.threeSum(data);

    printRes(total);

    return 0;
}
