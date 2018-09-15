#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    sf::RenderTexture renderTexture;
    if (!renderTexture.create(800, 600)) {
        std::cerr << "Render texture creation failed" << std::endl;
        return 1;
    }
    // on fait tourner le programme jusqu'à ce que la fenêtre soit fermée
    while (window.isOpen())
    {
        // on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
        sf::Event event;
        
        window.clear(sf::Color::Black);
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::CircleShape circle(10);
                circle.setPosition(sf::Vector2f(event.mouseButton.x - 10,  renderTexture.getSize().y - (event.mouseButton.y + 10)));
                renderTexture.draw(circle);
            }
            // évènement "fermeture demandée" : on ferme la fenêtre
            if (event.type == sf::Event::Closed)
                window.close();
        }
        sf::Sprite sprite(renderTexture.getTexture());
        window.draw(sprite);
        window.display();
    }

    return 0;
}