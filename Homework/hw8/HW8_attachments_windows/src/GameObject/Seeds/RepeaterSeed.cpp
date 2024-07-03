#include "RepeaterSeed.hpp"
#include "GameManager.hpp"
#include "GameWorld.hpp"

RepeaterSeed::RepeaterSeed(pGameWorld CurrentWorld) : Seeds(UIName::RepeaterSeed, IMGID_SEED_REPEATER, 370, 200, CD_REPEATER_SEED, CurrentWorld) {}