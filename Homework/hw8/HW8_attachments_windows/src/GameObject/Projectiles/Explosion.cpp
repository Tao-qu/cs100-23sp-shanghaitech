#include "Explosion.hpp"
#include "GameManager.hpp"
#include "GameWorld.hpp"

Explosion::Explosion(int x, int y, ATK atk, pGameWorld CurrentWorld) : Projectiles(IMGID_EXPLOSION, x, y, 3 * LAWN_GRID_WIDTH, 3 * LAWN_GRID_HEIGHT, atk, CurrentWorld) {}

void Explosion::Collide(std::shared_ptr<GameObject> object) {}

void Explosion::Update()
{
    if (!IsDead())
    {
        --m_exist_tick;
        if (m_exist_tick == 0)
        {
            SetHP(0);
        }
    }
}