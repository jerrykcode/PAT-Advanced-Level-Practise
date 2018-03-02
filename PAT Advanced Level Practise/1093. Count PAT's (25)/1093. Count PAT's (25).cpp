// 1093. Count PAT's (25).cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <string>

int main()
{
	string pats;
	cin >> pats;
	long long countP = 0, countPA = 0, countPAT = 0;
	for (int i = 0; i < pats.length(); i++) {
		switch (pats[i]) {
		case 'P': { countP++; break; }
		case 'A': {countPA += countP; break; }
		case 'T': {countPAT += countPA; break; }
		}
	}
	countPAT %= 1000000007;
	cout << countPAT << endl;
    return 0;
}



