#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> resVec;
        int n = nums.size();

        if (nums.size() < 3)
            return resVec;
        
        std::sort(nums.begin(), nums.end());

        int left, right, target = 0;
        for (int i = 0; i < n - 2; ++i) {

            if (i != 0 && nums.at(i) == nums.at(i-1))
                continue;

            target = 0 - nums.at(i);

            left = i + 1; 
            right = n - 1;

            while (left < right) {
                int result = nums.at(left) + nums.at(right);

                if (result == target) {
                    //std::vector<int> tempObj = {nums.at(i), nums.at(left), nums.at(right)};
                    std::vector<int> tempObj;
                    tempObj.push_back(nums[i]);
                    tempObj.push_back(nums[left]);
                    tempObj.push_back(nums[right]);

                    resVec.push_back(tempObj);
                    
                    while(left < right && nums.at(left) == nums.at(left+1))
                        left++;
                    while(right > left && nums.at(right) == nums.at(right-1))
                        right--;

                    left++;
                    right--;
                } else if (result < target)
                    left++;
                else
                    right--;
            }
        }
        return resVec;
    }
};

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
    std::vector<int> data = {1, 1, -2};
    total = obj.threeSum(data);

    printRes(total);

    return 0;
}
