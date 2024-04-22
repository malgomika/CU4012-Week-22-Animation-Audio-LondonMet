#include "Mario.h"

Mario::Mario()
{
	speed = 200;

	MarioSprt.loadFromFile("gfx/MarioSheetT.png");
	setSize(sf::Vector2f(15*4, 21*4));
	setPosition(100, 100);
	setTexture(&MarioSprt);
	
	//w
	Walk.addFrame(sf::IntRect(0, 0, 15, 21));
	Walk.addFrame(sf::IntRect(15, 0, 15, 21));
	Walk.addFrame(sf::IntRect(30, 0, 15, 21));
	Walk.addFrame(sf::IntRect(45, 0, 15, 21));
	Walk.setFrameSpeed(1.f / 10.f);

	//swim
	Swim.addFrame(sf::IntRect(0, 0, 15, 21));
	Swim.addFrame(sf::IntRect(16, 0, 15, 21));
	Swim.addFrame(sf::IntRect(32, 0, 15, 21));
	Swim.setFrameSpeed(1.f / 10.f);

	//duck
	Duck.addFrame(sf::IntRect(0, 44, 17, 17));
	//Duck.addFrame(sf::IntRect(17, 44, 17, 17));
	Duck.setFrameSpeed(1.f / 10.f);

	curAni = &Walk;
}

void Mario::handleInput(float dt)
{
	velocity.x = 0.f;
	setTextureRect(Walk.getCurrentFrame());

	//this is right
	if (input->isKeyDown(sf::Keyboard::D)) {
		velocity.x = speed;
		curAni = &Walk;
		curAni->setFlipped(false);
	}

	//and this is left
	else if (input->isKeyDown(sf::Keyboard::A)) {
		velocity.x = -speed;
		curAni = &Walk;
		curAni->setFlipped(true);
	}

	//hell if i know what this does
	else if (input->isKeyDown(sf::Keyboard::S)) {
		curAni = &Duck;
	}
	
	else {
		curAni->reset();
		curAni = &Walk;
	}

	//jump
	if (input->isKeyDown(sf::Keyboard::W) && canJump) {
		Jump(200.f);
		audio->playSoundbyName("jump");
	}

	curAni->animate(dt);
}
