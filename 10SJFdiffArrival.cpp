//Shortest Job First (SJF) Scheduling Algorithm with different arrival times.
#include <iostream>
#include <climits>
using namespace std;

int matrix[20][6];

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sortbyarrival(int noofprocess, int matrix[][6]) {
    for (int i = 0; i < noofprocess; i++) {
        for (int j = 0; j < noofprocess - i - 1; j++) {
            if (matrix[j][2] > matrix[j + 1][2]) {
                for (int k = 0; k < 6; k++) {
                    swap(&matrix[j][k], &matrix[j + 1][k]);
                }
            }
        }
    }
}

void timeofcompletion(int noofprocess, int matrix[][6]) {
    int current_time = 0;
    int completed = 0;
    int min_burst = INT_MAX;
    int shortest = 0;
    bool check = false;

    while (completed != noofprocess) {
        for (int i = 0; i < noofprocess; i++) {
            if (matrix[i][2] <= current_time && matrix[i][5] == 0) {
                if (matrix[i][1] < min_burst) {
                    min_burst = matrix[i][1];
                    shortest = i;
                    check = true;
                }
            }
        }

        if (check == false) {
            current_time++;
            continue;
        }

        matrix[shortest][1]--;
        min_burst = matrix[shortest][1];
        if (min_burst == 0) {
            min_burst = INT_MAX;
        }
        if (matrix[shortest][1] == 0) {
            completed++;
            check = false;
            int turnaround_time = current_time + 1 - matrix[shortest][2];
            matrix[shortest][5] = turnaround_time;
            matrix[shortest][4] = turnaround_time - matrix[shortest][3];
            if (matrix[shortest][4] < 0) {
                matrix[shortest][4] = 0;
            }
        }
        current_time++;
    }
}

int main() {
    int noofprocess;
    cout << "Enter the number of processes: ";
    cin >> noofprocess;

    for (int i = 0; i < noofprocess; i++) {
        cout << "\nProcess ID for process " << i + 1 << ": ";
        cin >> matrix[i][0];
        cout << "Burst time: ";
        cin >> matrix[i][1];
        cout << "Arrival time: ";
        cin >> matrix[i][2];
        matrix[i][3] = 0; // Initializing start time
        matrix[i][4] = 0; // Initializing waiting time
        matrix[i][5] = 0; // Initializing turnaround time
    }

    sortbyarrival(noofprocess, matrix);
    timeofcompletion(noofprocess, matrix);

    cout << "\nP.ID\tA.T\tB.T\tW.T\tTAT\n" << endl;
    for (int i = 0; i < noofprocess; i++) {
        cout << matrix[i][0] << "\t" << matrix[i][2] << "\t" << matrix[i][1] << "\t" << matrix[i][4] << "\t" << matrix[i][5] << endl;
    }

    return 0;
}
