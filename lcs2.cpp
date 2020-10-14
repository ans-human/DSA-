#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
using std::vector;

int lcs2(vector<int> &a, vector<int> &b) {
  int m = a.size();
  int n = b.size();
 // cout<<m<<" "<<n<<endl;
  //vector<int> c;
  int dp[m+1][n+1];
  /*for(auto c:a) cout<<c<<" ";
  cout<<endl;
  for(auto c:b) cout<<c<<" ";
  cout<<endl;
  */
  memset(dp, 0, sizeof(dp));
  for(int i=0; i<=m; i++){
    for(int j=0; j<=n; j++)
    cout<<dp[i][j]<<" ";

    cout<<endl;
  }

  for(int i=1; i<=m; i++){
    for(int j=1; j<=n; j++){

      if( a[i-1] == b[j-1]){
        dp[i][j] = 1+dp[i-1][j-1];
        //c.push_back(a[i-1]);
      }

      else{
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }
  return dp[m][n];
  //return std::min(std::min(a.size(), b.size()), c.size());
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
