// dijsktras.cpp
using namespace std;
#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<utility>
#include<deque>
int main(int argc, char *argv[])
{
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
    int tmp;
    int totalCost;
    vector<char> tileNames;
    vector<char> tileCosts;
    vector<vector<int>> map;

    cin >> tileN;
    for(int i = 0; i < tileN; i++)
    {
        cin >> tileName;
        cin >> tileCost;
        tileNames.push_back(tileName);
        tileCosts.push_back(tileCost);
    }
    cin >> mapRows;
    cin >> mapCols;

    vector<vector<int>> distances;
    
    distances.resize(mapRows);
    map.resize(mapRows);
    for(int i = 0; i < mapRows; i++)
    {
        map[i].resize(mapCols);
        distances[i].resize(mapCols);
        for(int j = 0; j < mapCols; j++)
        {
            cin >> tile;
            for(int k = 0; k < (int)tileNames.size(); ++k)
            {
                if(tileNames[k] == tile)
                {
                    tmp = tileCosts[k];
                }
                map[i][j] = tmp;
                distances[i][j] = tmp;
            }
            //cout << distances[i][j] << " ";
        }
        //cout << endl;
    }

    cin >> startRow;
    cin >> startCol;
    cin >> endRow;
    cin >> endCol;

    deque<int> frontier;
    deque<int> frontierRow;
    deque<int> frontierCol;
    vector<int> markedRow;
    vector<int> markedCol;
    int row = startRow;
    int col = startCol;
    bool marked = false;

    while(markedRow.size() != startRow*startCol){
        if(row!=0){
            for(int i = 0; i < (int)markedRow.size(); i++){
                if(markedRow[i] == row-1 && markedCol[i] == col){
                    marked = true;
                }
            }
            if(marked == false){
                frontier.push_back(map[row-1][col]);
                frontierRow.push_back(row-1);
                frontierCol.push_back(col);
            }
        }
        marked = false;
        if(row != mapRows-1){
            for(int i = 0; i < (int)markedRow.size(); i++){
                if(markedRow[i] == row+1 && markedCol[i] == col){
                    marked = true;
                }
            }
            if(marked == false){
                frontier.push_back(map[row+1][col]);
                frontierRow.push_back(row+1);
                frontierCol.push_back(col);
            }
        }
        marked = false;
        if(col!=0){
            for(int i = 0; i < (int)markedRow.size(); i++){
                if(markedRow[i] == row && markedCol[i] == col-1){
                    marked = true;
                }
            }
            if(marked == false){
                frontier.push_back(map[row][col-1]);
                frontierRow.push_back(row);
                frontierCol.push_back(col-1);
            }
        }
        marked = false;
        if(col != mapCols-1){
            for(int i = 0; i < (int)markedRow.size(); i++){
                if(markedRow[i] == row && markedCol[i] == col+1){
                    marked = true;
                }
            }
            if(marked == false){
                frontier.push_back(map[row][col+1]);
                frontierRow.push_back(row);
                frontierCol.push_back(col+1);
            }
        }
    }
    return 0;

}
