#include "Repeater.hpp"
#include "GameManager.hpp"
#include "GameWorld.hpp"

Repeater::Repeater(int x, int y, pGameWorld CurrentWorld) : Plants(IMGID_REPEATER, x, y, HP_REPEATER, ATK_REPEATER, 1, CurrentWorld) {}

bool Repeater::IsLockOn()
{
    return GetCurrentWorld()->IsLockOn(shared_from_this());
}

void Repeater::Update()
{
    if (!IsDead())
    {
        CountDown();
        if (Getcd() == 0)
        {
            if (IsLockOn())
            {
                GetCurrentWorld()->AddObject(std::make_shared<Pea>(GetX() + 30, GetY() + 20, GetATK(), GetCurrentWorld()));
                Setcd(CD_REPEATER);
            }
        }
        else if (Getcd() == 25)
        {
            GetCurrentWorld()->AddObject(std::make_shared<Pea>(GetX() + 30, GetY() + 20, GetATK(), GetCurrentWorld()));
        }
    }
}