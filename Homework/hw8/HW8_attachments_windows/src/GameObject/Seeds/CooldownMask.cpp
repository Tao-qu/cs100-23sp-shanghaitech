#include "CooldownMask.hpp"
#include "GameManager.hpp"
#include "GameWorld.hpp"

CooldownMask::CooldownMask(int x, int y, CD cd, pGameWorld CurrentWorld) : GameObject(IMGID_COOLDOWN_MASK, x, y, LAYER_COOLDOWN_MASK, 50, 70, ANIMID_NO_ANIMATION, HP_IMMORTAL, ATK_NONE, CurrentWorld), m_cd(cd) {}

void CooldownMask::Update()
{
    if (!IsDead())
    {
        --m_cd;
        if (m_cd == 0)
        {
            SetHP(0);
        }
    }
}