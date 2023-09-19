//  codem_7.cpp
//  leetcode
//  1～n 整数中 1 出现的次数
//  Created by Qian on 8/4/23.

#include <iostream>
using namespace::std;

/*
 输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。
 例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次
 解法：动态规划
*/

class Solution {
public:
    // 根据当前位的大小进行判断，比如数字 135x21
    // 如果遍历到百位，百位的数字x，x 需要分三种情况讨论
    // 第一种：等于1，那么在百位可以计算1的个数为 135 * 100 + 21
    // 第二种：大于等于 2，在百位可以计算出1的个数为 (135+1)*100
    // 第三种：小于 1,在百位计数出1的个数为 135*100
    // 所以大致的思路就是：遍历到哪一位时，将数字分为两部分，然后跌加每一位出现1的次数
        int countDigitOne(int n) {
        int count = 0;
        for(long pos = 1;pos<=n;pos*=10){
            int big = n/pos;
            int small = n%pos;
            if(big %10 ==1){
                count +=small+1;
            }
            // 之所以这样写，是把第二种和第三种合在了一起
            // 如果因为如果大于2，加8一定会进一位，如果小于等于，就算+8，也不会产生影响
            count+=(big+8)/10 * pos;
        }
        return count;
    }
};
