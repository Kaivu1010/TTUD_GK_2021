#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,k,m, res = 0; cin >> n >> k >> m;
    vector<int> array(n + 1);
    // dp[i] là tổng của i phần tử liên tiếp tính từ phần tử thứ 1
    vector<int> dp(n + 1);
    for (int i = 1; i <= n;i++) cin >> array[i];
    for (int i = 1; i <= n;i++) dp[i] = dp[i - 1] + array[i];
    for (int i = k; i <= n;i++) 
    {
        if (dp[i] - dp[i - k] == m) res++;
    }
    cout << res;
    
}