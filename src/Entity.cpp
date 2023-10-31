#ifndef ENTITY
#define ENTITY
class Entity {
private:
    float x, y; // Posizione dell'entità

    int hp; // Quantità di HP 
    int exp; // Esperienza
public:
    Entity(float startX, float startY) : x(startX), y(startY) {}

    float getX() const { return x; }
    float getY() const { return y; }

    void updatePosition(float deltaX, float deltaY) {
        x += deltaX;
        y += deltaY;
    }
};
#endif