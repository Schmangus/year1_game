//player.cpp
#include "player.h"
#include <Windows.h>

using namespace sf;
using namespace std;

const Keyboard::Key controls[4] = {
    Keyboard::W,   // Up
    Keyboard::A,   // Left
    Keyboard::S,  // Down
    Keyboard::D // Right
};

void Player::Update(double dt) {
    // Get current position
    Vector2f position = _shape->getPosition();

    // Move in four directions based on keys
    if (Keyboard::isKeyPressed(controls[0])) { 
        position.y -= _speed * dt; // Move up
    }
    if (Keyboard::isKeyPressed(controls[1])) { 
        position.x -= _speed * dt; // Move left
    }
    if (Keyboard::isKeyPressed(controls[2])) { 
        position.y += _speed * dt; // Move down
    }
    if (Keyboard::isKeyPressed(controls[3])) { 
        position.x += _speed * dt; // Move right
    }

    // Update player position
    _shape->setPosition(position);

    Entity::Update(dt);
}

Player::Player()
    : _speed(200.0f), Entity(make_unique<CircleShape>(25.f)) {
    _shape->setFillColor(Color::Magenta);
    _shape->setOrigin(Vector2f(25.f, 25.f));
}

void Player::Render(sf::RenderWindow& window) const {
    window.draw(*_shape);
}