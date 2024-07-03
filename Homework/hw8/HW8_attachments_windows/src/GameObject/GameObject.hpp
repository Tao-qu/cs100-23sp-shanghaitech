#ifndef GAMEOBJECT_HPP__
#define GAMEOBJECT_HPP__

#include <memory>
#include <list>
#include "ObjectBase.hpp"

// Declares the class name GameWorld so that its pointers can be used.
class GameWorld;
using pGameWorld = std::shared_ptr<GameWorld>;

class GameObject : public ObjectBase, public std::enable_shared_from_this<GameObject>
{
public:
  using std::enable_shared_from_this<GameObject>::shared_from_this; // Use shared_from_this() instead of "this".

  GameObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, HP hp, ATK atk, pGameWorld CurrentWorld);

  bool IsDead();
  virtual bool IsPlant();
  virtual bool IsProjectile();
  virtual bool IsZombie();

  HP GetHP();
  ATK GetATK();
  pGameWorld GetCurrentWorld();

  void SetHP(HP hp);
  void SetATK(ATK atk);
  virtual void Collide(std::shared_ptr<GameObject> object);
  virtual void Update() override;
  virtual void OnClick() override;

private:
  HP m_HP;
  ATK m_ATK;
  pGameWorld m_CurrentWorld;
};

#endif // !GAMEOBJECT_HPP__
