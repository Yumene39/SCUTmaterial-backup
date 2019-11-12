#pragma once
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include<cmath>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<math.h>
using namespace std;
const float pi = M_PI;
const float e = M_E;
bool*in_use;
unsigned m;
template<typename tn>tn sum(tn*a, unsigned l)
{
	tn s = 0;
	unsigned i;
	for (i = 0; i < l; ++i)s += a[i];
	return s;
}
float g(unsigned n, float a)
{
	if (a == 0.05f) {
		switch (n)
		{
		case 4:
			return 1.45;
		case 5:
			return 1.67;
		case 6:
			return 1.82;
		case 7:
			return 1.94;
		case 8:
			return 2.03;
		case 9:
			return 2.11;
		case 10:
			return 2.18;
		case 11:
			return 2.23;
		case 12:
			return 2.28;
		}
	}
	else if (a == 0.01f) {
		switch (n) {
		case 4:
			return 1.49;
		case 5:
			return 1.75;
		case 6:
			return 1.94;
		case 7:
			return 2.10;
		case 8:
			return 2.22;
		case 9:
			return 2.32;
		case 10:
			return 2.41;
		case 11:
			return 2.48;
		case 12:
			return 2.55;
		}
	}
	cout << "\nError: Out of Range\n";
	return 0;
}
float Sx(float*x, unsigned n, float average)
{
	unsigned i;
	float Sdelta2 = 0, delta;
	for (i = 0; i < n; ++i) {
		delta = x[i] - average;
		Sdelta2 += delta * delta;
	}
	return sqrtf(Sdelta2 / (n - 1));
}
float Sx(float*x, unsigned n)
{
	return Sx(x, n, sum(x, n) / n);
}
float Grubbs(float*x, unsigned n, float a)
{
	float g0, average, sx, delta;
	bool b;
	unsigned i;
	m = n;
	in_use = new bool[n];
	memset(in_use, true, sizeof(bool)*n);
	do {
		b = false;
		g0 = g(m, a);
		average = 0;
		for (i = 0; i < n; ++i)if (in_use[i])average += x[i];
		average /= m;
		sx = 0;
		for (i = 0; i < n; ++i)if (in_use[i]) {
			delta = x[i] - average;
			sx += delta*delta;
		}
		sx = sqrt(sx / (m - 1));
		for (i = 0; i < n; ++i)if (in_use[i] && (x[i] - average) / sx >= g0) {
			b = true;
			in_use[i] = false;
			--m;
			cout << "剔除了x[" << i + 1 << "]，即" << x[i] << endl;
		}
		cout << endl;
	} while (b);
	cout << "经格拉布斯准则处理，得平均值：" << average << endl;
	//delete[]in_use;
	return average;
}