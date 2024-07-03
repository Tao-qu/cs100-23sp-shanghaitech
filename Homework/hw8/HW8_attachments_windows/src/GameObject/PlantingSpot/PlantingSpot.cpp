#include "PlantingSpot.hpp"
#include "GameManager.hpp"
#include "GameWorld.hpp"

PlantingSpot::PlantingSpot(int x, int y, pGameWorld CurrentWorld) : GameObject(IMGID_NONE, x, y, LAYER_UI, 60, 80, ANIMID_NO_ANIMATION, HP_IMMORTAL, ATK_NONE, CurrentWorld) {}

void PlantingSpot::OnClick()
{
    switch (GetCurrentWorld()->GetInHand())
    {
    case UIName::SunflowerSeed:
        GetCurrentWorld()->AddObject(std::make_shared<Sunflower>(GetX(), GetY(), GetCurrentWorld()));
        GetCurrentWorld()->SetInHand(UIName::None);
        break;
    case UIName::PeashooterSeed:
        GetCurrentWorld()->AddObject(std::make_shared<Peashooter>(GetX(), GetY(), GetCurrentWorld()));
        GetCurrentWorld()->SetInHand(UIName::None);
        break;
    case UIName::WallnutSeed:
        GetCurrentWorld()->AddObject(std::make_shared<Wallnut>(GetX(), GetY(), GetCurrentWorld()));
        GetCurrentWorld()->SetInHand(UIName::None);
        break;
    case UIName::CherryBombSeed:
        GetCurrentWorld()->AddObject(std::make_shared<CherryBomb>(GetX(), GetY(), GetCurrentWorld()));
        GetCurrentWorld()->SetInHand(UIName::None);
        break;
    case UIName::RepeaterSeed:
        GetCurrentWorld()->AddObject(std::make_shared<Repeater>(GetX(), GetY(), GetCurrentWorld()));
        GetCurrentWorld()->SetInHand(UIName::None);
        break;
    case UIName::Shovel:
        GetCurrentWorld()->SetInHand(UIName::None);
        break;
    default:
        break;
    }
}