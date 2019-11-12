#pragma once
#include"Grubbs.h"
using namespace std;
const float c0 = sqrtf(3);
float uA(float*x, unsigned n, float a)
{
	float average = Grubbs(x, n, a), delta, Sdelta2 = 0;
	unsigned i;
	for (i = 0; i < n; ++i)if (in_use[i]) {
		delta = x[i] - average;
		Sdelta2 += delta*delta;
	}
	delete[]in_use;
	return sqrt(Sdelta2 / (m*(m - 1)));
}
float uB(float deltaEquipment, float c = c0)
{
	return deltaEquipment / c;
}
float u(float*x, unsigned n, float a, float deltaEquipment, float c = c0)
{
	float ua = uA(x, n, a), ub = uB(deltaEquipment, c0), U;
	U= sqrtf(ua*ua + ub*ub);
	cout << "A类标准不确定度：" << ua << endl;
	cout << "B类标准不确定度：" << ub << endl;
	cout << "合成标准不确定度：" << U << endl;
	return U;
}