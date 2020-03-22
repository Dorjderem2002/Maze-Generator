//
//  Box.hpp
//  mazeGenerator
//
//  Created by Dode Pep on 2/21/20.
//  Copyright © 2020 Dode. All rights reserved.
//

#ifndef Box_hpp
#define Box_hpp

#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;

class Box {
public:
    Box(float x,float y,int w);
    void draw(RenderWindow &app);
    void delSide(int s);
private:
    Vertex line[2];
    Vertex line2[2];
    Vertex line3[2];
    Vertex line4[2];
    Color background = Color(40,40,40);
};

#endif /* Box_hpp */
