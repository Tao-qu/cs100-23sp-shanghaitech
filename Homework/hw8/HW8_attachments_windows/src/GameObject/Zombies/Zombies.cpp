#include "Zombies.hpp"
#include "GameManager.hpp"
#include "GameWorld.hpp"

Zombies::Zombies(ImageID imageID, int x, int y, AnimID animaID, HP hp, ATK atk, pGameWorld CurrentWorld) : GameObject(imageID, x, y, LAYER_ZOMBIES, 20, 80, animaID, hp, atk, CurrentWorld) {}

bool Zombies::IsZombie()
{
    return true;
}

void Zombies::Collide(std::shared_ptr<GameObject> object)
{
    if ((*object).IsPlant())
    {
        if (GetCurrentAnimation() == ANIMID_WALK_ANIM)
        {
            PlayAnimation(ANIMID_EAT_ANIM);
        }
    }
    else if ((*object).IsProjectile())
    {
        SetHP(GetHP() - (*object).GetATK());
    }
}