//
//  Box.cpp
//  mazeGenerator
//
//  Created by Dode Pep on 2/21/20.
//  Copyright © 2020 Dode. All rights reserved.
//

#include "Box.hpp"

Box::Box(float x,float y,int w) {
    line[0].position = Vector2f(x,y);
    line[1].position = Vector2f(x+w,y);
    
    line2[0].position = Vector2f(x+w,y);
    line2[1].position = Vector2f(x+w,y+w);
    
    line3[0].position = Vector2f(x+w,y+w);
    line3[1].position = Vector2f(x,y+w);
    
    line4[0].position = Vector2f(x,y+w);
    line4[1].position = Vector2f(x,y);
}

void Box::draw(RenderWindow &app) {
    app.draw(line,2,Lines);
    app.draw(line2,2,Lines);
    app.draw(line3,2,Lines);
    app.draw(line4,2,Lines);
}

void Box::delSide(int s) {
    switch(s) {
        case 1:
            line[0].color = background;
            line[1].color = background;
            break;
        case 2:
            line2[0].color = background;
            line2[1].color = background;
            break;
        case 3:
            line3[0].color = background;
            line3[1].color = background;
            break;
        case 4:
            line4[0].color = background;
            line4[1].color = background;
            break;
    }
}
