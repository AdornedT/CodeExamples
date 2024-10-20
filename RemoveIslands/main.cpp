#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <random>

using namespace std;

enum class Direction {
    START,
    NORTH,
    SOUTH,
    EAST,
    WEST
};

unsigned int islandIterator(vector<vector<unsigned int>> landMass, unsigned int row, unsigned int column, Direction direction, unordered_map<string, bool> borderMap)
{   
    //North
    if(landMass.at(row - 1).at(column) && direction != Direction::SOUTH)
    {
        //This can solve non quadratic matrices
        if(row - 1 == 0)
        {
            return 1;
        }
        else if (borderMap.find(to_string(row-1) + "," + to_string(column)) != borderMap.end())
        {
            return 1;
        }
        else
        {
            if(islandIterator(landMass, row - 1, column, Direction::NORTH, borderMap))
            {
                return 1;
            }
        }
    }
    //East
    if(landMass.at(row).at(column+1) && direction != Direction::WEST)
    {
        //This can solve non quadratic matrices
        if(column + 1 == landMass[0].size() - 1)
        {
            return 1;
        }
        else if (borderMap.find(to_string(row) + "," + to_string(column+1)) != borderMap.end())
        {
            return 1;
        }
        else
        {
            if(islandIterator(landMass, row, column + 1, Direction::EAST, borderMap))
            {
                return 1;
            }
        }
    }
    //West
    if(landMass.at(row).at(column-1) && direction != Direction::EAST)
    {
        //This can solve non quadratic matrices
        if(column - 1 == 0)
        {
            return 1;
        }
        else if (borderMap.find(to_string(row) + "," + to_string(column-1)) != borderMap.end())
        {
            return 1;
        }
        else
        {
            if(islandIterator(landMass, row, column - 1, Direction::WEST, borderMap))
            {
                return 1;
            }
        }
    }
    //South
    if(landMass.at(row+1).at(column) && direction != Direction::NORTH)
    {
        //This can solve non quadratic matrices
        if(row + 1 == landMass.size() - 1)
        {
            return 1;
        }
        else if (borderMap.find(to_string(row+1) + "," + to_string(column)) != borderMap.end())
        {
            return 1;
        }
        else
        {
            if(islandIterator(landMass, row + 1, column, Direction::SOUTH, borderMap))
            {
                return 1;
            }
        }
    }

    return 0;
}

void removeIslands(vector<vector<unsigned int>> landMass)
{
    unordered_map<string, bool> borderMap = {};

    cout << "Starting Matrix" << endl;
    for (const auto& row : landMass)
    {
        for (const auto& elem : row)
        {
            cout << elem;
        }
        cout << endl;
    }
    cout << endl;

    const auto &startingRow = 1;
    const auto &endRow = landMass.size() - 2;
    const auto &startingColumn = 1;
    const auto &endColumn = landMass[0].size() - 2; //For non quadratic Matrices

    for(unsigned int row = startingRow; row <= endRow; row++)
    {
        for(unsigned int column = startingColumn; column <= endColumn; column++)
        {
            if(landMass.at(row).at(column))
            {
                if(landMass.at(row).at(column) = islandIterator(landMass, row, column, Direction::START, borderMap))
                {
                    borderMap.insert({to_string(row) + "," + to_string(column), true});
                }
            }
        }
    }

    cout << "Final Matix" << endl;
    for (const auto& row : landMass)
    {
        for (const auto& elem : row)
        {
            cout << elem;
        }
        cout << endl;
    }
    cout << endl;

    cout << "Final Hash Map" << endl;
    for (const auto& pair : borderMap)
    {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << endl;
}


vector<vector<unsigned int>> randomMatrix(unsigned int row_num, unsigned int column_num)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 1);

    vector<vector<unsigned int>> landMass(row_num, vector<unsigned int>(column_num, 0));

    for(auto& row : landMass)
    {
        for (auto& element : row)
        {
            element = dis(gen);
        }
    }

    return landMass;
}

int main()
{
    removeIslands(randomMatrix(3, 3));
    removeIslands(randomMatrix(4, 4));
    removeIslands(randomMatrix(5, 5));
    removeIslands(randomMatrix(6, 6));

    removeIslands(randomMatrix(4, 3));
    removeIslands(randomMatrix(5, 3));
    removeIslands(randomMatrix(6, 4));
}