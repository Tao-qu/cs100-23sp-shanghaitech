#include "BucketHeadZombie.hpp"
#include "GameManager.hpp"
#include "GameWorld.hpp"

BucketHeadZombie::BucketHeadZombie(int x, int y, pGameWorld CurrentWorld) : Zombies(IMGID_BUCKET_HEAD_ZOMBIE, x, y, ANIMID_WALK_ANIM, HP_Bucket_Head_Zombie, ATK_BUCKET_HEAD_ZOMBIE, CurrentWorld) {}

void BucketHeadZombie::Update()
{
    if (!IsDead())
    {
        if (GetCurrentAnimation() == ANIMID_WALK_ANIM)
        {
            MoveTo(GetX() - 1, GetY());
        }
        if (GetHP() <= HP_REGULAR_ZOMBIE && m_bucket != 0)
        {
            ChangeImage(IMGID_REGULAR_ZOMBIE);
            --m_bucket;
        }
    }
}