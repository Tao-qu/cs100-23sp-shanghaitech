#include "Background.hpp"
#include "GameManager.hpp"
#include "GameWorld.hpp"

Background::Background(pGameWorld CurrentWorld) : GameObject(IMGID_BACKGROUND, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, LAYER_BACKGROUND, WINDOW_WIDTH, WINDOW_HEIGHT, ANIMID_NO_ANIMATION, HP_IMMORTAL, ATK_NONE, CurrentWorld) {}