#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
class Mario :
    public GameObject
{
    int speed;
    sf::Texture MarioSprt;
    Animation Walk;
    Animation Swim;
    Animation Duck;
    Animation* curAni;

public:
    Mario(); //everyones favorite fat italian
    void handleInput(float dt) override;
};

