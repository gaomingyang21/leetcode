/*
参考：http://blog.csdn.net/sgbfblog/article/details/8001651
功能：实现给定一个中缀表达式转换成后缀表达式
Time：2014-4-29
Author：gaomingyang
*/
#include <iostream>
#include <stack>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

char str[]="+-*/(";
int getId(char ch)
{
	int i;
	for(i=0;i<strlen(str);i++)
		if(str[i]==ch)
			break;
	return i;
}

int getPriority(char ch)
{
	int priority = 0;
	switch(ch)
	{
		case '+':
		case '-':
			priority = 2;
			break;
		case '*':
		case '/':
			priority = 3;
			break;
	}
	return priority;
}

int getInt(char**p)
{
	int i=0;
	while(isdigit(**p))
	{
		i=i*10+((**p)-'0');
		(*p)++;
	}
	return i;
}
void main()
{
	char exp[]="(3-4)*5",*p=exp;
	int t;
	stack<int> optr;
	stack<char> op;
	while(*p)
	{
		if(*p == ' ')
			continue;
		// 操作数直接输出
		if(isdigit(*p))
		{
			t=getInt(&p);
			cout<<t<<" ";
		}
		// 操作码处理过程
		if(*p==')')
		{
			while(op.top()!='(')
			{
				cout<<op.top()<<" ";
				op.pop();
			}
			op.pop();// 左括号出栈
		}
		else if(*p=='(')
			op.push('(');
		else if(*p=='\0')
			break;
		else
		{
			while(!op.empty()&&getPriority(*p)<=getPriority(op.top()))
			{
				if(op.top()!='(')
				{
					cout<<op.top()<<" ";
					op.pop();
				}else break;
			}
			op.push(*p);
		}
		p++;
	}

	while(!op.empty())
	{
		cout<<op.top()<<" ";
		op.pop();
	}
}
