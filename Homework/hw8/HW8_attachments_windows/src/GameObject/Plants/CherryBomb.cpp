#include "CherryBomb.hpp"
#include "GameManager.hpp"
#include "GameWorld.hpp"

CherryBomb::CherryBomb(int x, int y, pGameWorld CurrentWorld) : Plants(IMGID_CHERRY_BOMB, x, y, HP_CHERRY_BOMB, ATK_IMMEDIATE_DEATH, CD_CHERRY_BOMB, CurrentWorld) {}

void CherryBomb::Update()
{
    if (!IsDead())
    {
        CountDown();
        if (Getcd() == 0)
        {
            GetCurrentWorld()->AddObject(std::make_shared<Explosion>(GetX(), GetY(), GetATK(), GetCurrentWorld()));
            SetHP(0);
        }
    }
}