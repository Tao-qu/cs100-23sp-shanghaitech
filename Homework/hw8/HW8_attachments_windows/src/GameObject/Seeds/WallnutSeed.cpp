#include "WallnutSeed.hpp"
#include "GameManager.hpp"
#include "GameWorld.hpp"

WallnutSeed::WallnutSeed(pGameWorld CurrentWorld) : Seeds(UIName::WallnutSeed, IMGID_SEED_WALLNUT, 250, 50, CD_WALLNUT_SEED, CurrentWorld) {}