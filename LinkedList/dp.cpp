
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vec.push_back(x);
    }

    int dp[500] = {0};

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            dp[i] = vec[i];
        }
        else if (i == 1)
        {
            dp[i] = max(vec[0], vec[1]);
        }
        else
        {
            dp[i] = max(vec[i] + dp[i - 2], dp[i - 1]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << " " << dp[i] << endl;
    }
}