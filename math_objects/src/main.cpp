#include "inc/objects.h"
#include <algorithm>
#include <memory>

int main() {
    std::vector<std::unique_ptr<MathObj>> math_objs;
    
    math_objs.push_back(std::make_unique<Rectangle>(2, 5));
    math_objs.push_back(std::make_unique<Circle>(3));
    math_objs.push_back(std::make_unique<Square>(4));
    math_objs.push_back(std::make_unique<TextureRectangle>("../assets/some_texture.png", 300, 200));

    std::for_each(std::begin(math_objs), std::end(math_objs), [](std::unique_ptr<MathObj>& x){ x->print(); });

    return 0;
}
