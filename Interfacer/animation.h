#ifndef ANIMATION_H
#define ANIMATION_H

#include <string>
#include <map>

class Animation
{
public:
    Animation(int spd, std::string txt, int color =0);
    void Draw(std::map<std::string, std::string> vars);
private:
    std::string text;
    int colour;
    int speed;
};

#endif // ANIMATION_H
