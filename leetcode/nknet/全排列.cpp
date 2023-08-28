//  全排列.cpp
//  leetcode
//  深度优先搜索
//  Created by Qian on 8/24/23.

#include <iostream>
#include <unordered_set>
using namespace::std;

class Solution {
public:
    //无重复数字
    vector<vector<int>> vec;
    void dfs(vector<int>& nums, int index){
        //结束条件
        if(index == nums.size() - 1){
            vec.push_back(nums);
            return;
        }
        //路径
        //选择
        for(int i = index; i < nums.size(); i++){
            swap(nums[index], nums[i]);
            dfs(nums, index + 1);
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, 0);
        return vec;
    }
    
    //含重复数字
    vector<vector<int>> n_vec;
    void dfsUni(vector<int>& nums, int index){
        //结束条件
        if(index == nums.size() - 1){
            n_vec.push_back(nums);
            return;
        }
        //路径
        //选择
        unordered_set<int> us;
        for(int i = index; i < nums.size(); i++){
            if(!us.count(nums[i])){
                us.insert(nums[i]);
                swap(nums[index], nums[i]);
                dfsUni(nums, index + 1);
                swap(nums[index], nums[i]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        dfsUni(nums, 0);
        return n_vec;
    }
};
