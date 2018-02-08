#include <stdio.h>
#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int main() {
  cout << 100000 << ' ' << 99999 << endl;
  for (int i = 1; i < 100000; i++)
    cout << i << ' ' << i+1 << ' ' << 69 << endl;
}
