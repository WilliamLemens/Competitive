#include <stdio.h>
#include <iostream>

int main() {
  int N, cnt;
  std::cout << "N:  ";
  std::cin >> N;

  for (int i = 1; i <= N; i++)
    for (int j = i+1; j <= N; j++) {
      if ((i+j)%2 == 0) {
        std::cout<< i << " " << j << std::endl;
        cnt++;
      }
    }
  std::cout << "M: " << cnt << std::endl;
}
