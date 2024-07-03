#include "Seeds.hpp"
#include "GameManager.hpp"
#include "GameWorld.hpp"

Seeds::Seeds(UIName name, ImageID imageID, int x, int price, CD cd, pGameWorld CurrentWorld) : m_name(name), GameObject(imageID, x, WINDOW_HEIGHT - 44, LAYER_UI, 50, 70, ANIMID_NO_ANIMATION, HP_IMMORTAL, ATK_NONE, CurrentWorld), m_price(price), m_cd(cd) {}

void Seeds::OnClick()
{
    if (GetCurrentWorld()->GetSun() >= m_price && GetCurrentWorld()->GetInHand() == UIName::None)
    {
        GetCurrentWorld()->SetInHand(m_name);
        GetCurrentWorld()->SetSun(GetCurrentWorld()->GetSun() - m_price);
        GetCurrentWorld()->AddObject(std::make_shared<CooldownMask>(GetX(), GetY(), m_cd, GetCurrentWorld()));
    }
}