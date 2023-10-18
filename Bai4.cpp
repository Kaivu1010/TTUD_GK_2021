#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int res = 0;
    vector<int> array(n + 1);
    for (int i = 1; i <= n; i++) cin >> array[i];
    // dp[i] chứa tập con có tổng lớn nhất được tạo ra từ i phần tử đầu tiên 
    vector<int> dp(n + 1);
    // đặt trường hợp cơ sở
    dp[1] = array[1];
    dp[2] = max(array[1], array[2]);
    
    for (int i = 3; i <= n; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + array[i]);
    }

    cout << dp[n];
    return 0;
}
