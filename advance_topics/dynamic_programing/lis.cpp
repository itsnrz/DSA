#include <bits/stdc++.h>
using namespace std;

// This function prints the LIS sequence using the parent array.
// index is the last index of the LIS.
void showSequenceIterative(vector<int> &arr, vector<int> &parent, int index) {
    vector<int> sequence;

    // Move backward from the last LIS element to the first LIS element.
    // parent[index] tells which previous element came before arr[index].
    while(index != -1) {
        sequence.push_back(arr[index]);
        index = parent[index];
    }

    // We collected the sequence backward, so reverse it before printing.
    reverse(sequence.begin(), sequence.end());

    cout << "Longest Increasing Subsequence: ";
    for(int value : sequence) {
        cout << value << " ";
    }
    cout << endl;
}

int LIS(vector<int> &arr, int n) {
    // dp[i] stores the length of LIS ending at index i.
    // Initially every element alone is an LIS of length 1.
    vector<int> dp(n, 1);

    // parent[i] stores the previous index used before i in the LIS.
    // -1 means there is no previous index.
    vector<int> parent(n, -1);

    // Try to build LIS ending at every index i.
    for(int i = 1; i < n; i++) {
        // Check all elements before i.
        for(int j = 0; j < i; j++) {
            // If arr[j] is smaller, arr[i] can come after arr[j].
            // Also update only if this gives a longer LIS.
            if(arr[j] < arr[i] && 1 + dp[j] > dp[i]) {
                dp[i] = 1 + dp[j];

                // Store j as the previous element of i in the LIS.
                parent[i] = j;
            }
        }
    }

    // After the full dp array is ready, find the maximum LIS length.
    int answer = dp[0];
    int lastIndex = 0;

    for(int i = 1; i < n; i++) {
        if(dp[i] > answer) {
            answer = dp[i];

            // Store where the LIS ends so we can print the sequence.
            lastIndex = i;
        }
    }

    // Print one actual LIS sequence using the parent links.
    showSequenceIterative(arr, parent, lastIndex);

    return answer;
}

int main() {
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Length of Longest Increasing Subsequence: " << LIS(arr, n) << endl;

    return 0;
}
