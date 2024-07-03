#ifndef SUN_HPP__
#define SUN_HPP__

#include "GameObject.hpp"

class Sun : public GameObject
{
public:
    Sun(int x, int y, int down_tick, pGameWorld CurrentWorld);

    bool IsFalling();

    int GetDownTick();

    void CountDown();
    void OnClick() override;

private:
    int m_down_tick;
};

#endif // !SUN_HPP__