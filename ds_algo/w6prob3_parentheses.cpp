#include <iostream>
#include <string>
#include <climits>
#include <algorithm>
#define MAXN 16

using namespace std;

long long calc(long long a, long long b, char c) {
  switch (c) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
  }
}

long long max_value(int n, int d[], char op[]) {
  long long M[MAXN][MAXN], m[MAXN][MAXN];
  int i, j, s;
  long long a, b, c, e;
  long long max_val, min_val;

  for (i=1; i<=n; ++i) {
    m[i][i] = d[i];
    M[i][i] = d[i];
  }

  for (s=1; s<=n-1; ++s) {
    for (i=1; i<=n-s; ++i) {
      j = i + s;
      min_val = LLONG_MAX;
      max_val = LLONG_MIN;
      for (int k=i; k<j; ++k) {
        a = calc(M[i][k], M[k+1][j], op[k]);
        b = calc(M[i][k], m[k+1][j], op[k]);
        c = calc(m[i][k], M[k+1][j], op[k]);
        e = calc(m[i][k], m[k+1][j], op[k]);
        min_val = min(min(min(min_val, a), min(b, c)), e);
        max_val = max(max(max(max_val, a), max(b, c)), e);
      }
      m[i][j] = min_val;
      M[i][j] = max_val;
    }
  }

  return M[1][n];
}

int main() {
  string s;
  int d[MAXN];
  char op[MAXN];
  cin >> s;
  int n = s.length()/2 + 1;

  //tokenize
  int i;
  for (i=0; i<s.length(); ++i)
    if (i%2 == 0)
      d[i/2 + 1] = s[i] - '0';
    else
      op[i/2 + 1] = s[i];
  // d[1->n], op[1->n-1]

  cout << max_value(n, d, op) << endl;
}
