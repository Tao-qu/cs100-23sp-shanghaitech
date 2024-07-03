#ifndef SUNFLOWER_HPP__
#define SUNFLOWER_HPP__

#include "Plants.hpp"

class Sunflower : public Plants
{
public:
    Sunflower(int x, int y, pGameWorld CurrentWorld);

    void Update() override;

private:
};

#endif // !SUNFLOWER_HPP__