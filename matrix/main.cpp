#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    int width, height;
    cin >> width; cin.ignore();
    cin >> height; cin.ignore();

    // Right neighbours
    vector<vector<int>> table(height, vector<int>(width, -1));

    vector<int> rightests(height, -1);
    vector<int> lowests(width, -1);

    for (int i = 0; i < height; ++i) {
        string line;
        getline(cin, line);
        int rightest = -1;
        for (int j = 0; j < width; ++j) {
            // Inserting
            if (line[j] == '0') {
                if (rightest != -1)
                    table[i][rightest] = j;
                rightest = j;
                int lowest_j = lowests[j];
                if (lowest_j != -1) {
                    cout << j << " " << lowest_j << " ";
                    if (rightests[lowest_j] == j)
                        cout << "-1 -1 ";
                    else
                        cout << table[lowest_j][j] << " " << lowest_j << " ";
                    cout << j << " " << i << endl;
                }
                lowests[j] = i;
            }
        }
        rightests[i] = rightest;
    }
    for (int j = 0; j < width; ++j) {
        int lowest_j = lowests[j];
        if (lowest_j != -1) {
            cout << j << " " << lowest_j << " ";
            if (rightests[lowest_j] == j)
                cout << "-1 -1 ";
            else
                cout << table[lowest_j][j] << " " << lowest_j << " ";
            cout << "-1 -1" << endl;
        }
    }
}
