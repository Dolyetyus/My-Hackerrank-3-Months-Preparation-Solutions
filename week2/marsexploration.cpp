#include <bits/stdc++.h>
#include <string> 

using namespace std;

/*
 * Complete the 'marsExploration' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int marsExploration(string s) {
    int num_msgs = s.size()/3;
    string compare = "";
    int faults = 0;
    
    for (int i = 0; i < num_msgs; i++){
        compare.insert(compare.size(), "SOS");
    }
    
    for (int i = 0; i < s.size(); i++){
        if (s[i] != compare[i]){
            faults++;
        }
    }
    return faults;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = marsExploration(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
