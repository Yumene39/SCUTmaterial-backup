#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>
#include<cmath>
#include<cstring>
#include"uncertainty.h"
using namespace std;
int main()
{
	float*x;
	unsigned n, i;
	float a, de;
	bool b = false;
	cout << "请输入数据组数n：";
	while (cin >> n) {
		x = new float[n];
		cout << "请输入数据x[i]：\n";
		for (i = 0; i < n; ++i)cin >> x[i];
		cout << "请输入显著水平a（0.01或0.05）：";
		cin >> a;
		cout << "请输入Δ（仪）：";
		cin >> de;
		u(x, n, a, de);
		//system("pause");
		delete[]x;
		b = false;
		cout << "请输入数据组数n：";
	}
	return 0;
}