# CU4012-Week-22-Animation-and-Audio

```c++
void Mario::handleInput(float dt)
{
	velocity.x = 0.f;

	setTextureRect(currentAnimation->getCurrentFrame());

	if (input->isKeyDown(sf::Keyboard::A))
	{
		velocity.x = -speed;
		currentAnimation = &walk;
		currentAnimation->animate(dt);
		currentAnimation->setFlipped(true);
	}
	else if (input->isKeyDown(sf::Keyboard::D))
	{
		velocity.x = speed;
		currentAnimation = &walk;
		currentAnimation->animate(dt);
		currentAnimation->setFlipped(false);
	}
	else
	{
		currentAnimation->reset();
	}

	if (input->isKeyDown(sf::Keyboard::Space) && canJump)
	{
		Jump(200.f);
		audio->playSoundbyName("jump");
	}
}```
