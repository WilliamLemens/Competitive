#include <stdio.h>
#include <iostream>

int main() {
	int len, leap;
	std::cin >> len;
  std::cin >> leap;
  char board[len];
  std::cin >> board;
	
  int g = 0, t = 0, i = 0, found = 0;
  while (i < len && found < 2) {
		if (board[i] == 'G') {
			g = i;
			found++;
		} else if (board[i] == 'T') {
			t = i;
			found++;
		}
		i++;
	}

	// Just a guick check to see if it's even possible without obstructions
	if (t%leap != g%leap) {
		std::cout << "NO" << std::endl;
		return 0;
	}

	// Actual logic
	if (t > g) {
		g += leap;
		while (g != t) {
			if (board[g] != '.') {
				std::cout << "NO" << std::endl;
				return 0;
			}
			g += leap;
		}
	} else {
		g -= leap;
		while (g != t) {
			if (board[g] != '.') {
				std::cout << "NO" << std::endl;
				return 0;
			}
			g -= leap;
		}
	}
	std::cout << "YES" << std::endl;
}
