#ifndef REGULARZOMBIE_HPP__
#define REGULARZOMBIE_HPP__

#include "Zombies.hpp"

class RegularZombie : public Zombies
{
public:
    RegularZombie(int x, int y, pGameWorld CurrentWorld);

    void Update() override;

private:
};

#endif // !REGULARZOMBIE_HPP__