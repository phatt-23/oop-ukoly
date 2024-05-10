#include "inc/objects.h"
#include <memory>

int main() {
    // polymorphic array (vector) of MathObjs => Rectangle, Circle, Square, TextureRectangle
    std::vector<std::shared_ptr<MathObj>> math_objs = {
        std::make_shared<Rectangle>(2, 5),
        std::make_shared<Circle>(3),
        std::make_shared<Square>(4),
        std::make_shared<TextureRectangle>("../assets/some_texture.png", 300, 200),
    };

    for(auto o : math_objs) { 
        o->print(); 
    }

    return 0;
}
