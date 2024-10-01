#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

// Create the main window
RenderWindow window(VideoMode(800, 600), "Space Invader");
Texture spritesheet;
Sprite invader;

void Load() {
    if (!spritesheet.loadFromFile("res/img/invaders_sheet.png")) {
        cerr << "Failed to load spritesheet!" << std::endl;
    }
    invader.setTexture(spritesheet);
    invader.setTextureRect(IntRect(Vector2i(0, 0), Vector2i(32, 32)));
}

void Render() {
    window.draw(invader);
}

int main() {
    
    while (window.isOpen()) {
        Load();
        Render();
    }
    
    return 0;
}