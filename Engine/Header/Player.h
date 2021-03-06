#pragma once
#include <SFML\Graphics.hpp>
#include "ActionTarget.h"
#include "Configuration.h"

#define _USE_MATH_DEFINES
#include <math.h>

class Player : public sf::Drawable, public ActionTarget<int>
{
public:
	Player(const Player&) = delete;
	Player& operator=(const Player&) = delete;
	Player();
	template<typename ... Args>
	void setPosition(Args&& ... args);
	void processEvents();
	void update(sf::Time deltaTime);
	static void setDefaultsInputs();
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates
		states) const override;
	sf::Sprite _sprite;
	sf::Vector2f _velocity;
	bool _isMoving;
	int _rotation;
};


template<typename ... Args>
void Player::setPosition(Args&& ... args)
{
	_sprite.setPosition(std::forward<Args>(args)...);
}
