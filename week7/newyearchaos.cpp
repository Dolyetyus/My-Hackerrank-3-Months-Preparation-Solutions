#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


/*This solution is using bubble sort and has apparently a high time complexity(?)
and fails hackerrank's tests that has big inputs (timeout)*/
/*
void minimumBribes(vector<int> q) {
    int n = q.size();
    vector<int> swaps(n+1);
    bool is_chaotic = false;
    int sum = 0;

    for (int i = 0; i < n - 1; i++) {
        if (q.at(i) - i > 3){
            is_chaotic = true;
            cout<<"Too chaotic"<<endl;
            break;
        }
        for (int j = 0; j < n - i - 1; j++) {
            if (q.at(j) > q.at(j + 1)) {
                swaps.at(q.at(j))++;
                swap(q.at(j), q.at(j + 1));
            }
        }
        if (is_chaotic) {break;}
    }
        
    if (!is_chaotic){
        for (int i = 0; i < swaps.size(); i++) {
            if (swaps.at(i) > 2){
                is_chaotic = true;
                break;
            }
            sum += swaps.at(i);
        }
        
        cout<<sum<<endl;
    }
}*/

//More optimal solution:

void minimumBribes(std::vector<int> q) {
    int swaps = 0;
    
    for (int i = 0; i < q.size(); i++) {
        int val = q.at(i);
        
        if (val - i > 3) {
            cout<<"Too chaotic"<<endl;
            return;
        }
        
        int j = i - 1;
        for (; j >= 0 && q.at(j) > val; j--) {
            q.at(j + 1) = q.at(j);
            swaps++;
        }
        q.at(j+1) = val;
    }
    
    cout<<swaps<<endl;
}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split(rtrim(q_temp_temp));

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        minimumBribes(q);
    }

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
