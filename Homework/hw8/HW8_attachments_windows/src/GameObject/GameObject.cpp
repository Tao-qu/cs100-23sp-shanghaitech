#include "GameObject.hpp"
#include "GameManager.hpp"
#include "GameWorld.hpp"

GameObject::GameObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, HP hp, ATK atk, pGameWorld CurrentWorld) : ObjectBase(imageID, x, y, layer, width, height, animID), m_HP(hp), m_ATK(atk), m_CurrentWorld(CurrentWorld) {}

bool GameObject::IsDead()
{
    if (m_HP <= 0)
    {
        return true;
    }
    return false;
}

bool GameObject::IsPlant()
{
    return false;
}

bool GameObject::IsProjectile()
{
    return false;
}

bool GameObject::IsZombie()
{
    return false;
}

HP GameObject::GetHP()
{
    return m_HP;
}

ATK GameObject::GetATK()
{
    return m_ATK;
}

pGameWorld GameObject::GetCurrentWorld()
{
    return m_CurrentWorld;
}

void GameObject::SetHP(HP hp)
{
    m_HP = hp;
}

void GameObject::SetATK(ATK atk)
{
    m_ATK = atk;
}

void GameObject::Collide(std::shared_ptr<GameObject> object) {}

void GameObject::Update() {}

void GameObject::OnClick() {}