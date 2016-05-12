#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Hud //Not only render but also keeps track of pickups
{
public:
  Hud()
  {
    s_stoneCount = 0;
    s_fireCount = 0;
    s_webCount = 0;

    if(!font.loadFromFile("art/fonts/temp2.ttf") &&
       !stoneTex.loadFromFile("art/hud/stone.png")&&
       !fireTex.loadFromFile("art/hud/fire.png") &&
       !webTex.loadFromFile("art/hud/web.png") &&
       !emptyTex.loadFromFile("art/hud/empty.png"))
    {
      exit(99);
    }

    stoneTex.loadFromFile("art/hud/stone.png");
    fireTex.loadFromFile("art/hud/fire.png");
    webTex.loadFromFile("art/hud/web.png");
    emptyTex.loadFromFile("art/hud/empty.png");
    //Setup of all the icons
    stoneCount.setFont(font); fireCount.setFont(font);  webCount.setFont(font);
    stonePickups.setTexture(stoneTex); firePickups.setTexture(fireTex); webPickups.setTexture(webTex);
    stonePickups.setPosition(900, 50);  stoneCount.setPosition(950, 50);
    firePickups.setPosition(900, 100);  fireCount.setPosition(950, 100);
    webPickups.setPosition(900, 150);   webCount.setPosition(950, 150);

    stoneCount.setString("0/3");
    webCount.setString("0/3");
    fireCount.setString("0/3");
  };

  void update()
  {
    //Nothing yet
  };

  void draw(sf::RenderWindow& window)
  {
    window.draw(stonePickups);
    window.draw(firePickups);
    window.draw(webPickups);
    window.draw(stoneCount);
    window.draw(fireCount);
    window.draw(webCount);
  };

  void addStoneCount()
  {
    s_stoneCount++;

    if(s_stoneCount == 1)
      stoneCount.setString("1/3");
    else if(s_stoneCount == 2)
      stoneCount.setString("2/3");
    else if(s_stoneCount == 3)
      stoneCount.setString("3/3");
  };
  void addFireCount()
  {
    s_fireCount++;

    if(s_fireCount == 1)
      fireCount.setString("1/3");
    else if(s_fireCount == 2)
      fireCount.setString("2/3");
    else if(s_fireCount == 3)
      fireCount.setString("3/3");
  };
  void addWebCount()
  {
    s_webCount++;

    if(s_webCount == 1)
      webCount.setString("1/3");
    else if(s_webCount == 2)
      webCount.setString("2/3");
    else if(s_webCount == 3)
      webCount.setString("3/3");
  };

private:
  sf::Sprite stonePickups, firePickups, webPickups;
  sf::Texture stoneTex, fireTex, webTex, emptyTex;
  sf::Font font;
  sf::Text stoneCount, fireCount, webCount;
  short s_stoneCount, s_fireCount, s_webCount;
};
