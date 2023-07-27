//  code64.cpp
//  leetcode
//  把数组排成最小的数
//  Created by Qian on 7/11/23.

#include <iostream>
#include <vector>
#include <string>
using namespace::std;

/*输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个 解法：快速排序/内置函数*/

class Solution {
public:
    //内置函数
    string minNumber_1(vector<int>& nums) {
        vector<string> str_vec;
        for(int num : nums){
            str_vec.push_back(to_string(num));
        }
        sort(str_vec.begin(), str_vec.end(), [](string x, string y){return x+y < y+x;});
        string res;
        for(string str : str_vec){
            res.append(str);
        }
        return res;
    }
    
    //快速排序
    void quickSort(vector<string>& strs, int l, int r) {
        if(l >= r) return;
        int i = l, j = r;
        while(i < j) {
            while(strs[j] + strs[l] >= strs[l] + strs[j] && i < j) j--;
            while(strs[i] + strs[l] <= strs[l] + strs[i] && i < j) i++;
            swap(strs[i], strs[j]);
        }
        swap(strs[i], strs[l]);
        quickSort(strs, l, i - 1);
        quickSort(strs, i + 1, r);
    }
    string minNumber_2(vector<int>& nums) {
        vector<string> strs;
        for(int i = 0; i < nums.size(); i++)
            strs.push_back(to_string(nums[i]));
        quickSort(strs, 0, int(strs.size()) - 1);
        string res;
        for(string s : strs)
            res.append(s);
        return res;
    }
};
