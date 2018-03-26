#include <stdio.h>

using namespace std;

void merge(int b, int m, int t, int A[], int B[]) {
  int i = b, j = m;
  for (int k = b; k < t; k++)
      B[k] = A[(i < m && (j >= t || A[i] <= A[j])) ? i++ : j++];
}

void split(int b, int t, int A[], int B[]) {
  if (t-b < 2)
    return;
  int m = (t+b)/2;
  split(b, m, B, A);
  split(m, t, B, A);
  merge(b, m, t, B, A);
}

void sort (int n, int arr[]) {
  int work[n];
  for (int i = 0; i < n; i++)
    work[i] = arr[i];
  split(0, n, arr, work);
}

int binSearch(int val, int n, int x[]) {
  int b = 0, t = n;

  if (x[b] > val) return 0;

  while (b+1 < t) {
    int m = (b+t)/2;
    if (x[m] <= val) b = m;
    else t = m;
  }

  return t;
}

int main() {
  int n, q;
  scanf("%d\n", &n);
  int x[n];
  for (int i = 0; i < n; i++)
    scanf("%d", &x[i]);
  scanf("%d\n", &q);

  sort(n, x);

  int m;
  for(int a = 0; a < q; a++) {
    scanf("%d", &m);
    printf("%d\n", binSearch(m, n, x));
  }
}
