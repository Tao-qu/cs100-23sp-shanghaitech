#ifndef SHOVEL_HPP__
#define SHOVEL_HPP__

#include "GameObject.hpp"

class Shovel : public GameObject
{
public:
    Shovel(pGameWorld CurrentWorld);

    void OnClick() override;

private:
    UIName m_name{UIName::Shovel};
};

#endif // !SHOVEL_HPP__