#ifndef COOLDOWNMASK_HPP__
#define COOLDOWNMASK_HPP__

#include "GameObject.hpp"

class CooldownMask : public GameObject
{
public:
    CooldownMask(int x, int y, CD cd, pGameWorld CurrentWorld);

    void Update() override;

private:
    CD m_cd;
};

#endif // !COOLDOWNMASK_HPP__