#include "Entity.h"

Entity::Entity(Configuration::Textures tex_id, World& world) : _world(world), _alive(true)
{
	sf::Texture& texture = Configuration::textures.get(tex_id);
	_sprite.setTexture(texture);
	_sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
}

bool Entity::isAlive() const
{
	return _alive;
}

void Entity::onDestroy()	
{
	_alive = false;
}