#include <iostream>
#include <vector>

using namespace std;

const int MAX_PROCESS = 10;
const int MAX_RESOURCE = 10;

// Function to calculate need matrix
void calculateNeedMatrix(int need[MAX_PROCESS][MAX_RESOURCE], int maxNeed[MAX_PROCESS][MAX_RESOURCE], int allocation[MAX_PROCESS][MAX_RESOURCE], int n, int m)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            need[i][j] = maxNeed[i][j] - allocation[i][j];
}

int main()
{
    int n, m;
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the number of resources: ";
    cin >> m;

    int processes[MAX_PROCESS];
    int available[MAX_RESOURCE];
    int maxNeed[MAX_PROCESS][MAX_RESOURCE];
    int allocation[MAX_PROCESS][MAX_RESOURCE];
    int need[MAX_PROCESS][MAX_RESOURCE];

    cout << "Enter the allocation matrix: " << endl;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> allocation[i][j];

    cout << "Enter the maximum matrix: " << endl;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> maxNeed[i][j];

    cout << "Enter the available resources: ";
    for (int i = 0; i < m; ++i)
        cin >> available[i];

    // Calculate and print the need matrix
    calculateNeedMatrix(need, maxNeed, allocation, n, m);
    cout << "Need Matrix: " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << need[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
