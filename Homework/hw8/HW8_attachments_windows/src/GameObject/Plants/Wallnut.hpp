#ifndef WALLNUT_HPP__
#define WALLNUT_HPP__

#include "Plants.hpp"

class Wallnut : public Plants
{
public:
    Wallnut(int x, int y, pGameWorld CurrentWorld);

    void Update() override;

private:
    int m_wallnut{1};
};

#endif // !WALLNUT_HPP__