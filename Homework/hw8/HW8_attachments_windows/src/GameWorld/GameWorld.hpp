#ifndef GAMEWORLD_HPP__
#define GAMEWORLD_HPP__

#include <list>
#include <memory>

#include "WorldBase.hpp"
#include "utils.hpp"

#include "GameObject.hpp"
#include "Background.hpp"
#include "PlantingSpot.hpp"
#include "Plants.hpp"
#include "Sunflower.hpp"
#include "Peashooter.hpp"
#include "Wallnut.hpp"
#include "CherryBomb.hpp"
#include "Repeater.hpp"
#include "Projectiles.hpp"
#include "Pea.hpp"
#include "Explosion.hpp"
#include "Seeds.hpp"
#include "SunflowerSeed.hpp"
#include "PeashooterSeed.hpp"
#include "WallnutSeed.hpp"
#include "CherryBombSeed.hpp"
#include "RepeaterSeed.hpp"
#include "CooldownMask.hpp"
#include "Shovel.hpp"
#include "Sun.hpp"
#include "SkySun.hpp"
#include "FlowerSun.hpp"
#include "Zombies.hpp"
#include "RegularZombie.hpp"
#include "BucketHeadZombie.hpp"
#include "PoleVaultingZombie.hpp"

class GameWorld : public WorldBase, public std::enable_shared_from_this<GameWorld>
{
public:
  // Use shared_from_this() instead of "this".
  GameWorld();
  virtual ~GameWorld();

  bool IsLockOn(std::shared_ptr<GameObject> plant);
  bool IsCollide(std::shared_ptr<GameObject> object1, std::shared_ptr<GameObject> object2);
  bool IsFree(std::shared_ptr<GameObject> zombie);
  bool IsPole(std::shared_ptr<GameObject> pole_vaulting_zombie);

  UIName GetInHand();

  void AddObject(std::shared_ptr<GameObject> object);
  void SetInHand(UIName name);
  void GenerateSkySun();
  void GenerateZombie();
  void Collide();
  void RemoveDead();
  void Free();

  void Init() override;

  LevelStatus Update() override;

  void CleanUp() override;

private:
  int sun_tick;
  int zombie_tick;
  int zombie_num;
  int P1;
  int P2;
  int P3;
  UIName m_inhand;
  std::list<std::shared_ptr<GameObject>> m_objects;
};

#endif // !GAMEWORLD_HPP__
