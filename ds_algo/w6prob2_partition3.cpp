// idea: kiểm tra sum chia hết cho 3 không, nếu có
// coi như 3 bài toán ba lô: xếp lần lượt từng ba lô và đánh
// dấu các phần tử đã chọn, nếu có ba lô nào không xếp được đầy thì
// kết luận không chia quà được, ngược lại kết luận chia được.

#include <iostream>
#include <vector>

#define MAXN 301
#define MAXW 10001
using namespace std;

int max_val(int Wm, int n, long w[]) {
  vector<vector<int>> value(MAXW, vector<int> (MAXN));
  int i, j, weight, val;
  for (i=0; i<=Wm; ++i) value[i][0] = 0;
  for (j=0; j<=n; ++j) value[0][j] = 0;
  for (i=1; i<=n; ++i)
    for (weight=1; weight<=Wm; ++weight) {
      value[weight][i] = value[weight][i-1];
      if (w[i] <= weight) {
        val = value[weight-w[i]][i-1] + w[i];
        if (value[weight][i] < val)
          value[weight][i] = val;
      }
    }
  return value[Wm][n];
}

int main() {
  int n;
  int sum=0, s;
  long w[MAXN];
  cin >> n;
  for (int i=1; i<=n; ++i) {
    cin >> w[i];
    sum += w[i];
  }
  s = sum/3;
  if (sum % 3 != 0)
    cout << 0 << endl;
  else {
    if (max_val(s, n, w) < s) cout << 0 << endl;
    else trace();
    if ()
    if ()
  }
}
