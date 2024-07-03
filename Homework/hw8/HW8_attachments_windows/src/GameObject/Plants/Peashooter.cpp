#include "Peashooter.hpp"
#include "GameManager.hpp"
#include "GameWorld.hpp"

Peashooter::Peashooter(int x, int y, pGameWorld CurrentWorld) : Plants(IMGID_PEASHOOTER, x, y, HP_PEASHOOTER, ATK_PEASHOOTER, 1, CurrentWorld) {}

bool Peashooter::IsLockOn()
{
    return GetCurrentWorld()->IsLockOn(shared_from_this());
}

void Peashooter::Update()
{
    if (!IsDead())
    {
        CountDown();
        if (Getcd() == 0)
        {
            if (IsLockOn())
            {
                GetCurrentWorld()->AddObject(std::make_shared<Pea>(GetX() + 30, GetY() + 20, GetATK(), GetCurrentWorld()));
                Setcd(CD_PEASHOOTER);
            }
        }
    }
}