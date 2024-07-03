#include <cctype>
#include "LifeRule.h"
#include "GameWorld.h"
#include "GameSettings.h"

// LifeRuleBase
int LifeRuleBase::CountAliveNeighbors(const CellNeighbors &neighbors) const
{
    int count_alive = 0;            // Count the number of alive neighbors
    for (auto neighbor : neighbors) // Loop through all neighbors
    {
        if (neighbor->IsAlive()) // If the neighbor is alive
        {
            ++count_alive; // Then increase the count
        }
    }
    return count_alive; // Return the count
}

void LifeRuleBase::DetermineNextState(const CellPointer &current, const CellNeighbors &neighbors)
{
    const int count_alive = CountAliveNeighbors(neighbors); // Count the number of alive neighbors

    // If the current cell is alive and the number of alive neighbors is not in the set of numbers that the cell survives with
    if (current->IsAlive() && (!BASE_CELL_SURVIVE_CONDITION.count(count_alive)))
    {
        current->SetState(CELL_STATE_DEAD);
        return;
    }
    // If the current cell is dead and the number of alive neighbors is in the set of numbers that the cell is born with
    if (!current->IsAlive() && BASE_CELL_BIRTH_CONDITION.count(count_alive))
    {
        current->SetState(CELL_STATE_ALIVE);
        return;
    }
}

CellNeighbors LifeRuleBase::GetNeighbors(const GameWorld *const game_world, const int x, const int y) const
{
    // Get the neighbors of the cell at position x, y
    CellNeighbors neighbors;
    // Loop through all the neighbors
    for (int i = -1; i <= 1; ++i)
    {
        for (int j = -1; j <= 1; ++j)
        {
            if (i == 0 && j == 0)
                continue;
            int next_x = x + i;
            int next_y = y + j;
            // If the position is not exceeding the boundaries of the world
            if (game_world->CheckPosValid(next_x, next_y))
            {
                // Add the neighbor to the list of neighbors
                neighbors.push_back(game_world->GetCell(next_x, next_y));
            }
        }
    }
    // Return the list of neighbors
    return neighbors;
}

// LifeRuleColorised
void LifeRuleColorised::DetermineNextState(const CellPointer &current, const CellNeighbors &neighbors)
{
    const int count_alive = CountAliveNeighbors(neighbors); // Count the number of alive,red and blue neighbors

    // If the current cell is alive and the number of alive neighbors is not in the set of numbers that the cell survives with
    if (current->IsAlive() && (!BASE_CELL_SURVIVE_CONDITION.count(count_alive)))
    {
        current->SetState(CELL_STATE_DEAD);
        return;
    }

    // If the current cell is dead and the number of alive neighbors is in the set of numbers that the cell is born with
    if (!current->IsAlive() && BASE_CELL_BIRTH_CONDITION.count(count_alive))
    {
        int count_state = 0;
        for (auto neighbor : neighbors)
        {
            count_state += neighbor->GetState();
        }

        if (count_state <= 7)
        {
            current->SetState(CELL_STATE_RED);
        }
        else
        {
            current->SetState(CELL_STATE_BLUE);
        }
        return;
    }
}

// LifeRuleExtended
CellNeighbors LifeRuleExtended::GetNeighbors(const GameWorld *const game_world, const int x, const int y) const
{
    // Get the neighbors of the cell at position x, y
    CellNeighbors neighbors;
    // the size of a cell's neighborhood
    int size_neighborhood = 2;
    // Loop through all the neighbors
    for (int i = -size_neighborhood; i <= size_neighborhood; ++i)
    {
        for (int j = -size_neighborhood; j <= size_neighborhood; ++j)
        {
            if (i == 0 && j == 0)
                continue;
            int next_x = x + i;
            int next_y = y + j;
            // If the position is not exceeding the boundaries of the world
            if (game_world->CheckPosValid(next_x, next_y))
            {
                // Add the neighbor to the list of neighbors
                neighbors.push_back(game_world->GetCell(next_x, next_y));
            }
        }
    }
    // Return the list of neighbors
    return neighbors;
}

// LifeRuleWeighted
int LifeRuleWeighted::CountAliveNeighbors(const CellNeighbors &neighbors) const
{
    int count_alive_weighted = 0; // Count the number of alive neighbors
    // neighbors' weight
    std::vector<int> weight_map({1, 1, 2, 1, 1,
                                 1, 2, 2, 2, 1,
                                 2, 2, 2, 2,
                                 1, 2, 2, 2, 1,
                                 1, 1, 2, 1, 1});
    int cnt = 0;                    // Loop count
    for (auto neighbor : neighbors) // Loop through all neighbors
    {
        if (neighbor != nullptr)
        {
            if (neighbor->IsAlive()) // If the neighbor is alive
            {
                count_alive_weighted += weight_map[cnt]; // Then increase the count
            }
        }
        cnt++;
    }
    return count_alive_weighted; // Return the count
}

CellNeighbors LifeRuleWeighted::GetNeighbors(const GameWorld *const game_world, const int x, const int y) const
{
    // Get the neighbors of the cell at position x, y
    CellNeighbors neighbors;
    // the size of a cell's neighborhood
    int size_neighborhood = 2;
    // Loop through all the neighbors
    for (int i = -size_neighborhood; i <= size_neighborhood; ++i)
    {
        for (int j = -size_neighborhood; j <= size_neighborhood; ++j)
        {
            if (i == 0 && j == 0)
                continue;
            int next_x = x + i;
            int next_y = y + j;
            // If the position is not exceeding the boundaries of the world
            if (game_world->CheckPosValid(next_x, next_y))
            {
                // Add the neighbor to the list of neighbors
                neighbors.push_back(game_world->GetCell(next_x, next_y));
            }
            else
            {
                neighbors.push_back(nullptr);
            }
        }
    }
    // Return the list of neighbors
    return neighbors;
}

void LifeRuleWeighted::DetermineNextState(const CellPointer &current, const CellNeighbors &neighbors)
{
    const int count_alive = CountAliveNeighbors(neighbors); // Count the number of alive neighbors

    // If the current cell is alive and the number of alive neighbors is not in the set of numbers that the cell survives with
    if (current->IsAlive() && (!WEIGHTED_CELL_SURVIVE_CONDITION.count(count_alive)))
    {
        current->SetState(CELL_STATE_DEAD);
        return;
    }
    // If the current cell is dead and the number of alive neighbors is in the set of numbers that the cell is born with
    if (!current->IsAlive() && WEIGHTED_CELL_BIRTH_CONDITION.count(count_alive))
    {
        current->SetState(CELL_STATE_ALIVE);
        return;
    }
}

// LifeRuleGenerations
void LifeRuleGenerations::DetermineNextState(const CellPointer &current, const CellNeighbors &neighbors)
{
    const int count_alive = CountAliveNeighbors(neighbors); // Count the number of alive neighbors
    int N = 8;                                              // the generation of the final death

    // If the current cell is alive
    if (current->IsAlive())
    {
        if ((current->GetState() == 1) && (!BASE_CELL_SURVIVE_CONDITION.count(count_alive)))
        {
            current->IncreaseState();
            return;
        }
        if (current->GetState() == N - 1)
        {
            current->SetState(CELL_STATE_DEAD);
            return;
        }
        if (current->GetState() >= 2)
        {
            current->IncreaseState();
            return;
        }
    }
    // If the current cell is dead and the number of alive neighbors is in the set of numbers that the cell is born with
    if (!current->IsAlive() && BASE_CELL_BIRTH_CONDITION.count(count_alive))
    {
        current->SetState(CELL_STATE_ALIVE);
        return;
    }
}