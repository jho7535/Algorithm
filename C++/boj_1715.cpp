// 카드 정렬하기

#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int n;

int main()
{
    int i, input, sum, s = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> input;
        pq.push(input);
    }

    for (i = 0; i < n - 1; i++)
    {
        sum = 0;
        sum += pq.top();
        pq.pop();
        sum += pq.top();
        pq.pop();
        s += sum;
        pq.push(sum);
    }

    cout << s << endl;
}