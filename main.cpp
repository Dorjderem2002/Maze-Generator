#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdio>
#include <ctime>
#include <iostream>
#include "Box.hpp"
using namespace sf;

#define WINDOW_SIZE 1000

int main() {
    srand(time(NULL));
    RenderWindow app(VideoMode(1002,1002),"Maze");
    app.setFramerateLimit(30);
    std::vector<Box> boxes;
    
    bool finished = false;
    
    int w = 10;
    int n = WINDOW_SIZE / w;
    
    std::vector<int> moves;
    
    RectangleShape start,end;
    start.setSize(Vector2f(w,w));
    end = start;
    start.setFillColor(Color::Red);
    end.setFillColor(Color::Green);
    start.setPosition(0, 0);
    
    bool map[10000] = {0};
    for(int y=0;y<n;y++) {
        for(int x=0;x<n;x++) {
            Box box(x*w+1,y*w+2,w);
            boxes.push_back(box);
        }
    }
    int step = 1;
    int startPos = 0,current=1;
    map[0] = 1;
    moves.push_back(0);
    
    while (app.isOpen()) {
        Event e;
        while (app.pollEvent(e)) {
            if(e.type == Event::Closed) {
                app.close();
            }
            if(e.type == Event::KeyPressed) {
                if(e.key.code == Keyboard::Space) {
                    current = 1;
                    finished = false;
                    for(int i=0;i<10000;i++) {
                        map[i]= 0;
                    }
                    boxes.clear();
                    for(int y=0;y<n;y++) {
                        for(int x=0;x<n;x++) {
                            Box box(x*w+1,y*w+2,w);
                            boxes.push_back(box);
                        }
                    }
                    moves.clear();
                    startPos = 0;
                    map[0] = 1;
                    moves.push_back(0);
                }
                if(e.key.code == Keyboard::Up) {
                    step += 5;
                    step = std::min(100,step);
                }
                if(e.key.code == Keyboard::Down) {
                    step -= 5;
                    step = std::max(1,step);
                }
            }
        }
        
        for(int b=0;b<step;b++) {
            if(current == 0) {
                finished = true;
                
            }
            
            if(!finished) {
                
                int rMove = rand()%4;
                int checker = 0;
                if(map[startPos + n] == 1 || startPos + n >= n * n ) {
                    checker++;
                }
                if(map[startPos - n] == 1 || startPos - n < 0) {
                    checker++;
                }
                if(map[startPos + 1] == 1 || (startPos + 1) % n == 0) {
                    checker++;
                }
                if(map[startPos - 1] == 1 || startPos % n == 0) {
                    checker++;
                }
                
                if(checker == 4) {
                    startPos = moves[current-1];
                    moves.pop_back();
                    current--;
                }
                
                if(startPos % n != 0 && map[startPos - 1] != 1 && startPos != 0 && rMove == 3) {
                    boxes[startPos-1].delSide(2);
                    boxes[startPos].delSide(4);
                    
                    map[startPos - 1] = 1;
                    startPos -= 1;
                    moves.push_back(startPos);
                    current++;
                }
                else {
                    rMove = rand() % 3;
                }
                if(startPos + n < n*n && map[startPos + n] != 1 && rMove == 2) {
                    boxes[startPos + n].delSide(1);
                    boxes[startPos].delSide(3);
                    
                    map[startPos + n] = 1;
                    startPos += n;
                    moves.push_back(startPos);
                    current++;
                }
                else {
                    rMove = rand() % 2;
                }
                if((startPos + 1) % n != 0 && map[startPos + 1] != 1 && rMove == 1) {
                    boxes[startPos+1].delSide(4);
                    boxes[startPos].delSide(2);
                    
                    map[startPos + 1] = 1;
                    startPos += 1;
                    moves.push_back(startPos);
                    current++;
                }
                else {
                    rMove = 0;
                }
                if(startPos - n >= 0 && map[startPos - n] != 1 && rMove == 0) {
                    boxes[startPos - n].delSide(3);
                    boxes[startPos].delSide(1);
                    
                    map[startPos - n] = 1;
                    startPos -= n;
                    moves.push_back(startPos);
                    current++;
                }
            }
            end.setPosition(startPos % n * w,startPos / n * w);
        }
        if(finished) {
            end.setPosition(1000-w, 1000-w);
        }
        app.clear(Color(40,40,40));
        for(Box box : boxes) {
            box.draw(app);
        }
        app.draw(start);
        app.draw(end);
        app.display();
    }
    return 0;
}

