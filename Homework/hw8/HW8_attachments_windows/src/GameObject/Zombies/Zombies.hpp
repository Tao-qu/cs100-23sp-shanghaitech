#ifndef ZOMBIES_HPP__
#define ZOMBIES_HPP__

#include "GameObject.hpp"

class Zombies : public GameObject
{
public:
    Zombies(ImageID imageID, int x, int y, AnimID animID, HP hp, ATK atk, pGameWorld CurrentWorld);

    bool IsZombie() override;

    virtual void Collide(std::shared_ptr<GameObject> object) override;

private:
};

#endif // !ZOMBIES_HPP__