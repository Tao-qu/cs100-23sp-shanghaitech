#include "PoleVaultingZombie.hpp"
#include "GameManager.hpp"
#include "GameWorld.hpp"

PoleVaultingZombie::PoleVaultingZombie(int x, int y, pGameWorld CurrentWorld) : Zombies(IMGID_POLE_VAULTING_ZOMBIE, x, y, ANIMID_RUN_ANIM, HP_Pole_Vaulting_Zombie, ATK_POLE_VAULTING_ZOMBIE, CurrentWorld) {}

void PoleVaultingZombie::Update()
{
    if (!IsDead())
    {
        if (GetCurrentAnimation() == ANIMID_WALK_ANIM)
        {
            MoveTo(GetX() - 1, GetY());
        }
        else if (GetCurrentAnimation() == ANIMID_RUN_ANIM)
        {
            if (GetCurrentWorld()->IsPole(shared_from_this()))
            {
                PlayAnimation(ANIMID_JUMP_ANIM);
                --m_poletime;
            }
            else
            {
                MoveTo(GetX() - 2, GetY());
            }
        }
        else if (GetCurrentAnimation() == ANIMID_JUMP_ANIM)
        {
            --m_poletime;
            if (m_poletime == 0)
            {
                PlayAnimation(ANIMID_WALK_ANIM);
                MoveTo(GetX() - 150, GetY());
            }
        }
    }
}