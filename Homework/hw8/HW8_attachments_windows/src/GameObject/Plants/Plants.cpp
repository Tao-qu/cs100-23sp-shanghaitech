#include "Plants.hpp"
#include "GameManager.hpp"
#include "GameWorld.hpp"

Plants::Plants(ImageID imageID, int x, int y, HP hp, ATK atk, CD cd, pGameWorld CurrentWorld) : GameObject(imageID, x, y, LAYER_PLANTS, 60, 80, ANIMID_IDLE_ANIM, hp, atk, CurrentWorld), m_cd(cd) {}

bool Plants::IsPlant()
{
    return true;
}

CD Plants::Getcd()
{
    return m_cd;
}

void Plants::CountDown()
{
    if (m_cd != 0)
    {
        --m_cd;
    }
}

void Plants::Setcd(CD cd)
{
    m_cd = cd;
}

void Plants::Collide(std::shared_ptr<GameObject> object)
{
    if ((*object).IsZombie())
    {
        SetHP(GetHP() - (*object).GetATK());
    }
}

void Plants::OnClick()
{
    if (GetCurrentWorld()->GetInHand() == UIName::Shovel)
    {
        SetHP(0);
        GetCurrentWorld()->SetInHand(UIName::None);
    }
}