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
	vector<vector<int>>	distances;

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
	distances.resize(mapRows);
    for(int i = 0; i < mapRows; i++)
    {
        map[i].resize(mapCols);
		distances[i].resize(mapCols);
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
				distances[i][j] = -1;
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
	priority_queue<pair<int,pair<int,int> > > prevFrontier;
    frontier.push({0,{startRow,startCol}});
	prevFrontier.push({0,{startRow,startCol}});
    std::map<pair<int,int>, int> marked;
	distances[startRow][startCol] = 0;
	int previousRow;
	int previousCol;
	int counter = 0;
    
	while(!frontier.empty())  
    {
		counter++;
        auto it = frontier.top();
        int weight = -it.first;
        int row = it.second.first;
        int col = it.second.second;
		
		it = prevFrontier.top();
		previousRow = it.second.first;
		previousCol = it.second.second;

		bool check = false;
        frontier.pop();
		prevFrontier.pop();
		//cout << weight << endl;
		//cout << row << " ";
		//cout << col << endl;
		
        if(marked.find({row,col}) != marked.end())
        {
            continue;
        }
		
        marked.insert({{row,col},weight});
		

		if (counter!=1) distances[row][col] = (map[previousRow][previousCol]) + (distances[previousRow][previousCol]);
		else distances[row][col] = 0;
        /*
		if(row == endRow && col == endCol)
        {
            //cout << weight << endl;
            break;
        }
		*/
		/*
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
		*/
		if(row!=0){
			if(marked.find({row-1,col}) != marked.end())
			{
				check = true;
			}
            if(check == false){
                frontier.push({-map[row-1][col],{row-1,col}});
				prevFrontier.push({-map[row-1][col],{row,col}});
				cout << row-1 << " " << col << " ";
            }
        }
        check = false;
        if(row != mapRows-1){
            if(marked.find({row+1,col}) != marked.end())
            {
                check = true;
            }
            if(check == false){
                frontier.push({-map[row+1][col],{row+1,col}});
				prevFrontier.push({-map[row+1][col],{row,col}});
				cout << row+1 << " " << col << " ";
            }
        }
        check = false;
        if(col!=0){
            if(marked.find({row,col-1}) != marked.end())
            {
                check = true;
            }
            if(check == false){
                frontier.push({-map[row][col-1],{row,col-1}});
				prevFrontier.push({-map[row][col-1],{row,col}});
				cout << row << " " << col-1 << " ";
            }
        }
        check = false;
        if(col != mapCols-1){
            if(marked.find({row,col+1}) != marked.end())
            {
                check = true;
            }
            if(check == false){
                frontier.push({-map[row][col+1],{row,col+1}});
				prevFrontier.push({-map[row][col+1],{row,col}});
				cout << row << " " << col+1 << " ";
            }
        }
		cout << endl;
		check = false;



        
    }
	for(int i = 0; i < mapRows; i ++){
		for(int j = 0; j < mapCols; j++){
			cout << distances[i][j] << " ";
		}
		cout << endl;
	}
    return 0;

}
