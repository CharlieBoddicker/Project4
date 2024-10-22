// dijsktras.cpp
using namespace std;
#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<utility>
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

    map.resize(mapRows);
    for(int i = 0; i < mapRows; i++)
    {
        map[i].resize(mapCols);
        for(int j = 0; j < mapCols; j++)
        {
            cin >> tile;
            for(int k = 0; k < tileNames.size(); ++k)
            {
                if(tileNames[k] == tile)
                {
                    tmp = tileCosts[k];
                }
                map[i][j] = tmp;
            }
            cout << map[i][j] << " ";
        }
        cout << endl;
    }

    cin >> startRow;
    cin >> startCol;
    cin >> endRow;
    cin >> endCol;
    priority_queue<pair<int,pair<int,int> > > frontier;
    frontier.push({0,{startRow,startCol}});
    std::map<int,int> marked;
    while(!frontier.empty());  
    {
        auto it = frontier.top();
        int weight = it.first;
        int from = it.second.first;
        int to = it.second.second;
        frontier.pop();
        if(marked.find(from) != marked.end())
        {
            
        }
        
    }
    return 0;

}
