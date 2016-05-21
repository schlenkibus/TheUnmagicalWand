#pragma once

#include <SFML/Graphics.hpp>
#include "AnimatedSprite.h"
#include "Animation.h"

class PlayerAnimation
{
private:
    enum currentPower {none, fire, web, stone};
    enum direction {right, left};
public:
  PlayerAnimation()
  {
    faceRight = false; inJump = false;
    dir = right;
    powerState = none;
    //Idle Animations
    spritesheetIdleR.loadFromFile("art/player/wand-anims/idle/idleR.png");
    spritesheetIdleL.loadFromFile("art/player/wand-anims/idle/idleL.png");
    ssFireIdleR.loadFromFile("art/player/wand-anims/idle/matchIdleR.png");
    ssFireIdleL.loadFromFile("art/player/wand-anims/idle/matchIdleL.png");
    ssWebIdleR.loadFromFile("art/player/wand-anims/idle/spiderR.png");
    ssWebIdleL.loadFromFile("art/player/wand-anims/idle/spiderL.png");
    ssStoneIdleL.loadFromFile("art/player/wand-anims/idle/hammerIdleL.png");
    ssStoneIdleL.loadFromFile("art/player/wand-anims/idle/hammerIdleR.png");

    idleR.setSpriteSheet(spritesheetIdleR);
    idleL.setSpriteSheet(spritesheetIdleL);
    fireIdleL.setSpriteSheet(ssFireIdleL);
    fireIdleR.setSpriteSheet(ssFireIdleR);
    webIdleL.setSpriteSheet(ssWebIdleL);
    webIdleR.setSpriteSheet(ssWebIdleR);
    stoneIdleL.setSpriteSheet(ssStoneIdleL);
    stoneIdleR.setSpriteSheet(ssStoneIdleR);

    //Setup the anims
    loadIdle();

    sprite.setAnimation(idleR);

    sprite.setFrameTime(sf::seconds(0.1f));

    sprite.setLooped(true);
  };
  void facesRight(bool s)
  {
    if(s == faceRight)
      return;
    faceRight = s;
    onDirChange();
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

  void setFire()
  {

  }
  void setWeb()
  {

  }
  void setStone()
  {

  }
  void setNone()
  {

  }
private:
  direction dir;
  AnimatedSprite sprite;
  Animation walkR, walkL, idleL, idleR, fireIdleL, fireIdleR, webIdleR, webIdleL, stoneIdleR, stoneIdleL;
  Animation actionNoneL, actionNoneR, actionFireL, actionFireR, actionWebR, actionWebL, actionStoneL, actionStoneR;
  sf::Texture spritesheetIdleL, spritesheetIdleR, ssFireIdleR, ssFireIdleL, ssWebIdleR, ssWebIdleL, ssStoneIdleR, ssStoneIdleL;
  sf::Texture ssActionNoneL, ssActionNoneR, ssActionFireL, ssActionFireR, ssActionWebL, ssActionWebR, ssActionStoneR, ssActionStoneL;
  bool faceRight, inJump;
  currentPower powerState;

  void onDirChange()
  {
    if(faceRight == true)
      dir = right;
    else
      dir = left;
    if(dir == left)
    {
      switch (powerState) {
        case none:
          sprite.setAnimation(idleL);
        break;
        case fire:
        break;
        case web:
        break;
        case stone:
        break;
      }
    }
    else if(dir == right)
    {
      switch (powerState) {
        case none:
          sprite.setAnimation(idleR);
        break;
        case fire:
        break;
        case web:
        break;
        case stone:
        break;
      }
    }
  }

  void loadIdle()
  {
    idleR.addFrame(sf::IntRect(0, 27, 33, 100));
    idleR.addFrame(sf::IntRect(37, 27, 33, 100));
    idleR.addFrame(sf::IntRect(71, 27, 33, 100));
    idleR.addFrame(sf::IntRect(106, 27, 33, 100));
    idleR.addFrame(sf::IntRect(139, 27, 33, 100));
    idleR.addFrame(sf::IntRect(174, 27, 33, 100));
    idleR.addFrame(sf::IntRect(207, 27, 33, 100));
    idleR.addFrame(sf::IntRect(241, 27, 33, 100));

    idleL.addFrame(sf::IntRect(14, 27, 33, 100));
    idleL.addFrame(sf::IntRect(48, 27, 33, 100));
    idleL.addFrame(sf::IntRect(81, 27, 33, 100));
    idleL.addFrame(sf::IntRect(115, 27, 33, 100));
    idleL.addFrame(sf::IntRect(149, 27, 33, 100));
    idleL.addFrame(sf::IntRect(183, 27, 33, 100));
    idleL.addFrame(sf::IntRect(218, 27, 33, 100));
    idleL.addFrame(sf::IntRect(254, 27, 33, 100));
  }

  void loadFire()
  {

  }
};
