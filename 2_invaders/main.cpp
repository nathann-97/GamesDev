#include <SFML/Graphics.hpp>
#include <iostream>
#include "ship.h"
#include "game.h"



using namespace sf;
using namespace std;

sf::Texture spritesheet;
sf::Sprite invader;
std::vector<Ship*> ships;




void Load() {
    if (!spritesheet.loadFromFile("res/img/invaders_sheet.png")) {
        cerr << "Failed to load spritesheet!" << std::endl;
    }
    invader.setTexture(spritesheet);
    invader.setTextureRect(sf::IntRect(0, 0, 32, 32));

    Invader::speed = 20.f;
    
    for (int r = 0; r < invaders_rows; ++r) {
        auto rect = IntRect(0, 0, 32, 32);
        for (int c = 0; c < invaders_columns;  ++c) {
            Vector2f position = Vector2f(c*50, r*50);
            auto inv = new Invader(rect, position);
            ships.push_back(inv);
        }
    }

    auto player = new Player();
    ships.push_back(player);
   
}

void Reset() {
    
}

void Update(RenderWindow& window) {
    // Reset clock, recalculate deltatime
    static Clock clock;
    float dt = clock.restart().asSeconds();
    // check and consume events
    Event event;
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed) {
            window.close();
            return;
        }
    }

    // Quit Via ESC Key
    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        window.close();
    }

    for (auto& s : ships) {
        s->Update(dt);
    };
}

void Render(RenderWindow& window) {
    // Draw Everything
   

    for (const auto s : ships) {
        window.draw(*s);
    }
}

int main() {
    RenderWindow window(VideoMode(gameWidth, gameHeight), "SPACE INVADERS");
    Load();
    while (window.isOpen()) {
        window.clear();
        Update(window);
        Render(window);
        window.display();
    }
    return 0;
}