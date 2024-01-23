#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'bomberMan' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING_ARRAY grid
 */
 
 //This took me 2 hours, no way this is "medium"

void transfer(vector<string> &grid){
    for (int idx = 0; idx<grid.size(); idx++){
        string &str = grid.at(idx);
        for (int chr = 0; chr<str.size(); chr++){
            if (str[chr] == '0'){
                str[chr] = '.';
            }
            else{
                str[chr] = 'O';
            }
        }
    }
}

void fillBoard(vector<string> &grid){
    for (int idx = 0; idx<grid.size(); idx++){
        string &str = grid.at(idx);
        for (int chr = 0; chr<str.size(); chr++){
            str[chr] = 'O';
        }
    }
}

void convertBoard(vector<string> &grid){
    for (int idx = 0; idx<grid.size(); idx++){
        string &str = grid.at(idx);
        for (int chr = 0; chr<str.size(); chr++){
            if (str[chr] == 'O'){
                str[chr] = '4';
            }
            else{
                str[chr] = '9';
            }
        }
    }
}

void bombs(vector<string> &grid){
    int rows = grid.size();
    int cols = grid[0].size();
    
    vector<string> originalGrid = grid;

    for (int idx = 0; idx < rows; idx++){
        string &str = originalGrid.at(idx);
        for (int chr = 0; chr < cols; chr++){
            if (originalGrid[idx][chr] == '1') {
                grid[idx][chr] = '0';
                if (idx > 0 && originalGrid[idx - 1][chr] != '1') {
                    grid[idx - 1][chr] = '0';
                }
                if (idx < rows - 1 && originalGrid[idx + 1][chr] != '1') {
                    grid[idx + 1][chr] = '0';
                }
                if (chr > 0 && originalGrid[idx][chr - 1] != '1') {
                    grid[idx][chr - 1] = '0'; 
                }
                if (chr < cols - 1 && originalGrid[idx][chr + 1] != '1') {
                    grid[idx][chr + 1] = '0';
                }
            }
        }
    }
}

void updateBoard(vector<string> &grid){
    int rows = grid.size();
    int cols = grid[0].size();
    
    for (int idx = 0; idx < rows; idx++){
        string &str = grid.at(idx);
        for (int chr = 0; chr < cols; chr++){
            if (str[chr] == '9'){
                str[chr] = '0';
            }
            else if (str[chr] == '0'){
                str[chr] = '4';
            }
            else if (grid[idx][chr] > '1') {
                int value = str[chr] - '0' -1;
                str[chr] = value + '0';
            }
        }
    }
    
    bombs(grid);
}

vector<string> bomberMan(int n, vector<string> grid) {
    if (n < 2) {
        return grid;
    }

    if (n % 2 == 0) {
        fillBoard(grid);
        return grid;
    }

    convertBoard(grid);
    n--;
    if (n%4==2){
        n=3;
    }
    else{
        n=5;
    }
    
    while (n>0){
        updateBoard(grid);
        n--;
    }

    transfer(grid);
    return grid;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int r = stoi(first_multiple_input[0]);

    int c = stoi(first_multiple_input[1]);

    int n = stoi(first_multiple_input[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

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
