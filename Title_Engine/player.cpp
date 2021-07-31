#include "player.h"


using namespace sf;
using namespace std;

void Player::Update(double dt) {
    //Move in four directions based on keys
    float direction = 0.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        direction--;
        move(_position * direction * _speed);
   }
   

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