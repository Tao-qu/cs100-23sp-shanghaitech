#include "CherryBombSeed.hpp"
#include "GameManager.hpp"
#include "GameWorld.hpp"

CherryBombSeed::CherryBombSeed(pGameWorld CurrentWorld) : Seeds(UIName::CherryBombSeed, IMGID_SEED_CHERRY_BOMB, 310, 150, CD_CHERRY_BOMB_SEED, CurrentWorld) {}