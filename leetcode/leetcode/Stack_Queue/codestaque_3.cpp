//  code18.cpp
//  leetcode
//  滑动窗口的最大值
//  Created by Qian on 6/25/23.

#include <iostream>
#include <vector>
#include <deque>
using namespace::std;

/*给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值*/

class Solution {
public:
    //方法一
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> max_set;
        vector<int>::iterator iter;
        for(iter = nums.begin(); iter <= nums.end() - k; iter++){
            int max_value = *max_element(iter, iter + k);
            max_set.push_back(max_value);
        }
        return max_set;
    }
    //方法二:双端队列
    vector<int> maxSlidingWindow_2(vector<int>& nums, int k) {
       unsigned long n = nums.size() ;
       deque<int> dq ;
       vector<int> res ;

       if (nums.size() == 0)
           return res ;
   
       for (int i = 0 ; i < n ; ++i) {
           while (!dq.empty() && i - dq.front() + 1 > k) {
               dq.pop_front() ;
           }
           while (!dq.empty() && nums[dq.back()] <= nums[i]) {
               dq.pop_back() ;
           }
           dq.push_back(i) ;
           if (i >= k - 1)
               res.push_back(nums[dq.front()]) ;
       }
       return res ;
   }
};
