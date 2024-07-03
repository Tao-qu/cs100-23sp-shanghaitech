#include "SkySun.hpp"
#include "GameManager.hpp"
#include "GameWorld.hpp"

SkySun::SkySun(pGameWorld CurrentWorld) : Sun(randInt(75, WINDOW_WIDTH - 75), WINDOW_HEIGHT - 1, randInt(63, 263), CurrentWorld) {}

void SkySun::Update()
{
    if (!IsDead())
    {
        CountDown();
        if (IsFalling())
        {
            MoveTo(GetX(), GetY() - 2);
        }
        else if (GetDownTick() == 0)
        {
            SetHP(0);
        }
    }
}