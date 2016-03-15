#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

// sort
class Solution {
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target);
};

bool compareInt(const int a, const int b) { return a < b; }

std::vector<int> Solution::twoSum(std::vector<int> &nums, int target)
{
    std::vector<int> res_vec;
    
    std::vector<int> nums_back = nums;
    std::sort(nums_back.begin(), nums_back.end(), compareInt);

    bool finish = false;
    for (unsigned int i = 0; i < nums_back.size(); ++i) {
        for (unsigned int j = i + 1; j < nums_back.size(); ++j) {
            if (nums_back.at(i) + nums_back.at(j) == target) {

                int temp1 = -1, temp2 = -1;
                bool first = false, second = false;
                for(unsigned int t = 0; t < nums.size(); ++t) {
                    if (second && first) 
                        break;
                    if (nums.at(t) == nums_back.at(i) && first == false) {
                        temp1 = t; 
                        first = true;
                    } else if (nums.at(t) == nums_back.at(j) && second == false) {
                        temp2 = t;
                        second = true; 
                    }
                    else
                        ;
                
                }
                res_vec.push_back(temp1);
                res_vec.push_back(temp2);
                finish = true;
                break;
            }
        }
        if (finish)
            break;
    }

    return res_vec;
}

int main()
{
    Solution tempObj;
    std::vector<int> res;
    std::vector<int> data = {3, 2, 4};
    int target = 6;
    res = tempObj.twoSum(data, target);

    for (const auto &i : res)
        std::cout<<i<<" ";
    std::cout<<std::endl;
    return 0;
}
