#include "Sun.hpp"
#include "GameManager.hpp"
#include "GameWorld.hpp"

Sun::Sun(int x, int y, int down_tick, pGameWorld CurrentWorld) : GameObject(IMGID_SUN, x, y, LAYER_SUN, 80, 80, ANIMID_IDLE_ANIM, HP_IMMORTAL, ATK_NONE, CurrentWorld), m_down_tick(down_tick + 300) {}

bool Sun::IsFalling()
{
    if (m_down_tick > 300)
    {
        return true;
    }
    return false;
}

int Sun::GetDownTick()
{
    return m_down_tick;
}

void Sun::CountDown()
{
    --m_down_tick;
}

void Sun::OnClick()
{
    GetCurrentWorld()->SetSun(GetCurrentWorld()->GetSun() + 25);
    SetHP(0);
}
