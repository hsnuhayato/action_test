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

// 無限大を表す値
const int INF = 1 << 29;

int main() {
  // 入力
  int N, K, W;
  vector<int> a(N);

  // cin >> N >> K >> W;
  // cout << "N " << N << " K " << K << " W " << W << endl;

  // for (int i = 0; i < N; ++i) cin >> a[i];

  N = 4;
  K = 4;
  W = 25;

  a[0] = 1;
  a[1] = 2;
  a[2] = 10;
  a[3] = 20;

  // 配列 dp
  vector<vector<int>> dp(N + 1, vector<int>(W + 1, INF));

  // 初期条件
  dp[0][0] = 0;
  // dp[0][1] = 1;
  // dp[0][2] = 1;
  // dp[0][10] = 1;
  // dp[0][20] = 1;





  // ループ
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j <= W; ++j)
    {
      // 初期条件
      if (i == 0) dp[i][a[j]] = 1;

      // a[i] を選ばない場合
      chmin(dp[i + 1][j], dp[i][j]);

      // a[i] を選ぶ場合
      if (j >= a[i]) {chmin(dp[i + 1][j], dp[i][j - a[i]] + 1)
            };

      cout << dp[i + 1][j] << " ";
    }
    cout << endl;
  }

  // 最小値が K 以下ならば、Yes
  if (dp[N][W] <= K)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  const std::string s = "hello";

  // 2番目から3要素だけ抜き出した部分文字列を取得する
  {
    std::string result = s.substr(2, 3);
    std::cout << result << std::endl;
  }
}
