#ifndef FLOWERSUN_HPP__
#define FLOWERSUN_HPP__

#include "Sun.hpp"

class FlowerSun : public Sun
{
public:
    FlowerSun(int x, int y, pGameWorld CurrentWorld);

    void Update() override;

private:
};

#endif // !FLOWERSUN_HPP__