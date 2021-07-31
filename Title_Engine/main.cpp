#include <SFML/Graphics.hpp>
#include <iostream>
#include "entity.h"
#include "player.h"

using namespace sf;
using namespace std;

constexpr uint16_t gameWidth = 800;
constexpr uint16_t gameHeight = 600;

void Load() {

    unique_ptr<Player> player1(new Player);
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

    

}

void Render(RenderWindow& window) {
    // Draw Everything

    
        window.draw(*s);
   
}


int main() {
    RenderWindow window(VideoMode(gameWidth, gameHeight), "Title Engine");
    Load();
    while (window.isOpen()) {
        window.clear();
        Update(window);
        Render(window);
        window.display();
    }
    return 0;
}