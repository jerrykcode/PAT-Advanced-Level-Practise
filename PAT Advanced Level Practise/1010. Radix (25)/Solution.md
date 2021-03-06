﻿# 1010. Radix (25)
[原题地址](https://www.patest.cn/contests/pat-a-practise/1010)
* 时间限制 400 ms
* 内存限制 65536 kB
* 代码长度限制 16000 B
* 判题程序 Standard
* 题目作者 CHEN, Yue

Given a pair of positive integers, for example, 6 and 110, can this equation 6 = 110 be true? The answer is "yes", if 6 is a decimal number and 110 is a binary number.

Now for any pair of positive integers N1 and N2, your task is to find the radix of one number while that of the other is given.

## Input Specification:

Each input file contains one test case. Each case occupies a line which contains 4 positive integers:
*N1 N2 tag radix*
Here N1 and N2 each has no more than 10 digits. A digit is less than its radix and is chosen from the set {0-9, a-z} where 0-9 represent the decimal numbers 0-9, and a-z represent the decimal numbers 10-35. The last number "radix" is the radix of N1 if "tag" is 1, or of N2 if "tag" is 2.

## Output Specification:

For each test case, print in one line the radix of the other number so that the equation N1 = N2 is true. If the equation is impossible, print "Impossible". If the solution is not unique, output the smallest possible radix.

## Sample Input 1:
6 110 1 10  
## Sample Output 1:
2  
## Sample Input 2:
1 ab 1 2  
## Sample Output 2:
Impossible  

## 题意：

给出一个整数的进制，求另一个整数在多少进制下的值与它相等。

## 思路：

本题思路参考了[1010. Radix (25) (柳婼 の blog)](https://www.liuchuo.net/archives/2458)

用二分法查找进制数

## 代码：

[1010. Radix (25).cpp](https://github.com/jerrykcode/PAT-Practise/blob/master/PAT%20Advanced%20Level%20Practise/1010.%20Radix%20(25)/1010.%20Radix%20(25).cpp)
```cpp
#include <iostream>
using namespace std;
#include <string>
#include <math.h>

int toInt(char c)
{
	if (isdigit(c)) return c - '0';
	return c - 'a' + 10;
}

long long toDec(string number, long long radix)
{
	long long result = 0;
	for (int i = 0; i < number.length(); i++)
		result += toInt(number[number.length() - i - 1])*pow(radix, i);
	return result;
}

long long max(long long a, long long b)
{
	return a > b ? a : b;
}

long long binarySearch(long long low, long long high, string n, long long a)
{
	while (low <= high) {
		long long mid = (low + high) / 2;
		long long value = toDec(n, mid);
		if (value < 0) high = mid - 1;
		else if (value < a) low = mid + 1;
		else if (value == a) return mid;
		else high = mid - 1;
	}
	return -1;
}

int main()
{
	string n1, n2;
	int tag, radix;
	cin >> n1 >> n2 >> tag >> radix;
	if (tag == 2) swap(n1, n2);
	long long a = toDec(n1, radix);
	int maxDigit = 0;
	for (int i = 0; i < n2.length(); i++) {
		if (toInt(n2[i]) > maxDigit)
			maxDigit = toInt(n2[i]);
	}
	long long low = maxDigit + 1;
	long long high = max(low, a) + 1;
	long long r = binarySearch(low, high, n2, a);
	if (r == -1) cout << "Impossible";
	else printf("%lld", r);
	return 0;
}
```