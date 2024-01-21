#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
    vector<int> ret;
    sort(ranked.begin(), ranked.end());
    ranked.erase(unique(ranked.begin(), ranked.end() ), ranked.end());
    
    for (int i = 0; i < player.size(); i++){
        for (int ii = 0; ii < ranked.size(); ii++){
            if (player.at(i) > ranked.at(ranked.size()-1)){
                ret.push_back(1);
                break;
            }
            else if (player.at(i) < ranked.at(ii)){
                ret.push_back(ranked.size()-ii+1);
                break;
            }
        }
    }
    
    return ret;
}*/

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
    vector<int> ret;
    ranked.erase(unique(ranked.begin(), ranked.end()), ranked.end());

    for (int i = 0; i < player.size(); i++) {
        int playerRank = 1;
        int low = 0;
        int high = ranked.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (ranked.at(mid) == player.at(i)) {
                playerRank = mid + 1;
                break;
            } 
            else if (ranked.at(mid) > player.at(i)) {
                playerRank = mid + 2;
                low = mid + 1;
            } 
            else {
                high = mid - 1;
            }
        }
        ret.push_back(playerRank);
    }
    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string ranked_count_temp;
    getline(cin, ranked_count_temp);

    int ranked_count = stoi(ltrim(rtrim(ranked_count_temp)));

    string ranked_temp_temp;
    getline(cin, ranked_temp_temp);

    vector<string> ranked_temp = split(rtrim(ranked_temp_temp));

    vector<int> ranked(ranked_count);

    for (int i = 0; i < ranked_count; i++) {
        int ranked_item = stoi(ranked_temp[i]);

        ranked[i] = ranked_item;
    }

    string player_count_temp;
    getline(cin, player_count_temp);

    int player_count = stoi(ltrim(rtrim(player_count_temp)));

    string player_temp_temp;
    getline(cin, player_temp_temp);

    vector<string> player_temp = split(rtrim(player_temp_temp));

    vector<int> player(player_count);

    for (int i = 0; i < player_count; i++) {
        int player_item = stoi(player_temp[i]);

        player[i] = player_item;
    }

    vector<int> result = climbingLeaderboard(ranked, player);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
