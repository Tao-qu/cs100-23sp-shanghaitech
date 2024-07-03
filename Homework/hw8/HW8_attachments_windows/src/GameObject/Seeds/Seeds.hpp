#ifndef SEEDS_HPP__
#define SEEDS_HPP__

#include "GameObject.hpp"

class Seeds : public GameObject
{
public:
    Seeds(UIName name, ImageID imageID, int x, int price, CD cd, pGameWorld CurrentWorld);

    void OnClick() override;

private:
    UIName m_name;
    int m_price;
    CD m_cd;
};

#endif // !SEEDS_HPP__