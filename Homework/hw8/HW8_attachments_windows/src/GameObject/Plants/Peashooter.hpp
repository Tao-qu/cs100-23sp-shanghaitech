#ifndef PEASHOOTER_HPP__
#define PEASHOOTER_HPP__

#include "Plants.hpp"

class Peashooter : public Plants
{
public:
    Peashooter(int x, int y, pGameWorld CurrentWorld);

    bool IsLockOn();

    void Update() override;

private:
};

#endif // !PEASHOOTER_HPP__