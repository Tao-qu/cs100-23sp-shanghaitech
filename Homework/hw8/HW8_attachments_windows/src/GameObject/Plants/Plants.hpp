#ifndef PLANTS_HPP__
#define PLANTS_HPP__

#include "GameObject.hpp"

class Plants : public GameObject
{
public:
    Plants(ImageID imageID, int x, int y, HP hp, ATK atk, CD cd, pGameWorld CurrentWorld);

    bool IsPlant() override;

    CD Getcd();

    void CountDown();
    void Setcd(CD cd);
    virtual void Collide(std::shared_ptr<GameObject> object) override;
    virtual void OnClick() override;

private:
    CD m_cd;
};

#endif // !PLANTS_HPP__