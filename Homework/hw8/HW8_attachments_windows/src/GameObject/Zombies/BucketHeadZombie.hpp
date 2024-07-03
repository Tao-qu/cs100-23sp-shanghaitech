#ifndef BUCKETHEADZOMBIE_HPP__
#define BUCKETHEADZOMBIE_HPP__

#include "Zombies.hpp"

class BucketHeadZombie : public Zombies
{
public:
    BucketHeadZombie(int x, int y, pGameWorld CurrentWorld);

    void Update() override;

private:
    int m_bucket{1};
};

#endif // !BUCKETHEADZOMBIE_HPP__