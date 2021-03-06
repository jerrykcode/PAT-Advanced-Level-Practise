// 1081. Rational Sum (20).cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	return a == 0 ? abs(b) : gcd(b%a, a);
}

int main()
{
	int n;
	cin >> n;
	int nsum = 0, dsum = 1; // 0/1
	for (int i = 0; i < n; i++) {
		int numerator, denominator;
		scanf("%d/%d", &numerator, &denominator);
		int com = gcd(numerator, denominator);
		numerator /= com;
		denominator /= com;
		nsum = nsum * denominator + dsum * numerator;
		dsum = denominator * dsum;
		com = gcd(nsum, dsum);
		nsum /= com;
		dsum /= com;
	}
	int integer = nsum / dsum;
	nsum -= dsum * integer;
	if (integer != 0) {
		cout << integer;
		if (nsum != 0) cout << " ";
	}
	if(nsum != 0) printf("%d/%d", nsum, dsum);
	if (integer == 0 && nsum == 0) cout << 0;
    return 0;
}

