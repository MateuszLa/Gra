#include <iostream>
#include<vector>
#include<string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace std;

class Hero :public sf::Sprite{
public:
    Hero():sf::Sprite(){}
    void add_sprite(sf::Texture &temp){

        setTexture(temp);
        setScale(2,2);

    }
    void step( float time, int n){
        cout<<getGlobalBounds().top<<endl;
        if(n==1){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            move(0,-time*v_y);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            move(0,v_y*time);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
           move(-v_x*time,0);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
           move(v_x*time,0);
        }
    }
        else{
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                move(0,-time*v_y);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                move(0,v_y*time);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
               move(-v_x*time,0);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
               move(v_x*time,0);
            }
        }
    }
    void street(){
        if(getGlobalBounds().top<=0){
            setPosition(getGlobalBounds().left,1);
        }
        if(getGlobalBounds().left<=0){
            setPosition(1,getGlobalBounds().top);
        }
        if(getGlobalBounds().top+getGlobalBounds().height>=600){
            setPosition(getGlobalBounds().left,599-getGlobalBounds().height);
       }
        if(getGlobalBounds().left+getGlobalBounds().width>=800){
            setPosition(799-getGlobalBounds().width,getGlobalBounds().top);
        }
    }
private:
    float v_x=20.0;
    float v_y=20.0;

};

class ball{
 public:
    ball(){sf::CircleShape k;}
    void add_image(sf::Texture &temp){
        kolo.setRadius(15);
        kolo.setTexture(&temp);
        kolo.setScale(2,2);
       kolo.setPosition(400,200);
    }
    void bounce(float time, Hero s, Hero x){
        kolo.move(v_x*time,v_y*time);
        if(kolo.getGlobalBounds().top<598){
            v_y=v_y+g*time;
        }
         if(kolo.getGlobalBounds().top<=5){
             v_y=-v_y;
         }
         if(kolo.getGlobalBounds().left<=0){
             v_x=-v_x;
         }
         if(kolo.getGlobalBounds().top+kolo.getGlobalBounds().height>=600){
              v_y=0;
         }
         if(kolo.getGlobalBounds().left+kolo.getGlobalBounds().width>=800){
              v_x=-v_x;
         }
         if(kolo.getGlobalBounds().intersects(s.getGlobalBounds())&&sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
              v_x=v_x+10;
              v_y=-40;
         }
         if(kolo.getGlobalBounds().intersects(s.getGlobalBounds())){
              v_x=-v_x;
         }
         if(kolo.getGlobalBounds().intersects(x.getGlobalBounds())){
              v_x=-v_x;
         }
    }
    void wynik(){
        if(kolo.getGlobalBounds().left<10 && kolo.getGlobalBounds().top>295.0){
            kolo.setPosition(300,300);
            v_x=10;
        }
        if(kolo.getGlobalBounds().left+kolo.getGlobalBounds().width>790 && kolo.getGlobalBounds().top>295){
            kolo.setPosition(300,300);
            v_x=10;
        }
    }
    void draw(sf::RenderWindow &w){
        w.draw(kolo);
    }
private:
    float v_x=10;
    float v_y=10;
    float g=9.81;
    sf::CircleShape kolo;
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
   sf::Font font;
   if(!font.loadFromFile("arial.ttf")){cerr<<"not";}
    sf::Text tekst;
    tekst.setString("hej");
    tekst.setFont(font);
    tekst.setCharacterSize(24);
    tekst.setFillColor(sf::Color::Red);
    tekst.setStyle(sf::Text::Bold | sf::Text::Underlined);
    tekst.setPosition(400,300);
    sf::RectangleShape rectangle(sf::Vector2f(10, 350.0));
    rectangle.setPosition(1.0, 300.0);
    rectangle.setOutlineColor(sf::Color::Red);

    sf::RectangleShape rectangle2(sf::Vector2f(100.0, 350.0));
    rectangle2.setPosition(790,300);
    rectangle2.setOutlineColor(sf::Color::Red);

    sf::Texture texture;
    if (!texture.loadFromFile("guy.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }

    sf::Texture texture_2;
   if(!texture_2.loadFromFile("grass.png")){
       std::cerr<<"not"<<std::endl;
       return 1;
   }
   sf::Texture texture_3;
   if(!texture_3.loadFromFile("wall.png")){
       std::cerr<<"not"<<std::endl;
   }
    texture_3.setRepeated(true);
   sf::Sprite sprite;
   sf::Sprite sprite_2;
   sf::Sprite sprite_3;

   sprite.setTexture(texture);
   sprite.setPosition(10,400);
   //sprite_2.setTexture(texture_2);
  //sprite_2.setScale(0.1,0.1);
   sprite_2.setPosition(400,400);
   sprite_3.setTexture(texture_3);
   sprite_3.setTextureRect({100,100,1000,1000});
    texture_3.setRepeated(true);

    Hero one;
    Hero two;
    ball Ball;
    one.add_sprite(texture);
    two.add_sprite(texture);
    Ball.add_image(texture_2);
    one.setPosition(588, 12);
    sf::Clock clock;
      while (window.isOpen()) {
        float time;
        time=float(clock.getElapsedTime().asMicroseconds())/100000;
        clock.restart();
          sf::Event event;
          while (window.pollEvent(event)) {

              if (event.type == sf::Event::Closed)
                  window.close();
          }
one.street();
one.step(time,2);
two.street();
two.step(time,1);
Ball.bounce(time,one,two);
Ball.wynik();
          window.clear(sf::Color::Black);
       window.draw(sprite_3);
          window.draw(rectangle);
          window.draw(rectangle2);
          //window.draw(Ball);
          Ball.draw(window);
          window.draw(one);
          window.draw(two);
         window.draw(tekst);
          window.display();
}
      return 0;
}
