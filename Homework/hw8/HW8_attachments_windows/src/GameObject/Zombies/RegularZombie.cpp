#include "RegularZombie.hpp"
#include "GameManager.hpp"
#include "GameWorld.hpp"

RegularZombie::RegularZombie(int x, int y, pGameWorld CurrentWorld) : Zombies(IMGID_REGULAR_ZOMBIE, x, y, ANIMID_WALK_ANIM, HP_REGULAR_ZOMBIE, ATK_REGULAR_ZOMBIE, CurrentWorld) {}

void RegularZombie::Update()
{
    if (!IsDead())
    {
        if (GetCurrentAnimation() == ANIMID_WALK_ANIM)
        {
            MoveTo(GetX() - 1, GetY());
        }
    }
}