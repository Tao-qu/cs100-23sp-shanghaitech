#include "SunflowerSeed.hpp"
#include "GameManager.hpp"
#include "GameWorld.hpp"

SunflowerSeed::SunflowerSeed(pGameWorld CurrentWorld) : Seeds(UIName::SunflowerSeed, IMGID_SEED_SUNFLOWER, 130, 50, CD_SUNFLOWER_SEED, CurrentWorld) {}