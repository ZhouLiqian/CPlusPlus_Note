//  code56.cpp
//  leetcode
//  二叉搜索树的后序遍历序列
//  Created by Qian on 7/8/23.

#include <iostream>
using namespace::std;

/*
 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。
 如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同
 解法：分治算法/辅助单调栈
*/

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        int i = 0;
        int j = int(postorder.size() - 1);
        return dfs(postorder, i, j);
    }
    
    bool dfs(vector<int>& postorder, int i, int j){
        if(i >= j)
            return true;
        int p = i;
        //寻找第一个大于根节点的值
        while (postorder[p] < postorder[j])
            p++;
        int m = p;
        //判断主树是否满足后序
        while (postorder[p] > postorder[j])
            p++;
        //分割区间
        return p == j && dfs(postorder, i, m-1) && dfs(postorder, m, j-1);
    }
};
