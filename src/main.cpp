#include <imgui.h>
#include <imgui-SFML.h>

#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow GameWindow(sf::VideoMode({700, 400}), "My Window");
    ImGui::SFML::Init(GameWindow);

    sf::RectangleShape Box({50, 50});
    bool BoxVisible;
    float Scale = 10;
    Box.setPosition({350, 200});
    Box.setFillColor({244, 62, 62});

    sf::Clock DeltaClock;
    while (GameWindow.isOpen()) {
        sf::Event Event;

        while (GameWindow.pollEvent(Event)) {
            ImGui::SFML::ProcessEvent(Event);

            if (Event.type == sf::Event::Closed)
                GameWindow.close();
        }

        Box.setOrigin({Box.getSize().x / 2, Box.getSize().y / 2});
        Box.setSize({Scale, Scale});

        ImGui::SFML::Update(GameWindow, DeltaClock.restart());

        ImGui::Begin("My Window");
        ImGui::Text("SUPPP!");
        ImGui::Checkbox("Box Visible", &BoxVisible);
        ImGui::SliderFloat("Box Scale", &Scale, 10, 50);
        ImGui::End();


        GameWindow.clear({125, 105, 191});
        if (BoxVisible)
            GameWindow.draw(Box);

        ImGui::SFML::Render(GameWindow);
        GameWindow.display();
    }

    ImGui::SFML::Shutdown();
    return 0;
}