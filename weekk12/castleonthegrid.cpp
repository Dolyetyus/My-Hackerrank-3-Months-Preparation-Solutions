#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/* Did not work fast enough using recursive backtracker :(
     
int move(vector<string>& grid, int currentX, int currentY, int goalX, int goalY, int moves) {
    if (currentX == goalX && currentY == goalY) {
        return moves;
    }

    grid[currentX][currentY] = 'X';

    int minMoves = INT_MAX;

    for (int i = currentY + 1; i < grid.size() && grid[currentX][i] != 'X'; i++) {
        minMoves = min(minMoves, move(grid, currentX, i, goalX, goalY, moves + 1));
    }
    for (int i = currentY - 1; i >= 0 && grid[currentX][i] != 'X'; i--) {
        minMoves = min(minMoves, move(grid, currentX, i, goalX, goalY, moves + 1));
    }

    for (int i = currentX + 1; i < grid.size() && grid[i][currentY] != 'X'; i++) {
        minMoves = min(minMoves, move(grid, i, currentY, goalX, goalY, moves + 1));
    }
    for (int i = currentX - 1; i >= 0 && grid[i][currentY] != 'X'; i--) {
        minMoves = min(minMoves, move(grid, i, currentY, goalX, goalY, moves + 1));
    }

    grid[currentX][currentY] = '.';

    return minMoves;
}


int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
    return move(grid, startX, startY, goalX, goalY, 0);
}*/

int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
    int n = grid.size();

    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};

    vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
    distance[startX][startY] = 0;

    queue<pair<int, int>> q;
    q.push({startX, startY});

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            while (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] != 'X') {
                if (distance[nx][ny] == INT_MAX) {
                    distance[nx][ny] = distance[x][y] + 1;
                    q.push({nx, ny});

                    if (nx == goalX && ny == goalY) {
                        return distance[nx][ny];
                    }
                }
                nx += dx[dir];
                ny += dy[dir];
            }
        }
    }

    return 0;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int startX = stoi(first_multiple_input[0]);

    int startY = stoi(first_multiple_input[1]);

    int goalX = stoi(first_multiple_input[2]);

    int goalY = stoi(first_multiple_input[3]);

    int result = minimumMoves(grid, startX, startY, goalX, goalY);

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
