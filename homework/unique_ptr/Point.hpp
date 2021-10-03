

class Point {
public:
    Point(int x, int y)
        : x_(x), y_(y) {}

    int getX();
    int getY();
    void setX(int);
    void setY(int);
private:
    int x_;
    int y_;
};