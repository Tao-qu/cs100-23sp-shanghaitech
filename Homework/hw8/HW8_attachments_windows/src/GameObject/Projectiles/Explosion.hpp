#ifndef EXPLOSION_HPP__
#define EXPLOSION_HPP__

#include "Projectiles.hpp"

class Explosion : public Projectiles
{
public:
    Explosion(int x, int y, ATK atk, pGameWorld CurrentWorld);

    void Collide(std::shared_ptr<GameObject> object) override;

    void Update() override;

private:
    int m_exist_tick{3};
};

#endif // !EXPLOSION_HPP__