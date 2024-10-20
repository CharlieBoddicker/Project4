// dijsktras.cpp
using namespace std;
#include<iostream>
#include<vector>

int main(int argc, char *argv[]) {
    int tileN;
    char tileName;
    int tileCost;
    int mapRows;
    int mapCols;
    char tile;
    int startRow;
    int startCol;
    int endRow;
    int endCol;
    vector<char> tileNames;
    vector<char> tileCosts;
    vector<vector<int>> map;

    cin >> tileN;
    for(int i = 0; i < tileN; i++){
        cin >> tileName;
        cin >> tileCost;
        tileNames.push_back(tileName);
        tileCosts.push_back(tileCost);
    }
    cin >> mapRows;
    cin >> mapCols;

    map.resize(mapRows);
    for(int i = 0; i < mapRows; i++){
        map[i].resize(mapCols);
        for(int j = 0; j < mapCols; j++){
            cin >> tile;
            map[i][j] = tile;
        }
    }

    cin >> startRow;
    cin >> startCol;
    cin >> endRow;
    cin >> endCol;

    return 0;

}
