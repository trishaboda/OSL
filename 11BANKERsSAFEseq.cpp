#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m, i, j, k;
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the number of resources: ";
    cin >> m;

    vector<vector<int>> alloc(n, vector<int>(m));
    vector<vector<int>> max(n, vector<int>(m));
    vector<int> avail(m);

    cout << "Enter the allocation matrix:\n";
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> alloc[i][j];

    cout << "Enter the maximum matrix:\n";
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> max[i][j];

    cout << "Enter the available resources:\n";
    for (i = 0; i < m; i++)
        cin >> avail[i];

    vector<int> f(n, 0), ans;

    vector<vector<int>> need(n, vector<int>(m));
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (f[i] == 0)
            {
                bool flag = true;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    ans.push_back(i);
                    for (int y = 0; y < m; y++)
                    {
                        avail[y] += alloc[i][y];
                    }
                    f[i] = 1;
                }
            }
        }
    }

    // Check if system is in a safe state
    bool safe = true;
    for (i = 0; i < n; i++)
    {
        if (f[i] == 0)
        {
            safe = false;
            break;
        }
    }

    if (safe)
    {
        cout << "Following is the SAFE Sequence:\n";
        for (i = 0; i < n - 1; i++)
            cout << " P" << ans[i] << " ->";
        cout << " P" << ans[n - 1] << endl;
    }
    else
    {
        cout << "The system is NOT in a safe state." << endl;
    }

    return 0;
}
