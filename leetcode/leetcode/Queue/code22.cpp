//  code22.cpp
//  leetcode
//  有序队列
//  Created by Qian on 6/26/23.

#include <iostream>
using namespace::std;

/*
 给定一个字符串 s 和一个整数 k
 你可以从 s 的前 k 个字母中选择一个，并把它加到字符串的末尾
 返回在应用上述步骤的任意数量的移动后，字典上最小的字符串
*/
class Solution {
public:
    string orderlyQueue(string s, int k) {
        //轮转
        string min_s = s;
        unsigned long n = s.length();
        if(k == 1){
            for(int i = 0; i < n - 1; i++){
                string new_s = s.substr(1) + s[0];
                if(new_s < min_s)
                    min_s = new_s;
                s = new_s;
            }
        }
        else//排序
        {
            sort(s.begin(), s.end());
            min_s = s;
        }
        return min_s;
    }
};

int main(){
    string s = {"baaca"};
    int k = 3;
    Solution solution;
    string min_s = solution.orderlyQueue(s, k);
    cout << min_s << endl;
    return 0;
}
