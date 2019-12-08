// LRU.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include"quene.h"
#define n 5
using namespace std;

void LRU() {
	arrayQueue queue(n);
	while (1)
	{
		int a;
		cout << "请输入将要使用页面的页号：";
		cin >> a;
		if (-1 == a)
			break;
		bool flag = queue.search(a);
		if (!flag)
			queue.push(a);
		queue.output();
	}
}
int main()
{
	cout << "此程序为简单的LRU算法" << endl;
	cout << "下面为循环输入，输入-1退出" << endl;
	LRU();
	return 0;
}

