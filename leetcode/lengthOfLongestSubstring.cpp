/*************************************************************************
	> File Name: lengthOfLongestSubstring.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年06月11日 星期四 00时44分38秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string S) {
        int flag = 1, flag1 = 1, flag2 = 1;
        int m = 0;
        for (int i = 1; i < S.size(); i++) {
            flag = 1;
            for (int j = i - 1; j >= m; j--) {
                if (S[i] == S[j]) {
                    m = i;
                    flag2 = flag1 > flag2 ? flag1 : flag2;
                    flag1 = 1;
                    flag = 0;
                    cout << endl;
                    break;
                }
            }
            if (flag) {
                flag1++;
            }
        }
        cout << flag2 << endl;
    }
};

int main()
{
    Solution t;
    string s;
    cin >> s;
    t.lengthOfLongestSubstring(s);
}
