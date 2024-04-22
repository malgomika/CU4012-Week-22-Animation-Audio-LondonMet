#include "Zombie.h"

Zombie::Zombie()
{
	speed = 200;

	ZombieSprSht.loadFromFile("gfx/animZombie.png");
	setSize(sf::Vector2f(55*2, 108*2)); 
	setPosition(100, 100);
	setTexture(&ZombieSprSht);

	Walk.addFrame(sf::IntRect(0, 0, 55, 108));
	Walk.addFrame(sf::IntRect(55, 0, 55, 108));
	Walk.addFrame(sf::IntRect(110, 0, 55, 108));
	Walk.addFrame(sf::IntRect(165, 0, 55, 108));
	Walk.addFrame(sf::IntRect(220, 0, 55, 108));
	Walk.addFrame(sf::IntRect(275, 0, 55, 108));
	Walk.addFrame(sf::IntRect(330, 0, 55, 108));
	Walk.addFrame(sf::IntRect(385, 0, 55, 108));

	Walk.setFrameSpeed(1.f / 10.0f);
}

void Zombie::update(float dt)
{
	//Walk.animate(dt);
	//setTextureRect(Walk.getCurrentFrame());
	
	/*i bought aseprite off of steam when there was a sale one time
	worth it for the plugins you can download off of the internet for it*/
}

void Zombie::handleInput(float dt)
{
	velocity.x = 0;
	setTextureRect(Walk.getCurrentFrame());

	//this is right
	if (input->isKeyDown(sf::Keyboard::D)) {
		velocity.x = speed;
		Walk.setFlipped(false);
		Walk.animate(dt);
	}

	//and this is left
	if (input->isKeyDown(sf::Keyboard::A)) {
		velocity.x = -speed;
		Walk.setFlipped(true);
		Walk.animate(dt);
	}

	//boing
	if (input->isKeyDown(sf::Keyboard::W) && canJump) {
		Jump(200.f);
		audio->playSoundbyName("jump");
	}
}
