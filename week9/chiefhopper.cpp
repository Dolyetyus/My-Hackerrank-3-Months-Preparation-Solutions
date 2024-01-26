#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


/*Apparently too slow for some tests:

int chiefHopper(vector<int> arr) {
    bool found = false;
    int start_energy = 0;
    
    while (!found){
        int bot_energy = start_energy;
        
        for (int i = 0; i<arr.size(); i++){
            if (bot_energy < arr.at(i)){
                bot_energy = bot_energy - (arr.at(i)-bot_energy);
                if (bot_energy<0){
                    break;
                }
            }
            else{
                bot_energy = bot_energy + (bot_energy-arr.at(i));
                if (bot_energy<0){
                    break;
                }
            }
            
            if (i==arr.size()-1){
                found = true;
            }
        }
        
        start_energy++;
    }
    
    return start_energy-1;
}*/

int chiefHopper(vector<int> arr) {
    int energy = 0;
    
    reverse(arr.begin(), arr.end());

    for (int i = 0; i<arr.size(); i++) {
        energy = ceil((energy + arr.at(i)) / 2.0);
    }

    return energy;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = chiefHopper(arr);

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
