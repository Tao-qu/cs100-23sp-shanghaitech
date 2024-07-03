#ifndef PLANTINGSPOT_HPP__
#define PLANTINGSPOT_HPP__

#include "GameObject.hpp"

class PlantingSpot : public GameObject
{
public:
    PlantingSpot(int x, int y, pGameWorld CurrentWorld);

    void OnClick() override;

private:
};

#endif // !PLANTINGSPOT_HPP__