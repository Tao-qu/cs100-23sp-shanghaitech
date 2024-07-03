#include "GameWorld.hpp"

GameWorld::GameWorld() {}

GameWorld::~GameWorld() {}

bool GameWorld::IsLockOn(std::shared_ptr<GameObject> plant)
{
  if ((*plant).IsPlant())
  {
    for (auto &zombie : m_objects)
    {
      if ((*zombie).IsZombie())
      {
        if ((*zombie).GetX() >= (*plant).GetX() && (*zombie).GetY() == (*plant).GetY())
        {
          return true;
        }
      }
    }
  }
  return false;
}

bool GameWorld::IsCollide(std::shared_ptr<GameObject> object1, std::shared_ptr<GameObject> object2)
{
  return abs((*object1).GetX() - (*object2).GetX()) < (((*object1).GetWidth() + (*object2).GetWidth()) / 2) && abs((*object1).GetY() - (*object2).GetY()) < (((*object1).GetHeight() + (*object2).GetHeight()) / 2);
}

bool GameWorld::IsPole(std::shared_ptr<GameObject> pole_vaulting_zombie)
{
  for (auto &plant : m_objects)
  {
    if ((*plant).IsPlant())
    {
      if (abs((*pole_vaulting_zombie).GetX() - 40 - (*plant).GetX()) < (((*pole_vaulting_zombie).GetWidth() + (*plant).GetWidth()) / 2) && abs((*pole_vaulting_zombie).GetY() - (*plant).GetY()) < (((*pole_vaulting_zombie).GetHeight() + (*plant).GetHeight()) / 2))
      {
        return true;
      }
    }
  }
  return false;
}

bool GameWorld::IsFree(std::shared_ptr<GameObject> zombie)
{
  if ((*zombie).IsZombie())
  {
    for (auto &plant : m_objects)
    {
      if ((*plant).IsPlant() && IsCollide(zombie, plant))
      {
        return false;
      }
    }
  }
  return true;
}

UIName GameWorld::GetInHand()
{
  return m_inhand;
}

void GameWorld::AddObject(std::shared_ptr<GameObject> object)
{
  m_objects.push_back(object);
}

void GameWorld::SetInHand(UIName name)
{
  m_inhand = name;
}

void GameWorld::GenerateSkySun()
{
  if (sun_tick == 0)
  {
    sun_tick = 300;
    AddObject(std::make_shared<SkySun>(shared_from_this()));
  }
  --sun_tick;
}

void GameWorld::GenerateZombie()
{
  if (zombie_tick == 0)
  {
    SetWave(GetWave() + 1);
    zombie_num = floor((15 + GetWave()) / 10);
    zombie_tick = std::max(150, 600 - 20 * GetWave());
    P2 = 2 * std::max(GetWave() - 8, 0);
    P3 = 3 * std::max(GetWave() - 15, 0);

    for (int i = 0; i != zombie_num; ++i)
    {
      int PR = randInt(0, P1 + P2 + P3 - 1);
      if (PR < P1)
      {
        AddObject(std::make_shared<RegularZombie>(randInt(WINDOW_WIDTH - 40, WINDOW_WIDTH - 1), FIRST_ROW_CENTER + randInt(0, 4) * LAWN_GRID_HEIGHT, shared_from_this()));
      }
      else if (PR < P1 + P2)
      {
        AddObject(std::make_shared<BucketHeadZombie>(randInt(WINDOW_WIDTH - 40, WINDOW_WIDTH - 1), FIRST_ROW_CENTER + randInt(0, 4) * LAWN_GRID_HEIGHT, shared_from_this()));
      }
      else
      {
        AddObject(std::make_shared<PoleVaultingZombie>(randInt(WINDOW_WIDTH - 40, WINDOW_WIDTH - 1), FIRST_ROW_CENTER + randInt(0, 4) * LAWN_GRID_HEIGHT, shared_from_this()));
      }
    }
  }
  --zombie_tick;
}

void GameWorld::Collide()
{
  for (auto object1 = m_objects.begin(); object1 != m_objects.end(); ++object1)
  {
    for (auto object2 = object1; object2 != m_objects.end(); ++object2)
    {
      if (object1 != object2 && !(**object1).IsDead() && !(**object2).IsDead())
      {
        if (IsCollide(*object1, *object2))
        {
          (**object1).Collide(*object2);
          (**object2).Collide(*object1);
        }
      }
    }
  }
}

void GameWorld::RemoveDead()
{
  for (auto object = m_objects.begin(); object != m_objects.end();)
  {
    if ((**object).IsDead())
    {
      m_objects.erase(object++);
    }
    else
    {
      ++object;
    }
  }
}

void GameWorld::Free()
{
  for (auto &zombie : m_objects)
  {
    if ((*zombie).IsZombie() && (*zombie).GetCurrentAnimation() == ANIMID_EAT_ANIM && IsFree(zombie))
    {
      (*zombie).PlayAnimation(ANIMID_WALK_ANIM);
    }
  }
}

void GameWorld::Init()
{
  // YOUR CODE HERE
  SetWave(0);
  SetSun(50);
  sun_tick = 180;
  zombie_tick = 1200;
  zombie_num = floor((GetWave() + 15) / 10);
  P1 = 20;
  P2 = 2 * std::max(GetWave() - 8, 0);
  P3 = 3 * std::max(GetWave() - 15, 0);
  m_inhand = UIName::None;

  AddObject(std::make_shared<Background>(shared_from_this()));
  for (int i = 0; i != GAME_COLS; ++i)
  {
    for (int j = 0; j != GAME_ROWS; ++j)
    {
      AddObject(std::make_shared<PlantingSpot>(FIRST_COL_CENTER + i * LAWN_GRID_WIDTH, FIRST_ROW_CENTER + j * LAWN_GRID_HEIGHT, shared_from_this()));
    }
  }
  AddObject(std::make_shared<SunflowerSeed>(shared_from_this()));
  AddObject(std::make_shared<PeashooterSeed>(shared_from_this()));
  AddObject(std::make_shared<WallnutSeed>(shared_from_this()));
  AddObject(std::make_shared<CherryBombSeed>(shared_from_this()));
  AddObject(std::make_shared<RepeaterSeed>(shared_from_this()));
  AddObject(std::make_shared<Shovel>(shared_from_this()));
}

LevelStatus GameWorld::Update()
{
  // YOUR CODE HERE
  GenerateSkySun();
  GenerateZombie();
  for (auto &object : m_objects)
  {
    (*object).Update();
  }
  Collide();
  RemoveDead();
  for (auto &object : m_objects)
  {
    if ((*object).IsZombie() && (*object).GetX() < 0)
    {
      return LevelStatus::LOSING;
    }
  }
  Free();
  return LevelStatus::ONGOING;
}

void GameWorld::CleanUp()
{
  // YOUR CODE HERE
  m_objects.clear();
}