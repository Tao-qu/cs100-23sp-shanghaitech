#include "Pea.hpp"
#include "GameManager.hpp"
#include "GameWorld.hpp"

Pea::Pea(int x, int y, ATK atk, pGameWorld CurrentWorld) : Projectiles(IMGID_PEA, x, y, 28, 28, atk, CurrentWorld) {}

void Pea::Update()
{
    if (!IsDead())
    {
        MoveTo(GetX() + 8, GetY());
        if (GetX() >= WINDOW_WIDTH)
        {
            SetHP(0);
        }
    }
}