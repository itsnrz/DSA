#include <bits/stdc++.h>
using namespace std;

// This function prints the LCS by following the direction matrix recursively.
// We start from direction[n][m] and move back toward direction[0][0].
void printLCS(vector<vector<char>> &direction, string &s1, int i, int j) {
    // If any string becomes empty, there is nothing left to print.
    if(i == 0 || j == 0)
        return;

    // 'h' means both characters matched, so the LCS came from diagonal.
    if(direction[i][j] == 'h') {
        // First print the previous part of LCS.
        printLCS(direction, s1, i-1, j-1);

        // Then print current matching character.
        // We use i-1 because string indexing starts from 0.
        cout << s1[i-1];
    }
    // 'u' means the value came from the upper cell, so move up.
    else if(direction[i][j] == 'u') {
        printLCS(direction, s1, i-1, j);
    }
    // 'l' means the value came from the left cell, so move left.
    else {
        printLCS(direction, s1, i, j-1);
    }
}

int LCS(string &s1, string &s2, int n, int m) {
    // dp[i][j] stores the length of LCS of:
    // first i characters of s1 and first j characters of s2.
    // Size is n+1 and m+1 to include empty string cases at row 0 and column 0.
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    // direction matrix stores from where dp[i][j] got its value:
    // 'h' = diagonal, 'u' = up, 'l' = left, '-' = base cell.
    vector<vector<char>> direction(n+1, vector<char>(m+1, '-'));

    // Fill the dp table from smaller subproblems to bigger subproblems.
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            // If current characters match, include this character in LCS.
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                direction[i][j] = 'h';
            }
            // If characters do not match, take the better answer from up or left.
            else if(dp[i-1][j] >= dp[i][j-1]) {
                dp[i][j] = dp[i-1][j];
                direction[i][j] = 'u';
            }
            else {
                dp[i][j] = dp[i][j-1];
                direction[i][j] = 'l';
            }
        }
    }

    cout << "\nLongest Common Subsequence: ";
    printLCS(direction, s1, n, m);
    cout << endl;

    // dp[n][m] contains the LCS length of the full strings.
    return dp[n][m];
}

int main() {

    string s1, s2;

    cout << "Enter first string: ";
    cin >> s1;

    cout << "Enter second string: ";
    cin >> s2;

    int length = LCS(s1, s2, s1.length(), s2.length());

    cout << "Length of Longest Common Subsequence: " << length << endl;

    return 0;
}
