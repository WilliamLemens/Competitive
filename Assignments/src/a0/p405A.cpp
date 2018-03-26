#include <stdio.h>
#include <iostream>

void insertionSort(int len, int vals[]) {
	int i = 1;
	while (i < len) {
		int j = i-1;
		int x = vals[i];
		while (j >= 0 && vals[j] > x)
			vals[j+1] = vals[j--];
		vals[j+1] = x;
		i++;
	}
}

int main() {
	int len;
	std::cin >> len;
	int vals[len];
	for (int i = 0; i < len; i++)
		std::cin >> vals[i];
	insertionSort(len, vals);
	std::cout << vals[0];
	for (int i = 1; i < len; i++)
		printf(" %d",vals[i]);
	std::cout << "\n";
}
