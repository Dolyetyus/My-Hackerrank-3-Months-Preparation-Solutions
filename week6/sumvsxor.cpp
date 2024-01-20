#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*Apparently time complexity of this solution is too high
and since hackerrank loves very big numbers, it fails some
tests (30% of tests) due to its time complexity

long sumXor(long n) {
    long counter = 0;
    for (long i = 0; i <= n; i++){
        if ((n + i) == (n ^ i)){
            counter++;
        }
    }
    
    return counter;
}*/

//Here is the optimal solution:
long sumXor(long n) {
    long counter = 0;

    while (n > 0) {
        if ((n & 1) == 0) {
            counter++;
        }
        n >>= 1;
    }

    return 1L << counter;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    long n = stol(ltrim(rtrim(n_temp)));

    long result = sumXor(n);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
