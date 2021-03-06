// 1100. Mars Numbers (20).cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <string>
#include <map>

int main()
{
	string n1[12] = { "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
	string n2[12] = { "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
	map<string, int> string_to_int;
	for (int i = 0; i < 12; i++) {
		string_to_int[n1[i]] = i + 1;
		string_to_int[n2[i]] = (i + 1) * 13;
	}
	int n;
	cin >> n;
	cin.ignore();
	string number;
	for (int i = 0; i < n; i++) {
		getline(cin, number);
		if (isalpha(number[0])) { //Mars to Earth
			if (number == "tret") {
				printf("0\n");
				continue;
			}
			string a = "", b = "";
			int flag = 1;
			for (int i = 0; i < number.length(); i++) {
				if (flag) {
					if (number[i] != ' ') a += number[i];
					else flag = 0;
				}
				else b += number[i];
			}
			printf("%d\n", string_to_int[a] + string_to_int[b]);
		}
		else { //Earth to Mars
			int n = atoi(number.c_str());
			if (n == 0) {
				printf("tret\n");
				continue;
			}
			string result = "";
			if (n % 13 != 0)
				result = n1[n % 13 - 1];
			if (n / 13 != 0) {
				if (n % 13 != 0) result = " " + result;
				result = n2[n / 13 - 1] + result;
			}
			cout << result << endl;
		}
	}
    return 0;
}

