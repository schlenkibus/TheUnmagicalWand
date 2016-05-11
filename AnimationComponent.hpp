#pragma once

#include <SFML/Graphics.hpp>
#include "AnimatedSprite.h"
#include "Animation.h"

class PlayerAnimation
{
public:
  PlayerAnimation()
  {
    faceRight = false; inJump = false;

    spritesheetIdleR.loadFromFile("art/player/wand-anims/idle/idleR.png");
    spritesheetIdleL.loadFromFile("art/player/wand-anims/idle/idleL.png");

    idleR.setSpriteSheet(spritesheetIdleR);
    idleL.setSpriteSheet(spritesheetIdleL);

    loadIdle();

    sprite.setAnimation(idleR);

    sprite.setFrameTime(sf::seconds(0.1f));

    sprite.setLooped(true);
  };
  void facesRight(bool s)
  {
    faceRight = s;
  };
  void isJumping(bool s)
  {
    inJump = s;
  };
  AnimatedSprite& getSprite()
  {
    return sprite;
  };
  void setPosition(sf::Vector2f pos)
  {
    sprite.setPosition(pos);
  };
  void setOrigin(sf::Vector2f f)
  {
    sprite.setOrigin(f);
  };
  void update(sf::Time deltaTime)
  {
    sprite.update(deltaTime);
  };
private:
  AnimatedSprite sprite;
  Animation walkR, walkL, jumpL, jumpR, idleL, idleR;
  sf::Texture spritesheetIdleL, spritesheetIdleR;
  bool faceRight, inJump;

  void loadIdle() //Right now only R
  {
    idleR.addFrame(sf::IntRect(0, 27, 33, 100));
    idleR.addFrame(sf::IntRect(37, 27, 33, 100));
    idleR.addFrame(sf::IntRect(71, 27, 33, 100));
    idleR.addFrame(sf::IntRect(106, 27, 33, 100));
    idleR.addFrame(sf::IntRect(139, 27, 33, 100));
    idleR.addFrame(sf::IntRect(174, 27, 33, 100));
    idleR.addFrame(sf::IntRect(207, 27, 33, 100));
    idleR.addFrame(sf::IntRect(241, 27, 33, 100));
  }
};
