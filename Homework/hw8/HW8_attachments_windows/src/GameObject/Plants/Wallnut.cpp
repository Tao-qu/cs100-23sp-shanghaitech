#include "Wallnut.hpp"
#include "GameManager.hpp"
#include "GameWorld.hpp"

Wallnut::Wallnut(int x, int y, pGameWorld CurrentWorld) : Plants(IMGID_WALLNUT, x, y, HP_WALLNUT, ATK_NONE, CD_WALLNUT, CurrentWorld) {}

void Wallnut::Update()
{
    if (!IsDead())
    {
        if (GetHP() < HP_WALLNUT / 3 && m_wallnut != 0) 
        {
            ChangeImage(IMGID_WALLNUT_CRACKED);
            --m_wallnut;
        }
    }
}