#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string pangrams(string s) {
    unordered_map<char, int> M;
    
    for (char ch : s) {
        if (isalpha(ch)) {
            char lowercaseCh = tolower(ch);
            if (M.find(lowercaseCh) == M.end()) {
                M[lowercaseCh] = 1;
            } else {
                M[lowercaseCh]++;
            }
        }
    }

    for (char letter = 'a'; letter <= 'z'; letter++) {
        if (M.find(letter) == M.end()) {
            return "not pangram";
        }
    }
    return "pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
