/*************************************************************************
	> File Name: twosum.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年06月11日 星期四 22时39分38秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, j;
        vector<int> t;
        int flag = 0;
        for (i = 0; i < nums.size(); i++) {
            for (j = i + 1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target) {
                    t.push_back(i);
                    t.push_back(j);
                    flag = 1;
                    break;
                }
            }
            if(flag) {
                break;
            }
        }   
        return t;
    }
};
