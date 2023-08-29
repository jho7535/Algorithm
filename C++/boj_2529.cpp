// 부등호

#include <iostream>
#include <algorithm>

using namespace std;

int k;
char str[9];
int minArr[10] = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
int maxArr[10];
int temp[10];
bool flag[10] = {false}; // 0~9 정수. 사용되었으면 true

void inequal(int index);
bool bigger(int *arr);
bool smaller(int *arr);

int main()
{
    int i;
    cin >> k;
    for (i = 0; i < k; i++)
        cin >> str[i];

    inequal(0);

    for (i = 0; i <= k; i++)
        cout << maxArr[i];
    cout << endl;
    for (i = 0; i <= k; i++)
        cout << minArr[i];
    cout << endl;
}

void inequal(int index)
{
    if (index > k)
    {
        if (bigger(temp))
            copy(temp, temp + k + 1, maxArr);
        if (smaller(temp))
            copy(temp, temp + k + 1, minArr);
        return;
    }

    int i;
    if (index == 0)
    {
        for (i = 0; i < 10; i++)
        {
            temp[index] = i;
            flag[i] = true;
            inequal(index + 1);
            flag[i] = false;
        }
    }

    if (str[index - 1] == '<')
    {
        for (i = 0; i < 10; i++)
        {
            if (!flag[i] && temp[index - 1] < i)
            {
                temp[index] = i;
                flag[i] = true;
                inequal(index + 1);
                flag[i] = false;
            }
        }
        return;
    }
    else
    {
        for (i = 0; i < 10; i++)
        {
            if (!flag[i] && temp[index - 1] > i)
            {
                temp[index] = i;
                flag[i] = true;
                inequal(index + 1);
                flag[i] = false;
            }
        }
        return;
    }
}
bool bigger(int *arr)
{
    int i;
    for (i = 0; i <= k; i++)
    {
        if (arr[i] > maxArr[i])
            return true;
        else if (arr[i] < maxArr[i])
            return false;
    }
}
bool smaller(int *arr)
{
    int i;
    for (i = 0; i <= k; i++)
    {
        if (arr[i] > minArr[i])
            return false;
        else if (arr[i] < minArr[i])
            return true;
    }
}