#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n,A,B; cin >> n >> A >> B;
    vector<int> array(n);
    for (int i = 0; i < n;i++) cin >> array[i];
    // dp[i][j] sẽ lưu số lượng tập con có tổng là j
    // mà có thể được tạo từ i phần tử đầu tiên của mảng
    vector<vector<int>> dp(n + 1, vector<int>(B + 1, 0));

    // Khởi tạo dp[i][0] = 1 vì có một tập con rỗng
    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= B; ++j) {
            // Nếu số hiện tại lớn hơn tổng j, thì không bao gồm nó
            if (array[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - array[i - 1]];
        }
    }

    // Đếm số lượng tập con có tổng từ A đến B
    int count = 0;
    for (int i = A; i <= B; ++i) count += dp[n][i];
    cout << count;
    return 0;
}
