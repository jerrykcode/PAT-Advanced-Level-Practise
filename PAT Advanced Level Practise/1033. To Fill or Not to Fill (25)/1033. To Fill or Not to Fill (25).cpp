// 1033. To Fill or Not to Fill (25).cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <algorithm>

struct node {
	double price, dist;
};

bool compare(node a, node b)
{
	return a.dist < b.dist;
}

int main()
{
	double cmax, d, davg;
	int n;
	cin >> cmax >> d >> davg >> n;
	node *stations = new node[n + 1];
	for (int i = 0; i < n; i++) 
		cin >> stations[i].price >> stations[i].dist;
	stations[n] = {0.0, d};
	sort(stations, stations + n + 1, compare);
	if (stations[0].dist != 0) {
		printf("The maximum travel distance = 0.00\n");
		return 0;
	}
	double availableDist = 0, totalPrice = 0;
	int currentStation = 0;
	while (1) {
		double maxDist = stations[currentStation].dist + cmax * davg;
		if (currentStation + 1 < n + 1 && stations[currentStation + 1].dist > maxDist) {
			printf("The maximum travel distance = %.2f\n", maxDist);
			return 0;
		}
		int min = currentStation + 1, flag = 0;
		for (int i = currentStation + 1; i < n; i++) {
			if (stations[i].dist > maxDist) break;
			if (stations[i].price < stations[currentStation].price) {
				min = i;
				flag = 1;
				break;
			}
			if (stations[i].price < stations[min].price) 
				min = i;
		}
		if (flag) {
			totalPrice += (stations[min].dist - availableDist) * stations[currentStation].price/davg;
			availableDist = stations[min].dist;
			currentStation = min;
		}
		else {
			if (maxDist >= d) {
				totalPrice += (d - availableDist)*stations[currentStation].price/davg;
				break;
			}
			totalPrice += (maxDist - availableDist)*stations[currentStation].price/davg;
			availableDist = maxDist;
			currentStation = min;
		}
	}//while
	printf("%.2f\n", totalPrice);
    return 0;
}

