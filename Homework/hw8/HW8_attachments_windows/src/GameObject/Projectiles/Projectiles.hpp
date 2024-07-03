#ifndef PROJECTILES_HPP__
#define PROJECTILES_HPP__

#include "GameObject.hpp"

class Projectiles : public GameObject
{
public:
    Projectiles(ImageID imageID, int x, int y, int width, int height, ATK atk, pGameWorld CurrentWorld);

    bool IsProjectile() override;

    virtual void Collide(std::shared_ptr<GameObject> object) override;

private:
    int m_atk;
};

#endif // !PROJECTILES_HPP__