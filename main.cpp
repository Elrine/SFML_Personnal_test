#include <SFML/System.hpp>
#include <iostream>

void func() {
    
    for(size_t i = 0; i < 10; i++)
    {
        std::cout << "I'm thread number one" << std::endl;
    }
    
}

int main()
{
    sf::Thread thread(&func);

    thread.launch();

    
    for(size_t i = 0; i < 10; i++)
    {
        std::cout << "I'm the main thread" << std::endl;
    }
    return 0;
}