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
    vector<int> tileCosts;
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
    frontier.push({-0,{startRow,startCol}});
    std::map<pair<int,int>, int> marked;
    while(!frontier.empty())  
    {
        auto it = frontier.top();
        int weight = -it.first;
        int row = it.second.first;
        int col = it.second.second;
        frontier.pop();
        if(marked.find({row,col}) != marked.end())
        {
            continue;
        }
        marked.insert({{row,col},weight});
        if(row == endRow && col == endCol)
        {
            cout << weight << endl;
            break;
        }
        for(int i = 0; i < 1; ++i)
        {
            for(int j = 0; j < 1; ++j)
            {
                int newRow = i;
                int newCol = j;
                if(i == 0 && j == 0)
                {
                    continue;
                }
                
            }
        }

        
    }
    return 0;

}
