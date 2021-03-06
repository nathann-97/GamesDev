//ship.cpp
#include "ship.h"
#include "game.h"
#include "bullet.h"
using namespace sf;
using namespace std;

Ship::Ship() {};
bool Invader::direction;
float Invader::speed;


Ship::Ship(IntRect ir) : Sprite() {
  _sprite = ir;
  setTexture(spritesheet);
  setTextureRect(_sprite);
};

void Ship::Explode() {
    setTextureRect(IntRect(128, 32, 32, 32));
    _exploded = true;
}

void Ship::Update(const float &dt) {}

//Define the ship deconstructor. 
//Although we set this to pure virtual, we still have to define it.
Ship::~Ship() = default;


Invader::Invader() : Ship() {}

Invader::Invader(sf::IntRect ir, sf::Vector2f pos) : Ship(ir) {
    setOrigin(16, 16);
    setPosition(pos);
}

void Invader::Update(const float& dt) {
    Ship::Update(dt);

    move(dt * (direction ? 1.0f : -1.0f) * speed, 0);

    if ((direction && getPosition().x > gameWidth - 16) ||
        (!direction && getPosition().x < 16)) {
        direction = !direction;
       // for (int i = 0; i < ships.size(); ++i) {
            
         //  ships[i]-> move(0, 24);
      //  }

    }
}

Player::Player() : Ship(IntRect(160, 32, 32, 32)) {
    setPosition({ gameHeight * .5f, gameHeight - 32.f });
}

void Player::Update(const float& dt) {
    Ship::Update(dt);
    const Keyboard::Key controls[3] = {
    Keyboard::A,   // Player1 LEFT
    Keyboard::D,   // Player1 RIGHT
    Keyboard::Space, //Fire Bullet

    };
    float Playerdirection = 0.0f;
    if (Keyboard::isKeyPressed(controls[0])) {
        Playerdirection--;
    }
    if (Keyboard::isKeyPressed(controls[1])) {
        Playerdirection++;
    }
    move(Playerdirection * 100 * dt, 0);

}
