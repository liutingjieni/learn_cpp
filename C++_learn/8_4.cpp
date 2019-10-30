/*************************************************************************
	> File Name: 8_4.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月26日 星期六 15时49分55秒
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<vector> 
#include<string>
using namespace std;

int main()
{
    ifstream in("class.cpp");
    if (!in) {
        cerr << "无法打开输入文件" << endl;
        return -1;
    }

    string line;
    vector<string> words;
    while (in >> line) {
        words.push_back(line);
    }
    in.close();

    ofstream out("class2", ofstream :: app);
    for (auto it : words) {
        it = it + '2';
        out << it << endl;
    }
    out.close();
        return 0;
}
