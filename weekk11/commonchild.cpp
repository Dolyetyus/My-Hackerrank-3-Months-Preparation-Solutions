#include <bits/stdc++.h>

using namespace std;

/*int commonChild(string s1, string s2) {
    map<char, int> common;
    string modifiedS2;
    
    for (auto chr: s1){
        common[chr]++;
    }

    for (auto chr : s2) {
        if (common.find(chr)!=common.end() && common[chr]>0){
            common[chr]--;
            modifiedS2 += chr;
        }
    }

    s2 = modifiedS2;

    for (auto& [chr, count] : common) {
        s1.erase(remove(s1.begin(), s1.end(), chr), s1.end());
    }

    cout << "After removal: " << s2 << endl;
    
    return s2.length();
}*/

int commonChild(string s1, string s2) {
    int n = s1.length();
    vector<vector<int>> arr(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int ii = 1; ii <= n; ii++) {
            if (s1[i - 1] == s2[ii - 1]) {
                arr[i][ii] = arr[i - 1][ii - 1] + 1;
            } 
            else {
                arr[i][ii]=max(arr[i - 1][ii],arr[i][ii - 1]);
            }
        }
    }

    return arr[n][n];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
