#include <iostream>
#include <string>
#include <fstream>
#include<sstream>

using namespace std;

int main() {
    string s1, s2;
    int total = 0;
    string keywords[30] = {"if", "else", "auto", "break", "case", "char", "const", "continue", "default",
                           "do", "enum", "extern", "float", "for", "goto", "int", "long", "register",
                           "return", "short", "signed", "sizeof", "static", "struct", "switch",
                           "typedef", "union", "void", "volatile", "while"};//有do，就不用考虑double关键字，有signed就不用考虑unsigned
    //32个字符串，第一版本便是让他们搜索，接下来可以通过分类索引来改进搜索的速度,有doubule便多了一个do，除此之外保留关键词会不会一行出现相同的两个(可以拆分成一个个单词)，开关次数过多
    for (int i = 0; i < 30; ++i) {
        ifstream fin(R"(D:\CLionProjects\EE308_Lab2\test.c)");
        s1 = keywords[i];
        while (getline(fin, s2)) {
            if (s2.find(s1) < 2000) {//一般来说每行不会超过80个词汇，2000个字符宽度足够
                total++;
            }
        }
        fin.close();
    }
    cout <<"total num: " << total << endl;
}
