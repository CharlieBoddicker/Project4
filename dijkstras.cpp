// Owen Youngblood, Charles Boddicker
// project 4 Path Finding
// this code finds the shortest path between a start and end point on a 2d grid representing a playing field.
// references: https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/
//             https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/
               
using namespace std;
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>

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
    vector<char> tileNames;
    vector<int> tileCosts;
    vector<vector<int>> map;
    vector<vector<int>> distances;

    cin >> tileN;
    for (int i = 0; i < tileN; i++)
    {
        cin >> tileName;
        cin >> tileCost;
        tileNames.push_back(tileName);
        tileCosts.push_back(tileCost);
    }
    cin >> mapRows;
    cin >> mapCols;

    map.resize(mapRows);
    distances.resize(mapRows);
    //fill 2d map vector with the weights of the cells.
    for (int i = 0; i < mapRows; i++)
    {
        map[i].resize(mapCols);
        distances[i].resize(mapCols, -1);
        for (int j = 0; j < mapCols; j++)
        {
            cin >> tile;
            for (int k = 0; k < tileNames.size(); ++k)
            {
                if (tileNames[k] == tile)
                {
                    tmp = tileCosts[k];
                }
                map[i][j] = tmp;
            }
        }
    }

    cin >> startRow;
    cin >> startCol;
    cin >> endRow;
    cin >> endCol;

    priority_queue<pair<int, pair<int, int>>> frontier;//to store in the format <weight,<row,column>>
    frontier.push({0, {startRow, startCol}});
    std::map<pair<int, int>, int> marked;//node -> weight 
    std::map<pair<int, int>, pair<int, int>> previous;//to track the previous cell so we can backtrack
    distances[startRow][startCol] = 0;
    //dijkstra's algorithm
    while (!frontier.empty())  
    {
        auto it = frontier.top();
        int weight = -it.first;
        int row = it.second.first;
        int col = it.second.second;
        frontier.pop();    
        if (marked.find({row, col}) != marked.end())
        {
            continue;
        }    
        marked.insert({{row, col}, weight});
        if (row == endRow && col == endCol)
        {
            break;
        }

        //up
        if (row > 0)
        {
            int newRow = row - 1;
            int newCol = col;
            int newWeight = weight + map[newRow][newCol];
            if (distances[newRow][newCol] == -1 || newWeight < distances[newRow][newCol])
            {
                distances[newRow][newCol] = newWeight;
                frontier.push({-newWeight, {newRow, newCol}});
                previous[{newRow, newCol}] = {row, col};
            }
        }

        //down
        if (row < mapRows - 1)
        {
            int newRow = row + 1;
            int newCol = col;
            int newWeight = weight + map[newRow][newCol];
            if (distances[newRow][newCol] == -1 || newWeight < distances[newRow][newCol])
            {
                distances[newRow][newCol] = newWeight;
                frontier.push({-newWeight, {newRow, newCol}});
                previous[{newRow, newCol}] = {row, col};
            }
        }

        //right
        if (col < mapCols - 1)
        {
            int newRow = row;
            int newCol = col + 1;
            int newWeight = weight + map[newRow][newCol];
            if (distances[newRow][newCol] == -1 || newWeight < distances[newRow][newCol])
            {
                distances[newRow][newCol] = newWeight;
                frontier.push({-newWeight, {newRow, newCol}});
                previous[{newRow, newCol}] = {row, col};
            }
        }

        //left
        if (col > 0)
        {
            int newRow = row;
            int newCol = col - 1;
            int newWeight = weight + map[newRow][newCol];
            if (distances[newRow][newCol] == -1 || newWeight < distances[newRow][newCol])
            {
                distances[newRow][newCol] = newWeight;
                frontier.push({-newWeight, {newRow, newCol}});
                previous[{newRow, newCol}] = {row, col};
            }
        }
    }

    //backtrack to find the path
    vector<int> pathRows;
    vector<int> pathCols;
    int currentRow = endRow;
    int currentCol = endCol;

    if (marked.find({endRow, endCol}) != marked.end()) 
    {
        while (currentRow != startRow || currentCol != startCol) 
        {
            pathRows.push_back(currentRow);
            pathCols.push_back(currentCol);
            auto prev = previous[{currentRow, currentCol}];
            currentRow = prev.first;
            currentCol = prev.second;
        }
        pathRows.push_back(startRow);
        pathCols.push_back(startCol);
    }

    int totalWeight = distances[endRow][endCol]; //get the distance to the destination
    totalWeight += map[startRow][startCol]; //include cost of leaving starting tile
    totalWeight -= map[endRow][endCol]; //exclude cost of leaving destination tile
    cout << totalWeight << endl;
    //print the path in reverse order
    for (int i = pathRows.size() - 1; i >= 0; i--) 
    {
        cout << pathRows[i] << " " << pathCols[i] << endl;
    }

    return 0;
}
