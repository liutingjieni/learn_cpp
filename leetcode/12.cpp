/*************************************************************************
	> File Name: 12.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年10月10日 星期六 20时34分49秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        size = word.size();
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (word[0] == board[i][j]) {
                    vector<bool> t(i * board[0].size() + j, 0);
                    if (dfs(board, word, t, i, j, 0)) return true;
                }
            }
        }
        return false;
    }

    bool dfs(const vector<vector<char>> &board, const string &word, vector<bool> t, int i, int j, int m) {
        if (m == size)  return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())  //如果坐标不在矩阵范围内
                return false;
        bool haspath = false;

        if (!t[i * board[0].size() + j] && board[i][j] == word[m]) {
                t[i * board[0].size() + j] = 1;
                m++;
                haspath = dfs(board, word, t, i, j + 1, m) ||
                          dfs(board, word, t, i, j - 1, m) ||
                          dfs(board, word, t, i + 1, j, m) ||
                          dfs(board, word, t, i - 1, j, m);
                if (!haspath) {
                    m--;
                    t[i * board[0].size() + j] = 0;
                } 
        } 
        return haspath;
    }
private:
    int size;
};

int main()
{
    vector<vector<char>> t = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string s = "AB";
    Solution q;
    cout << q.exist(t, s) << endl;
}
