#include <bits/stdc++.h>
using namespace std;
template <class T>
void chmax(T& a, T b) {
  if (a < b) a = b;
}
template <class T>
void chmin(T& a, T b) {
  if (a > b) a = b;
}

const int INF = 1 << 29;

int main() {
  int N, K, W;
  vector<int> a(N);

  N = 4;
  K = 4;
  W = 25;

  a[0] = 1;
  a[1] = 2;
  a[2] = 10;
  a[3] = 20;

  vector<vector<int>> dp(N + 1, vector<int>(W + 1, INF));

  dp[0][0] = 0;
  // dp[0][1] = 1;
  // dp[0][2] = 1;
  // dp[0][10] = 1;
  // dp[0][20] = 1;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j <= W; ++j) {
      if (i == 0) dp[i][a[j]] = 1;
      chmin(dp[i + 1][j], dp[i][j]);
      if (j >= a[i])
      {
        chmin(dp[i + 1][j], dp[i][j - a[i]] + 1)
      };

      cout << dp[i + 1][j] << " ";
    }
    cout << endl;
  }

  if (dp[N][W] <= K)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  const std::string s = "hello";
  {
    std::string result = s.substr(2, 3);
    std::cout << result << std::endl;
  }
}
