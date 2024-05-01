#include <iostream>
using namespace std;

void swap(int *a, int *b){
    int x = *a;
    *a = *b;
    *b = x;
}

int main(){
    int x; // Number of Processes
    cout << "Enter number of Processes: ";
    cin >> x;
    int a[10];    // Arrival Time
    int b[10];    // Burst Time
    int s[10];    // Service Time
    int w[10];    // Waiting Time
    int t[10];    // TAT
    float aw = 0; // Total Wait Time
    float at = 0; // Total TAT

    for (int i = 0; i < x; i++){
        cout << "\nEnter Arrival Time " << i + 1 << ": ";
        cin >> a[i];
        cout << "Enter Burst Time " << i + 1 << ": ";
        cin >> b[i];
    }

    s[0] = 0;

    for (int i = 1; i < x; i++){
        s[i] = s[i - 1] + b[i - 1];
    }

    for (int i = 0; i < x; i++){
        int min = i;
        for (int j = i; j < x; j++){
            if (a[j] < a[min]){
                swap(&a[j], &a[min]);
                swap(&b[j], &b[min]);
                swap(&s[j], &s[min]);
            }
        }
    }

    for (int i = 0; i < x; i++){
        w[i] = s[i] - a[i];
        t[i] = w[i] + b[i];
    }

    for (int i = 0; i < x; i++){
        aw = aw + w[i];
        at = at + t[i];
    }

    cout << "\nP.ID\tA.T\tB.T\tS.T\tWT\tTAT\n";

    for (int i = 0; i < x; i++){
        cout << i + 1 << "\t" << a[i] << "\t" << b[i] << "\t" << s[i] << "\t" << w[i] << "\t" << t[i] << "\n";
    }

    cout << "\nAVERAGE WAIT TIME (AWT):" << aw / x << endl;
    cout << "AVERAGE TURN AROUND TIME (ATAT):" << at / x << endl;
}