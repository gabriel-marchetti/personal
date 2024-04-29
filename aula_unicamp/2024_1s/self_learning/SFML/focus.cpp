#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main(){
    sf::Window window( sf::VideoMode(800, 600), "My Window" );
    
    while( window.isOpen() ){
        sf::Event event;
        while( window.pollEvent(event) ){
            if( event.type == sf::Event::Closed ){
                window.close();
            }
            
            bool focus = window.hasFocus();
            if( !focus ){
                window.setTitle("Waiting...");
                window.setSize(sf::Vector2u(400, 300));
                continue;
            }

            if( focus ){
                window.setTitle("Playing!");
                window.setSize(sf::Vector2u(800, 600));
                continue;
            }
        }
    }

    return 0;
}