#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class Direction {
    START,
    NORTH,
    SOUTH,
    EAST,
    WEST
};

unsigned int islandIterator(vector<vector<unsigned int>> landMass, unsigned int row, unsigned int column, Direction direction)
{   
    //North
    if(landMass.at(row - 1).at(column) && direction != Direction::SOUTH)
    {
        //This can solve non quadratic matrices
        if(row - 1 == 0)
        {
            return 1;
        }
        else
        {
            if(islandIterator(landMass, row - 1, column, Direction::NORTH))
            {
                return 1;
            }
        }
    }
    //East
    if(landMass.at(row).at(column+1) && direction != Direction::WEST)
    {
        //This can solve non quadratic matrices
        if(column + 1 == landMass[0].size())
        {
            return 1;
        }
        else
        {
            if(islandIterator(landMass, row, column + 1, Direction::EAST))
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
        else
        {
            if(islandIterator(landMass, row, column - 1, Direction::WEST))
            {
                return 1;
            }
        }
    }
    //South
    if(landMass.at(row+1).at(column) && direction != Direction::NORTH)
    {
        //This can solve non quadratic matrices
        if(row + 1 == landMass.size())
        {
            return 1;
        }
        else
        {
            if(islandIterator(landMass, row + 1, column, Direction::SOUTH))
            {
                return 1;
            }
        }
    }

    return 0;
}

void removeIslands(vector<vector<unsigned int>> landMass)
{
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
                landMass.at(row).at(column) = islandIterator(landMass, row, column, Direction::START);
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
}


int main()
{
    vector<vector<unsigned int>> landMass1{ {1, 1, 0, 0, 1}, 
                                            {0, 1, 1, 0, 0}, 
                                            {0, 0, 1, 1, 0}, 
                                            {1, 0, 1, 0, 0}, 
                                            {1, 1, 0, 0, 1} };

    vector<vector<unsigned int>> landMass2{ {1, 0, 0, 0, 1}, 
                                            {0, 1, 1, 0, 0}, 
                                            {0, 0, 1, 1, 0}, 
                                            {1, 0, 1, 0, 0}, 
                                            {1, 1, 0, 0, 1} };
    
    removeIslands(landMass1);
    removeIslands(landMass2);
}