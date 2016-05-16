#include "Enemy.hpp"

Book::Book(sf::Vector2f pos)
{
  srand((unsigned)time(0));
  x = pos.x;
  y = pos.y;
  sprite.setPosition(pos);

  spriteSheetL.loadFromFile("art/mobs/books/bookL.png");
  spriteSheetR.loadFromFile("art/mobs/books/bookR.png");

  idleL.setSpriteSheet(spriteSheetL);
  idleR.setSpriteSheet(spriteSheetR);

  idleL.addFrame(sf::IntRect(7, 21, 93, 55));
  idleL.addFrame(sf::IntRect(114, 21, 69, 59));
  idleL.addFrame(sf::IntRect(203, 20, 52, 57));

  idleR.addFrame(sf::IntRect(5, 22, 93, 57));
  idleR.addFrame(sf::IntRect(111, 20, 69, 59));
  idleR.addFrame(sf::IntRect(196, 21, 52, 56));

  sprite.setFrameTime(sf::seconds(0.2f));

  sprite.setAnimation(idleR);

  waypoint = generateNewWaypoint();
  linearInterpolation();
}

void Book::update(sf::Time deltaTime)
{
  if(dir.x > 0 && faceRight == false)
  {
    faceRight = true;
    sprite.setAnimation(idleR);
  }
  if(faceRight == true && dir.x < 0)
  {
    faceRight = false;
    sprite.setAnimation(idleL);
  }
  sprite.update(deltaTime);
  pathfinding();
}

void Book::pathfinding()
{
  if( sprite.getPosition().x >= waypoint.x - 20 &&
      sprite.getPosition().x <= waypoint.x + 20 &&
      sprite.getPosition().y >= waypoint.y - 20 &&
      sprite.getPosition().y <= waypoint.y + 20)
  {
    waypoint = generateNewWaypoint();
    linearInterpolation();
  }
  else
  {
    sprite.move(dir * 0.003f);
  }
}

sf::Vector2f Book::generateNewWaypoint()
{
  return sf::Vector2f(RandomFloat(50, 900), RandomFloat(0, 600));
}

void Book::linearInterpolation()
{
  dir = normalize(waypoint, sprite.getPosition());
}

float Book::RandomFloat(float min, float max)
{
  float r = (float)rand() / (float)RAND_MAX;
  return min + r * (max - min);
}


Pot::Pot(sf::Vector2f pos)
{
  srand((unsigned)time(0));
  x = pos.x;
  y = pos.y;
  sprite.setPosition(pos);

  spriteSheetL.loadFromFile("art/mobs/pots/potL.png");
  spriteSheetR.loadFromFile("art/mobs/pots/potR.png");

  idleL.setSpriteSheet(spriteSheetL);
  idleR.setSpriteSheet(spriteSheetR);

  idleL.addFrame(sf::IntRect(5, 14, 88, 72));
  idleL.addFrame(sf::IntRect(110, 14, 88, 72));
  idleL.addFrame(sf::IntRect(195, 14, 88, 72));
  idleL.addFrame(sf::IntRect(289, 14, 88, 72));

  idleR.addFrame(sf::IntRect(11, 14, 88, 72));
  idleR.addFrame(sf::IntRect(107, 14, 88, 72));
  idleR.addFrame(sf::IntRect(190, 14, 88, 72));
  idleR.addFrame(sf::IntRect(282, 14, 88, 72));

  sprite.setFrameTime(sf::seconds(0.2f));

  sprite.setAnimation(idleR);

  waypoint = generateNewWayPoint();
  linearInterpolation();
}

void Pot::update(sf::Time deltaTime)
{
  if(dir.x > 0 && faceRight == false)
  {
    faceRight = true;
    sprite.setAnimation(idleR);
  }
  if(faceRight == true && dir.x < 0)
  {
    faceRight = false;
    sprite.setAnimation(idleL);
  }
  sprite.update(deltaTime);
  pathfinding();
}

void Pot::pathfinding()
{
  if( sprite.getPosition().x >= waypoint.x - 20 &&
      sprite.getPosition().x <= waypoint.x + 20 )
  {
    waypoint = generateNewWayPoint();
    linearInterpolation();
  }
  else
  {
    sprite.move(dir * 0.003f);
  }
}

sf::Vector2f Pot::generateNewWayPoint()
{
  return sf::Vector2f(RandomFloat(50, 900), RandomFloat(600, 600));
}

void Pot::linearInterpolation()
{
  dir = normalize(waypoint, sprite.getPosition());
}

float Pot::RandomFloat(float min, float max)
{
  float r = (float)rand() / (float)RAND_MAX;
  return min + r * (max - min);
}

Rat::Rat(sf::Vector2f pos)
{
  srand((unsigned)time(0));
  x = pos.x;
  y = pos.y;
  sprite.setPosition(pos);

  spriteSheetL.loadFromFile("art/mobs/rat/ratL.png");
  spriteSheetR.loadFromFile("art/mobs/rat/ratR.png");

  idleL.setSpriteSheet(spriteSheetL);
  idleR.setSpriteSheet(spriteSheetR);

  idleL.addFrame(sf::IntRect(6, 10, 77, 75));
  idleL.addFrame(sf::IntRect(91, 10, 77, 75));
  idleL.addFrame(sf::IntRect(174, 10, 77, 75));
  idleL.addFrame(sf::IntRect(265, 10, 77, 75));

  idleR.addFrame(sf::IntRect(9, 10, 77, 75));
  idleR.addFrame(sf::IntRect(90, 10, 77, 75));
  idleR.addFrame(sf::IntRect(173, 10, 77, 75));
  idleR.addFrame(sf::IntRect(257, 10, 77, 75));

  sprite.setFrameTime(sf::seconds(0.2f));

  sprite.setAnimation(idleR);

  waypoint = generateNewWayPoint();
  linearInterpolation();
}

void Rat::update(sf::Time deltaTime)
{
  if(dir.x > 0 && faceRight == false)
  {
    faceRight = true;
    sprite.setAnimation(idleR);
  }
  if(faceRight == true && dir.x < 0)
  {
    faceRight = false;
    sprite.setAnimation(idleL);
  }
  sprite.update(deltaTime);
  pathfinding();
}

void Rat::pathfinding()
{
  if( sprite.getPosition().x >= waypoint.x - 20 &&
      sprite.getPosition().x <= waypoint.x + 20 )
  {
    waypoint = generateNewWayPoint();
    linearInterpolation();
  }
  else
  {
    sprite.move(dir * 0.003f);
  }
}

sf::Vector2f Rat::generateNewWayPoint()
{
  return sf::Vector2f(RandomFloat(50, 900), RandomFloat(600, 600));
}

void Rat::linearInterpolation()
{
  dir = normalize(waypoint, sprite.getPosition());
}

float Rat::RandomFloat(float min, float max)
{
  float r = (float)rand() / (float)RAND_MAX;
  return min + r * (max - min);
}
