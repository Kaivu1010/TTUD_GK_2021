#include <iostream>
#include <queue>
using namespace std;
int main() {
    int n; cin >> n;
    // sử dụng hàng đợi ưu tiên vì độ phức tạp khi chèn và xóa phần tử lớn nhất của nó thấp
    priority_queue<int> pqueue;
    for (int i = 0; i < n;i++) 
    {
        int temp; cin >> temp;
        pqueue.push(temp);
    }
    string s;
    while (cin >> s)
    {
        if (s == "insert")
        {
            int temp; cin >> temp;
            pqueue.push(temp);
        }
        else 
        {
            cout << pqueue.top() << endl;
            pqueue.pop();
        }
    }
    
    return 0;
}
