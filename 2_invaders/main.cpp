#include <SFML/Graphics.hpp>
#include <iostream>


using namespace sf;
using namespace std;

sf::Texture spritesheet;
sf::Sprite invader;

const Keyboard::Key controls[4] = {
    Keyboard::W,   // Player1 Up
    Keyboard::S,   // Player1 Down
    Keyboard::A,  // Player 1 Left
    Keyboard::D // Player1 Right
};

const int gameWidth = 600;
const int gameHeight = 600;

void Load() {
    if (!spritesheet.loadFromFile("res/img/invaders_sheet.png")) {
        cerr << "Failed to load spritesheet!" << std::endl;
    }
    invader.setTexture(spritesheet);
    invader.setTextureRect(sf::IntRect(0, 0, 32, 32));
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
    window.draw(invader);
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