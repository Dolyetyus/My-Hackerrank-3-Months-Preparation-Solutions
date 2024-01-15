#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {    
    string firstTwo = s.substr(0, 2);
    int hour = stoi(firstTwo);
    
    if (s.substr(s.length() - 2) == "PM"){
        if (hour == 12){}
        else{
            hour += 12;
            s.replace(0, 2, std::to_string(hour));
        }
    }
    else if (s.substr(s.length() - 2) == "AM"){
        if (hour == 12){
            s.replace(0, 2, "00");
        }
    }
    
    return s.substr(0, 8);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
