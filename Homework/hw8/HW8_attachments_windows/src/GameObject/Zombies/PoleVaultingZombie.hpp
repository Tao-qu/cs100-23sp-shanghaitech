#ifndef POLEVAULTINGZOMBIE_HPP__
#define POLEVAULTINGZOMBIE_HPP__

#include "Zombies.hpp"

class PoleVaultingZombie : public Zombies
{
public:
    PoleVaultingZombie(int x, int y, pGameWorld CurrentWorld);

    void Update() override;

private:
    int m_poletime{42};
};

#endif // !POLEVAULTINGZOMBIE_HPP__