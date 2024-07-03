#ifndef CHERRYBOMB_HPP__
#define CHERRYBOMB_HPP__

#include "Plants.hpp"

class CherryBomb : public Plants
{
public:
    CherryBomb(int x, int y, pGameWorld CurrentWorld);

    void Update() override;

private:
};

#endif // !CHERRYBOMB_HPP__