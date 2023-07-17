//  code15.cpp
//  leetcode
//  翻转单词顺序
//  Created by Qian on 6/20/23.

#include <iostream>
#include <string>
using namespace::std;

/*
 输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
 为简单起见，标点符号和普通字母一样处理。
 例如输入字符串"I am a student. "，则输出"student. a am I"
*/

class Solution {
public:
    //方法一
    string reverseWords(string s) {
        // 反转整个字符串
        reverse(s.begin(), s.end());
        unsigned long n = s.size();
        int idx = 0;
        for (int start = 0; start < n; ++start) {
            if (s[start] != ' ') {
                // 填一个空白字符然后将idx移动到下一个单词的开头位置
                if (idx != 0)
                    s[idx++] = ' ';
                cout << "idx: " << idx << endl;

                // 循环遍历至单词的末尾
                int end = start;
                while (end < n && s[end] != ' ')
                    s[idx++] = s[end++];
                cout << "end: " <<end << endl;
                cout << "idx_2: " << idx << endl;

                // 反转整个单词
                reverse(s.begin() + idx - (end - start), s.begin() + idx);
                cout << "s: " << s << endl;

                // 更新start，去找下一个单词
                start = end;
            }
        }
        s.erase(s.begin() + idx, s.end());
        return s;
    }
    
    //方法二(双指针)
    string reverseWords_2(string s) {
        int n = int(s.size());
        string ans = "";
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                int right = i;
                while (i >= 0 && s[i] != ' ') {
                    i--;
                }
                ans += s.substr(i + 1, right - i) + " ";
            }
        }
        return ans.substr(0, ans.size() - 1);
    }
};
