//  leetcode
//  汽水瓶
//  Created by Qian on 7/19/23.

#include <iostream>
using namespace::std;

/*
 某商店规定：三个空汽水瓶可以换一瓶汽水，允许向老板借空汽水瓶（但是必须要归还）。
 小张手上有n个空汽水瓶，她想知道自己最多可以喝到多少瓶汽水。
 数据范围：输入的正整数满足 1 ≤ n ≤ 100
 考点：贪心算法
*/

int SodaNumber(int n){
    int sodanum = 0;
    while(n >= 3){
        int soda = n / 3;
        sodanum += soda;
        n = soda + n % 3;
    }

    if(n == 2){
        sodanum++;
    }

    return sodanum;
}
