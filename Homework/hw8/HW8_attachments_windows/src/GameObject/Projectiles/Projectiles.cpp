#include "Projectiles.hpp"
#include "GameManager.hpp"
#include "GameWorld.hpp"

Projectiles::Projectiles(ImageID imageID, int x, int y, int width, int height, ATK atk, pGameWorld CurrentWorld) : GameObject(imageID, x, y, LAYER_PROJECTILES, width, height, ANIMID_NO_ANIMATION, HP_IMMORTAL, atk, CurrentWorld) {}

bool Projectiles::IsProjectile()
{
    return true;
}

void Projectiles::Collide(std::shared_ptr<GameObject> object)
{
    if ((*object).IsZombie())
    {
        SetHP(0);
    }
}