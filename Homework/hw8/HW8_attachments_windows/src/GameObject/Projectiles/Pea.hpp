#ifndef PEA_HPP__
#define PEA_HPP__

#include "Projectiles.hpp"

class Pea : public Projectiles
{
public:
    Pea(int x, int y, ATK atk, pGameWorld CurrentWorld);

    void Update() override;

private:
};

#endif // !PEA_HPP__