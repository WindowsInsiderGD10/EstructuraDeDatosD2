#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Ventana de prueba");
    sf::Font font;
    if (!font.openFromFile("fontananegra.ttf")) {
        return -1;
    }

    sf::Text mensaje(font, "¿Y tu porque carajos hiciste esto?", 24);
    mensaje.setPosition({100, 100});
    mensaje.setFillColor(sf::Color::White);

    sf::RectangleShape boton(sf::Vector2f(120, 40));
    boton.setPosition({100, 200});

    sf::Text textoBoton(font, "Cerrar", 20);
    textoBoton.setPosition({110, 210});
    textoBoton.setFillColor(sf::Color::White);

    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();

            if (event->is<sf::Event::MouseButtonPressed>()) {
                sf::Vector2i mouse = sf::Mouse::getPosition(window);
                if (boton.getGlobalBounds().contains(sf::Vector2f(mouse)))
                    window.close();
            }
        }

        window.clear(sf::Color(30, 30, 30));
        window.draw(mensaje);
        window.draw(boton);
        window.draw(textoBoton);
        window.display();
    }

    return 0;
}