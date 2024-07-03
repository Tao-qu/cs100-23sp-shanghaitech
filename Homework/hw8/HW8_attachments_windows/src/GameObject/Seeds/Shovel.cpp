#include "Shovel.hpp"
#include "GameManager.hpp"
#include "GameWorld.hpp"

Shovel::Shovel(pGameWorld CurrentWorld) : GameObject(IMGID_SHOVEL, 600, WINDOW_HEIGHT - 40, LAYER_UI, 50, 50, ANIMID_NO_ANIMATION, HP_IMMORTAL, ATK_NONE, CurrentWorld) {}

void Shovel::OnClick()
{
    if (GetCurrentWorld()->GetInHand() == UIName::None)
    {
        GetCurrentWorld()->SetInHand(m_name);
    }
}