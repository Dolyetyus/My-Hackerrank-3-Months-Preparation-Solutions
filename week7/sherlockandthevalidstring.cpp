#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) {
    map<char, int> chrmap;
    std::map<int, int> freqcount;
    int diff_freq = 0;
    string ret = "YES";
    
    for (auto chr: s){
        chrmap[chr]++;
    }
    
    for (const auto& entry : chrmap) {
        freqcount[entry.second]++;
    }
    
    if (freqcount.size() > 2){
        return "NO";
    }
    
    if (freqcount.size() == 2) {
        auto it = freqcount.begin();
        int freq1 = it->first;
        int count1 = it->second;
        ++it;
        int freq2 = it->first;
        int count2 = it->second;

        if ((freq1 == 1 && count1 == 1) || (freq2 == 1 && count2 == 1)) {
            return "YES";
        }

        if ((freq1 - freq2 == 1 && count1 == 1) || (freq2 - freq1 == 1 && count2 == 1)) {
            return "YES";
        }

        return "NO";
    }
    
    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
