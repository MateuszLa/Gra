#include <iostream>
#include <SFML/Audio.hpp>
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
        setScale(2.0,2.0);

    }

    void step( float time, int n,sf::Event &zdarzenie){

        if(n==1){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)&& getGlobalBounds().top+getGlobalBounds().height >598){
                v_y_1=-2.7;
                move(0,v_y_1);
            }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
           move(-v_x*time,0);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
           move(v_x*time,0);
        }
        if(getGlobalBounds().top+getGlobalBounds().height<600){
            v_y_1+=9.81*time/11;
             move(0,v_y_1);
        }
    }


        else{

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&& getGlobalBounds().top+getGlobalBounds().height >598){
                v_y_2=-2.7;
                 move(0,v_y_2);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
               move(-v_x*time,0);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
               move(v_x*time,0);
            }
            if(getGlobalBounds().top+getGlobalBounds().height<600){
                v_y_2+=9.81*time/11;
                move(0,v_y_2);
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
        if(getGlobalBounds().top+getGlobalBounds().height>=601){
            v_y_2=0; v_y_1=0;
       }
        if(getGlobalBounds().left+getGlobalBounds().width>=800){
            setPosition(799-getGlobalBounds().width,getGlobalBounds().top);
        }

    }

private:
    float v_x=15.5;
    float v_y_1=0;
    float v_y_2=0;
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

    void bounce(float time, Hero &s, Hero &x){
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
         if(kolo.getGlobalBounds().top+kolo.getGlobalBounds().height>=598){
              v_y=0;
         }
         if(kolo.getGlobalBounds().left+kolo.getGlobalBounds().width>=800){
              v_x=-v_x;
         }
         if(kolo.getGlobalBounds().intersects(s.getGlobalBounds())&&sf::Keyboard::isKeyPressed(sf::Keyboard::L)){
              v_x=v_x+1;
              v_y=-50;
         }
         if(kolo.getGlobalBounds().intersects(x.getGlobalBounds())&&sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
              v_x=v_x-1;
              v_y=-50;
         }


         if(kolo.getGlobalBounds().intersects(s.getGlobalBounds())&&sf::Keyboard::isKeyPressed(sf::Keyboard::J)){
              v_x=v_x-3;

         }
         if(kolo.getGlobalBounds().intersects(x.getGlobalBounds())&&sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
              v_x=v_x+3;

         }


         if(kolo.getGlobalBounds().intersects(s.getGlobalBounds())&&sf::Keyboard::isKeyPressed(sf::Keyboard::K)){
              v_x=v_x+4;
             // v_y=-40;
         }
         if(kolo.getGlobalBounds().intersects(x.getGlobalBounds())&&sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)){
              v_x=v_x-4;
             // v_y=-40;
         }

         if(kolo.getGlobalBounds().intersects(s.getGlobalBounds())&&kolo.getGlobalBounds().top<=s.getGlobalBounds().top){
             v_y=-60;
         }
         if(kolo.getGlobalBounds().intersects(x.getGlobalBounds())&&kolo.getGlobalBounds().top<=x.getGlobalBounds().top){
             v_y=-60;
         }

         if(kolo.getGlobalBounds().intersects(s.getGlobalBounds())&& s.getGlobalBounds().left>kolo.getGlobalBounds().left){
             kolo.setPosition(kolo.getGlobalBounds().left-5,kolo.getGlobalBounds().top);
             v_x=-v_x;
         }
         if(kolo.getGlobalBounds().intersects(s.getGlobalBounds())&& s.getGlobalBounds().left<kolo.getGlobalBounds().left){
            kolo.setPosition(kolo.getGlobalBounds().left+5,kolo.getGlobalBounds().top);
            v_x=-v_x;
         }
         if(kolo.getGlobalBounds().intersects(x.getGlobalBounds())&&x.getGlobalBounds().left+x.getGlobalBounds().width>kolo.getGlobalBounds().left+kolo.getGlobalBounds().width){
              kolo.setPosition(kolo.getGlobalBounds().left-5,kolo.getGlobalBounds().top);
             v_x=-v_x;
         }
         if(kolo.getGlobalBounds().intersects(x.getGlobalBounds())&& x.getGlobalBounds().left+x.getGlobalBounds().width<kolo.getGlobalBounds().left+kolo.getGlobalBounds().width){
            kolo.setPosition(kolo.getGlobalBounds().left+5,kolo.getGlobalBounds().top);
            v_x=-v_x;
         }
         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&kolo.getGlobalBounds().intersects(s.getGlobalBounds())){
             v_y=-70;
             kolo.setPosition(kolo.getGlobalBounds().left+15,kolo.getGlobalBounds().top-35);
         }

         if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)&& kolo.getGlobalBounds().intersects(x.getGlobalBounds())){
             v_y=-70;
             kolo.setPosition(kolo.getGlobalBounds().left+15,kolo.getGlobalBounds().top-35);//kolo.getGlobalBounds().width
         }
    }

    void draw(sf::RenderWindow &w){
        w.draw(kolo);
    }

    void wynik(sf::RenderWindow &w,sf:: Font &font){
        if(kolo.getGlobalBounds().left<10 && kolo.getGlobalBounds().top>295.0){
            kolo.setPosition(400,50);
            v_x=-19;
            v_y=-20;
            wynik_2=wynik_2+1;
        }
        if(kolo.getGlobalBounds().left+kolo.getGlobalBounds().width>790 && kolo.getGlobalBounds().top>295){
            kolo.setPosition(400,50);
            v_x=19;
            v_y=-20;
            wynik_1=wynik_1+1;
        }

        string tekst_1=to_string(wynik_1);
        string tekst_2=to_string(wynik_2);

        sf::Text texst;
        sf::Text texst_2;

        texst.setString(tekst_1);
        texst.setFont(font);
        texst.setCharacterSize(45);
        texst.setStyle(sf::Text::Bold | sf::Text::Underlined);
        texst.setFillColor(sf::Color::Red);
        texst.setPosition(270,20);

        texst_2.setString(tekst_2);
        texst_2.setFont(font);
        texst_2.setCharacterSize(45);
        texst_2.setStyle(sf::Text::Bold | sf::Text::Underlined);
        texst_2.setFillColor(sf::Color::Red);
        texst_2.setPosition(500,20);

        w.draw(texst);
        w.draw(texst_2);
    }

    int wynik_1=0;
    int wynik_2=0;

    void set_wynik(){
     wynik_1=wynik_2=0;
     kolo.setPosition(400,200);
    }

private:
    float v_x=19;
    float v_y=19;
    float g=9.81;
    sf::CircleShape kolo;
};


void zegar(sf:: Font &font, sf::RenderWindow &w, sf::Clock c, ball &bal){
    int time;
    time=c.getElapsedTime().asSeconds();

    string tekst_=to_string(time);
    sf::Text tekst;
    tekst.setString(tekst_);
    tekst.setFont(font);
    tekst.setCharacterSize(45);
    tekst.setStyle(sf::Text::Bold | sf::Text::Underlined);
    tekst.setFillColor(sf::Color::Red);
    tekst.setPosition(370,20);

    sf::RectangleShape zegar_(sf::Vector2f(300.0, 50.0));
    zegar_.setPosition(250,30);


    if(time==120){
        sf::RectangleShape win(sf::Vector2f(800.0, 600.0));
        sf::Texture texture_p;
        sf::Texture texture_r;
        sf::Texture texture_d;
        if(!texture_p.loadFromFile("win1.png")){
            std::cerr<<"not"<<std::endl;
        }
        if(!texture_d.loadFromFile("win2.png")){
            std::cerr<<"not"<<std::endl;
        }
        if(!texture_r.loadFromFile("rem.png")){
            std::cerr<<"not"<<std::endl;
        }

        cout<<"koniec meczu"<<endl;
        if(bal.wynik_1>bal.wynik_2){
            cout<<"WYGRAL GRACZ 1!!!"<<endl;
            win.setTexture(&texture_p);
            w.draw(win);
            w.display();
            sf::sleep(sf::milliseconds(3000));
        }
        if(bal.wynik_1<bal.wynik_2) {
            cout<<"WYGRAL GRACZ 2!!!"<<endl;
            win.setTexture(&texture_d);
            w.draw(win);
            w.display();
            sf::sleep(sf::milliseconds(3000));
        }
        if(bal.wynik_1==bal.wynik_2){
            cout<<"REMIS!!!"<<endl;
            win.setTexture(&texture_r);
            w.draw(win);
            w.display();
            sf::sleep(sf::milliseconds(3000));
        }
        w.close();
    }

    w.draw(zegar_);
    w.draw(tekst);
}

void reset_position(Hero &one, Hero &two){
    one.setPosition(588, 464);
    two.setPosition(188, 464);
}
int main()
{
    cout<<"1: Zacznij mecz."<<endl;
    cout<<"2: Wyjdz z gry."<<endl;
    cout<<"3: Opis gry."<<endl;

   sf::Font font;
   if(!font.loadFromFile("arial.ttf")){cerr<<"not";}


    sf::RectangleShape rectangle(sf::Vector2f(100, 350.0));
    rectangle.setPosition(-50, 300.0);

    sf::RectangleShape rectangle2(sf::Vector2f(100.0, 350.0));
    rectangle2.setPosition(750,300);


    sf::Texture texture;
    if (!texture.loadFromFile("guy2.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }

    sf::Texture texture_2;
   if(!texture_2.loadFromFile("pilkaa.jpg")){
       std::cerr<<"not"<<std::endl;
       return 1;
   }

   sf::Texture texture_3;
   if(!texture_3.loadFromFile("boisko.jpg")){
       std::cerr<<"not"<<std::endl;
   }

   sf::Texture texture_4;
   if(!texture_4.loadFromFile("siatka2.jpg")){
       std::cerr<<"not"<<std::endl;
   }

   sf::Texture texture_5;
   if(!texture_5.loadFromFile("4080.jpg")){
       std::cerr<<"not"<<std::endl;
   }
    texture_3.setRepeated(true);

   sf::Sprite sprite;
   sf::Sprite sprite_2;
   sf::Sprite sprite_3;
   sf::Sprite sprite_4;
   sf::Sprite sprite_5;


    sprite.setTexture(texture);
    sprite.setPosition(10,400);
    sprite_2.setPosition(400,400);
    sprite_3.setTexture(texture_3);
    sprite_3.setTextureRect({400,200,1000,2000});
    texture_3.setRepeated(true);
    sprite_5.setTexture(texture_5);
    sprite_5.setTextureRect({100,100,1000,1000});
    texture_5.setRepeated(true);
    sprite_5.setPosition(0,-800);

    Hero one;
    Hero two;

    ball Ball;
    one.add_sprite(texture);
    two.add_sprite(texture);
    Ball.add_image(texture_2);
    one.setPosition(588, 464);
    two.setPosition(188, 464);
    rectangle.setTexture(&texture_4);
    rectangle2.setTexture(&texture_4);
    int wybor;

for(;;){
cin>>wybor;
  switch(wybor){
    case 3:
      cout<<"Pierwszy gracz porusza sie klawiszami 'w' 'a' 'd'. Kopie pilke 'Lshift'-wysokie kopniecie, 'Lctrl'-niskie kopniecie."<<endl;
      cout<<"Gracz moze rowniez przyjac pilke przyciskiem 'q'."<<endl;
      cout<<"------------"<<endl;
      cout<<"Drugi gracz porusza sie strzalkami. Kopie pilke 'l'-wysokie kopniecie, 'k'-niskie kopniecie."<<endl;
      cout<<"Gracz moze rowniez przyjac pilke przyciskiem 'j'."<<endl;
      cout<<"------------"<<endl;
      cout<<"Kazde kopniecie pilki przyspiesza ja, predkosc zmniejsza po zdobyciu bramki lub przyjeciu pilki."<<endl;
      cout<<"Przyjecie pilki zwalnia tylko czesciowo pilke."<<endl;
      break;

    case 2:
    return 1;

    case 1:
      Ball.set_wynik();
      reset_position(one, two);

      sf::Music music;
        if (!music.openFromFile("muza.ogg"))
            return -1; // error
        music.play();

    sf::Clock clock6;
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
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
one.step(time,2,event);
two.street();
two.step(time,1,event);
Ball.bounce(time,one,two);
          window.clear(sf::Color::Black);
          window.draw(sprite_3);
          window.draw(sprite_5);
          window.draw(rectangle);
          window.draw(rectangle2);
          Ball.draw(window);
          window.draw(one);
          window.draw(two);
          zegar(font,window,clock6,Ball);
          Ball.wynik(window,font);
          window.display();
}
    break;
}
}
}
