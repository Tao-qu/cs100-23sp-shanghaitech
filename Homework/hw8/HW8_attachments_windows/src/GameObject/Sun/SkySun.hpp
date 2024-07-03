#ifndef SKYSUN_HPP__
#define SKYSUN_HPP__

#include "Sun.hpp"

class SkySun : public Sun
{
public:
    SkySun(pGameWorld CurrentWorld);

    void Update() override;

private:
};

#endif // !SKYSUN_HPP__