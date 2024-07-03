#include "Sunflower.hpp"
#include "GameManager.hpp"
#include "GameWorld.hpp"

Sunflower::Sunflower(int x, int y, pGameWorld CurrentWorld) : Plants(IMGID_SUNFLOWER, x, y, HP_SUNFLOWER, ATK_NONE, randInt(30, CD_SUNFLOWER), CurrentWorld) {}

void Sunflower::Update()
{
    if (!IsDead())
    {
        CountDown();
        if (Getcd() == 0)
        {
            GetCurrentWorld()->AddObject(std::make_shared<FlowerSun>(GetX(), GetY(), GetCurrentWorld()));
            Setcd(CD_SUNFLOWER);
        }
    }
}