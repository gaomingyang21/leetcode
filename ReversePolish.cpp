/**
题目地址：http://oj.leetcode.com/problems/evaluate-reverse-polish-notation/
作者：gaomingyang
时间：2014-4-29
逆波兰表达式四则运算
**/
#include <iostream>
#include <stack>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
		stack<int> s;
		for(vector<string>::iterator it = tokens.begin(); it!=tokens.end(); it++)//顺序访问
		{
			string tmp = *it;
			int x1,x2;

			switch(tmp[0])
			{
				//int x1,x2;
				case '+':
					x1 = s.top();
					s.pop();
					x2 = s.top();
					s.pop();
					s.push(x2+x1);
					break;
				case '-':
					if(tmp.length() > 1)
					{
						s.push(atoi(tmp.c_str()));
						break;
					}
					x1 = s.top();
					s.pop();
					x2 = s.top();
					s.pop();
					s.push(x2-x1);
					break;
				case '*':
					x1 = s.top();
					s.pop();
					x2 = s.top();
					s.pop();
					s.push(x2*x1);
					break;
				case '/':
					x1 = s.top();
					s.pop();
					x2 = s.top();
					s.pop();
					s.push(x2/x1);
					break;
				default:
					s.push(atoi(tmp.c_str()));
			}
		}
		return s.top();
    }
};

int main()
{
	// 初始化测试数据
	char *words[] = {"-1","1","*","-1","+"};
	char *words1[] = {"4","13","5","/","+"};
	size_t words_size = sizeof(words)/sizeof(char *);
	vector<string> test(words, words + words_size);
	size_t words1_size = sizeof(words1)/sizeof(char *);
	vector<string> test1(words1, words1 + words1_size);
	
	Solution s;
	int xx = s.evalRPN(test);
	cout << xx << endl;
	//cout  << s.evalRPN(test1);
	//int testchu = 13/5;
	//cout << testchu << endl;
	return 0;
}
