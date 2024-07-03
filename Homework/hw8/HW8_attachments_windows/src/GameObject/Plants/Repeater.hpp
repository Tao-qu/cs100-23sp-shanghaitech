#ifndef REPEATER_HPP__
#define REPEATER_HPP__

#include "Plants.hpp"

class Repeater : public Plants
{
public:
    Repeater(int x, int y, pGameWorld CurrentWorld);

    bool IsLockOn();

    void Update() override;

private:
};

#endif // !REPEATER_HPP__