#include "FlowerSun.hpp"
#include "GameManager.hpp"
#include "GameWorld.hpp"

FlowerSun::FlowerSun(int x, int y, pGameWorld CurrentWorld) : Sun(x, y, 12, CurrentWorld) {}

void FlowerSun::Update()
{
    if (!IsDead())
    {
        CountDown();
        if (IsFalling())
        {
            MoveTo(GetX() - 1, GetY() + 4 - (12 - (GetDownTick() + 1 - 300)));
        }
        if (GetDownTick() == 0)
        {
            SetHP(0);
        }
    }
}