#include "PeashooterSeed.hpp"
#include "GameManager.hpp"
#include "GameWorld.hpp"

PeashooterSeed::PeashooterSeed(pGameWorld CurrentWorld) : Seeds(UIName::PeashooterSeed, IMGID_SEED_PEASHOOTER, 190, 100, CD_PEASHOOTER_SEED, CurrentWorld) {}