#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SFML/Graphics.hpp>
#include <iostream>

const float WIDTH = 1200;
const float HEIGHT = 900;

sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "OpenGL", sf::Style::Default, sf::ContextSettings(32));

class Button {
    inline static float prevWidth = 0, prevHeight = 0, prevX = 0, prevY = 0;
    inline static sf::Texture prevTex;
    inline static sf::Font prevFont;
    sf::Sprite button;
    sf::Text text;
public:
    sf::FloatRect hitbox;
    Button(float x, float y, float width, float height, const std::wstring& label, sf::Texture &buttonTex, sf::Font &font)
    : text(label, font, 20) {
            button.setPosition(x, y);
            button.setTexture(buttonTex);
            button.setScale(width/buttonTex.getSize().x, height/buttonTex.getSize().y);
            hitbox = button.getGlobalBounds();
            text.setFillColor(sf::Color::White);
            text.setOrigin(text.getLocalBounds().width/2, text.getLocalBounds().height/1.5);
            text.setPosition(x+width/2, y+height/2);
        }
    Button(const std::wstring& label)
    : Button(prevX, prevY, prevWidth, prevHeight, label, prevTex, prevFont) {
            prevY += prevHeight+10;
        }
    static void setParameters(float x, float y, float width, float height, sf::Texture& buttonTex, sf::Font& font) {
        prevWidth = width;
        prevHeight = height;
        prevX = x;
        prevY = y;
        prevTex = buttonTex;
        prevFont = font;
    }

    void draw() const {
        window.pushGLStates();
        window.draw(button);
        window.draw(text);
        window.popGLStates();
    }
};
class Planet {
public:
    Planet(float size, float tilt, const char* path)
    : size(size), tilt(tilt) {
        texture.loadFromFile(path);
    }
    void render(float angle, int flag = 0) {
        glPushMatrix();
        glRotatef(tilt, 0.5f, 0.0f, -1.0f);
        glRotatef(90+flag%2*180, 1.0f, 0.0f, 0.0f);
        glRotatef(angle, 0.0f, 0.0f, -1.0f);
        if ((flag>>1)%2) glTranslatef(0.0f, (flag>>2)*size, 0.0f);
        sf::Texture::bind(&texture);
        GLUquadric* quadric = gluNewQuadric();
        gluQuadricTexture(quadric, GL_TRUE);
        if (flag%2) gluDisk(quadric, size+0.1, size+0.7, 128, 32);
        else gluSphere(quadric, size, 128, 32);
        gluDeleteQuadric(quadric);
        glPopMatrix();
    }
    float size, tilt;
    sf::Texture texture;
};

int main() {    
    window.setVerticalSyncEnabled(true);
    window.setActive(true);
    
    sf::Texture background;
    sf::Sprite backgroundImage;
    background.loadFromFile("textures\\space.jpg");
    backgroundImage.setTexture(background);
    backgroundImage.setScale(WIDTH/background.getSize().x, HEIGHT/background.getSize().y);

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    GLfloat lightPosition[] = {5.0f, 0.0f, 3.0f, 1.0f};
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable (GL_COLOR_MATERIAL);

    sf::Texture buttonTexture;
    buttonTexture.loadFromFile("textures\\button.png");
    sf::Font buttonFont;
    buttonFont.loadFromFile("arial.ttf");
    Button::setParameters(1080, 335, 100, 50, buttonTexture, buttonFont);
    Button buttons[] = {
        Button(L"Земля"),
        Button(L"Марс"),
        Button(L"Юпитер"),
        Button(L"Сатурн")
    };
    

    Planet earth(0.5, 23, "textures\\earth.jpg");
    Planet mars(0.4, 25, "textures\\mars.jpg");
    Planet jupiter(0.8, 3, "textures\\jupiter.jpg");
    Planet saturn(0.6, 26, "textures\\saturn.jpg");
    Planet rings(0.6, 26, "textures\\rings.jpg");
    Planet moon(0.1, 0, "textures\\moon.jpg");
    Planet phobos(0.1, 0, "textures\\phobos.jpg");
    Planet deimos(0.1, 0, "textures\\deimos.jpg");

    float angle = 0.0f;
    int frame = 0;
    bool running = true;
    while (running)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) running = false;
            else if (event.type == sf::Event::Resized) {
                glViewport(0, 0, event.size.width, event.size.height);
            } else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                for (int i = 0; i < 4; i++) if (buttons[i].hitbox.contains(mousePos)) frame = i;
            }
        }
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glFrustum(-1*WIDTH/HEIGHT/2, WIDTH/HEIGHT/2, -0.5, 0.5, 1.0, 5.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0, 0, -3);
        
        window.pushGLStates();
        window.draw(backgroundImage);
        window.popGLStates();
        angle += 0.5f;
        switch (frame) {
        case 0:
            earth.render(angle);
            moon.render(0.2*angle, 34);
            break;
        case 1:
            mars.render(angle);
            phobos.render(-0.2*angle, 34);
            deimos.render(0.4*angle, 50);
            break;
        case 2:
            jupiter.render(0.6*angle);
            break;
        case 3:
            saturn.render(0.8*angle);
            rings.render(-0.1*angle, 1);
            break;
        }
        for (Button b : buttons) b.draw();
        window.display();
    }
}
