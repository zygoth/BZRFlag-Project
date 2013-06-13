/* 
 * File:   UniformCostArraySearcher.cpp
 * Author: zygoth
 * 
 * Created on May 13, 2013, 4:23 PM
 */

#include "UniformCostArraySearcher.h"
#include "Point.h"

UniformCostArraySearcher::UniformCostArraySearcher()
{
    tree = NULL;
    grid = NULL;
    objectGrid = NULL;
    width = 0; 
    height = 0;
    targetX = 0;
    targetY = 0;
    printCounter = 0;
    aStar = false;
    penaltyMode = false;
    printer = new GNUPrinter();
}

UniformCostArraySearcher::UniformCostArraySearcher(bool* world, int cols, int rows)
{
    tree = NULL;
    grid = new bool[cols * rows];
    objectGrid = world;
    

    width = cols;
    height = rows;
    targetX = -1;
    targetY = -1;
    aStar = true;
    penaltyMode = true;
}

UniformCostArraySearcher::UniformCostArraySearcher(const UniformCostArraySearcher& orig)
{
}

UniformCostArraySearcher::~UniformCostArraySearcher()
{
    delete objectGrid;
    delete grid;
    delete printer;
}

// returns true when the target point is found and nextTarget is given the value of a point on the path
// returns false if no path is found or the target point is inside of an object
//     When false nextTarget is not updated
bool UniformCostArraySearcher::search(Point startPosition, Point targetPosition,
                                      Point* nextTarget, int distance)
{
    printer = new GNUPrinter();
    
    targetX = targetPosition.x + width/2;
    targetY = targetPosition.y + height/2;
    
    for(int i = 0; i < width*height; i++)
        grid[i] = objectGrid[i];
    
    if(grid[targetY*width + targetX] == 1)
        return false;
    
    int tempX = startPosition.x + width/2;
    int tempY = startPosition.y + height/2;
    
    node_uc* tempNode;
    tempNode = newNode(0.0 + getDistance(tempX,tempY), 
                       tempX, tempY, NULL);
    tempNode->pathCost = 0.0;
    
    grid[tempNode->y*width + tempNode->x] = 1;
    pathOptions.push(tempNode);
    tree = tempNode;
    
    while(!(pathOptions.empty())){
        tempNode = pathOptions.top();
        pathOptions.pop();
        
        if(tempNode->x == targetX && tempNode->y == targetY)
            break;
        
        addchildren(tempNode);
        
    }
    
    if(tempNode->x != targetX && tempNode->y != targetY)
        return false;
    
    vector<Point> path;
    node_uc* parent = tempNode->parent;
    
    while(parent != NULL){
        int x = tempNode->x;
        int y = tempNode->y;
        
        printer->insertSquare(x,y);
        Point pathPoint(x, y); 
        path.push_back(pathPoint);
        tempNode = parent;
        parent = parent->parent;
    }
    printer->outputToFile("BEHAVIOR_PATH");
    
    Point check = path.back();
    while(path.empty() == false && distance > 0)
    {
        path.pop_back();
        check = path.back();
        distance--;
    }
    
    nextTarget->x = check.x - width/2;
    nextTarget->y = check.y - height/2;
    
    path.clear();
    clearNode(tree);
    delete printer;
    
    return true;
}

// returns true when target point is found and nextTarget is given the value of a point on the path
// returns false if no path is found and nextTarget is given the value of a the targetPosition
bool UniformCostArraySearcher::search(settledGrid_t map, Point startPosition, Point targetPosition,
                                      Point* nextTarget)

{
    int nextPointRange = 30;
    delete printer;
    printer = new GNUPrinter();
    printCounter = 0;
            
    tree = NULL;
    width = map.width;
    height = map.height;
    targetX = targetPosition.x;
    targetY = targetPosition.y;
    aStar = true;
    penaltyMode = true;
            
    int temp = width*height;
    objectGrid = new bool[temp];
    grid = new bool[temp];
    for(int x = 0; x < width ; x++)
    {
        for(int y = 0; y < height; y++)
        {
            if(map.grid[x][y] > .99)
            {
                grid[y*width + x] = true;
                objectGrid[y*width + x] = true;
            }
            else
            {
                grid[y*width + x] = false;
                objectGrid[y*width + x] = false;
            }
            
        }
    }
    
    int tempX = startPosition.x;
    int tempY = startPosition.y;
    
    node_uc* tempNode;
    if(aStar){
        tempNode = newNode(0.0 + getDistance(tempX,tempY), 
                        tempX, tempY, NULL);
        tempNode->pathCost = 0.0;
    }
    else
        tempNode = newNode(0.0, tempX, tempY, NULL);
    
    grid[tempNode->y*width + tempNode->x] = 1;
    pathOptions.push(tempNode);
    tree = tempNode;
    
    while(!(pathOptions.empty())){
        tempNode = pathOptions.top();
        pathOptions.pop();
        
        if(tempNode->x == targetX && tempNode->y == targetY)
            break;
        
        addchildren(tempNode);
        
    }
    
    if(tempNode->x != targetX && tempNode->y != targetY){
        nextTarget->x = targetX;
        nextTarget->x = targetY;
        return false;
    }
    
    vector<Point> path;
    node_uc* parent = tempNode->parent;
    
    while(parent != NULL){
        int x = tempNode->x;
        int y = tempNode->y;
        
        Point pathPoint(x, y); 
        path.push_back(pathPoint);
        tempNode = parent;
        parent = parent->parent;
    }
    
    Point check = path.back();
    while(path.empty() == false && nextPointRange > 0)
    {
        path.pop_back();
        check = path.back();
        nextPointRange--;
    }
    
    nextTarget->x = check.x;
    nextTarget->y = check.y;
    
    path.clear();
    clearNode(tree);
    delete objectGrid;
    delete grid;
    
    return true;
}

void UniformCostArraySearcher::clearNode(node_uc* node)
{
    for(int i = 0; i < node->childrenNum; i++)
        clearNode(node->children[i]);
    delete node;
}

bool UniformCostArraySearcher::search(bool* occgrid, int gridWidth, int gridHeight,
                                     Point startPosition, Point targetPosition,
                                     vector<Point>& path, bool cost, bool penalty)
{
    objectGrid = occgrid;
    width = gridWidth;
    height = gridHeight;
    targetX = targetPosition.x;
    targetY = targetPosition.y;
    aStar = cost;
    penaltyMode = penalty;
    
    grid = new bool[width*height];
    for(int i = 0; i < width*height; i++)
        grid[i] = occgrid[i];
    
    int tempX = startPosition.x;
    int tempY = startPosition.y;
    
    node_uc* tempNode;
    if(aStar){
        tempNode = newNode(0.0 + getDistance(tempX,tempY), 
                        tempX, tempY, NULL);
        tempNode->pathCost = 0.0;
    }
    else
        tempNode = newNode(0.0, tempX, tempY, NULL);
    
    
    grid[tempNode->y*width + tempNode->x] = 1;
    pathOptions.push(tempNode);
    tree = tempNode;
    
    while(!(pathOptions.empty())){
        tempNode = pathOptions.top();
        pathOptions.pop();
        
        if(tempNode->x == targetX && tempNode->y == targetY)
            break;
        
        addchildren(tempNode);
        
    }
    
    if(tempNode->x != targetX && tempNode->y != targetY){
        printer->outputToFile("UCSearch");
        return false;
    }
    
    node_uc* parent = tempNode->parent;
    printer->outputToFile("UCSearch");
    printer = new GNUPrinter();
    
    cout << "Cost of Path: " << tempNode->cost << endl;
    int pathLength = 0;
    
    while(parent != NULL){
        int x1 = parent->x;
        int y1 = parent->y;
        int x2 = tempNode->x;
        int y2 = tempNode->y;
        
        printer->insertLine(x1, y1, x2, y2, true);
        printer->insertPause(0.0001);
        
        Point pathPoint(x2, y2); 
        path.push_back(pathPoint);
        tempNode = parent;
        parent = parent->parent;
        pathLength++;
    }
    
    cout << "Number of Nodes: " << pathLength << endl;
    cout << endl;
    printer->insertSquare(targetX, targetY);
    printer->outputToFile("UCResult");
    return true;
}

node_uc* UniformCostArraySearcher::newNode(double cost,int x,int y, node_uc* parent)
{
    node_uc* tempNode = new node_uc;
  
    tempNode->childrenNum = 0;
    tempNode->cost = cost;
    tempNode->parent = parent;
    tempNode->x = x;
    tempNode->y = y;
    
    for(int i = 0; i < 8; i++)
        tempNode->children[i] = NULL;
    
    if(penaltyMode)
        tempNode->nextTo = isNextToObject(x,y);
    else
        tempNode->nextTo = false;
    
    return tempNode;
}

bool UniformCostArraySearcher::isNextToObject(int x,int y)
{
    // left side
    if(x>0){
        if(y>0){
            // check lower-left
            if(objectGrid[(y-1)*width + (x-1)] == true)
                return true;
        }
        
        // check left
        if(objectGrid[(y)*width + (x-1)] == true)
            return true;
        
        if(y<height-1){
            // check upper-left
            if(objectGrid[(y+1)*width + (x-1)] == true)
                return true;
        }
    }
    
    // middle
    if(y>0){
        // check down
        if(objectGrid[(y-1)*width + (x)] == true)
            return true;
    }
    
    if(y<height-1){
        // check up
        if(objectGrid[(y+1)*width + (x)] == true)
            return true;
    }
    
    // right
    if(x<width-1){
        if(y<0){
            // check lower-right
            if(objectGrid[(y-1)*width + (x+1)] == true)
                return true;
        }
        
        // check right
        if(objectGrid[(y)*width + (x+1)] == true)
            return true;
        
        if(y>height-1){
            // check upper-right
            if(objectGrid[(y+1)*width + (x+1)] == true)
                return true;
        }
    }
    
    return false;
}

void UniformCostArraySearcher::addChild(node_uc* parent, node_uc* child)
{
    parent->children[parent->childrenNum] = child;
    parent->childrenNum++;
}

void UniformCostArraySearcher::addchildren(node_uc* parent)
{
    double amount;
    double currentCost;
    int x = parent->x;
    int y = parent->y;
    if(aStar)
        amount = parent->pathCost;
    else
        amount = parent->cost;
    node_uc* child;
    
    // check left
    if(x>0){
        if(grid[(y)*width + (x-1)] == false){
                if(penaltyMode){
                    currentCost = amount + 1.0 
                                * getPenalty(parent, x-1, y);
                }
                else
                    currentCost = amount + 1.0;
                
                if(aStar){
                    child = newNode(currentCost + getDistance(x-1, y), 
                                    x-1, y, parent);
                    child->pathCost = currentCost;
                }
                else
                    child = newNode(currentCost, x-1, y, parent);
                
                //printer->insertLine(x, y, x-1, y, true);
                grid[(y)*width + (x-1)] = 1;
                
                addChild(parent, child);
                pathOptions.push(child);
            }
    }
    
    // check right
    if(x<width-1){
        if(grid[(y)*width + (x+1)] == false){
                if(penaltyMode){
                    currentCost = amount + 1.0 
                                * getPenalty(parent, x+1, y);
                }
                else
                    currentCost = amount + 1.0;
                
                if(aStar){
                    child = newNode(currentCost + getDistance(x+1, y), 
                                    x+1, y, parent);
                    child->pathCost = currentCost;
                }
                else
                    child = newNode(currentCost, x+1, y, parent);
                
                //printer->insertLine(x, y, x+1, y, true);
                grid[(y)*width + (x+1)] = 1;
                
                addChild(parent, child);
                pathOptions.push(child);
            }
    }
    
    // check up
    if(y<height-1){
        if(grid[(y+1)*width + (x)] == false){
                if(penaltyMode){
                    currentCost = amount + 1.0 
                                * getPenalty(parent, x, y+1);
                }
                else
                    currentCost = amount + 1.0;
                
                if(aStar){
                    child = newNode(currentCost + getDistance(x, y+1), 
                                    x, y+1, parent);
                    child->pathCost = currentCost;
                }
                else
                    child = newNode(currentCost, x, y+1, parent);
                
                //printer->insertLine(x, y, x, y+1, true);
                grid[(y+1)*width + (x)] = 1;
                
                addChild(parent, child);
                pathOptions.push(child);
            }
    }
    
    // check down
    if(y>0){
        if(grid[(y-1)*width + (x)] == false){
                if(penaltyMode){
                    currentCost = amount + 1.0 
                                * getPenalty(parent, x, y-1);
                }
                else
                    currentCost = amount + 1.0;
                
                if(aStar){
                    child = newNode(currentCost + getDistance(x, y-1), 
                                    x, y-1, parent);
                    child->pathCost = currentCost;
                }
                else
                    child = newNode(currentCost, x, y-1, parent);
                
                //printer->insertLine(x, y, x, y-1, true);
                grid[(y-1)*width + (x)] = 1;
                
                addChild(parent, child);
                pathOptions.push(child);
            }
    }
    
    // check upper-left
    if(x>0){
        if(y<height-1){
            if(grid[(y+1)*width + (x-1)] == false){
                if(penaltyMode){
                    currentCost = amount + 1.41421 
                                * getPenalty(parent, x-1, y+1);
                }
                else
                    currentCost = amount + 1.41421;
                
                if(aStar){
                    child = newNode(currentCost + getDistance(x-1, y+1), 
                                    x-1, y+1, parent);
                    child->pathCost = currentCost;
                }
                else
                    child = newNode(currentCost, x-1, y+1, parent);
                
                //printer->insertLine(x, y, x-1, y+1, true);
                grid[(y+1)*width + (x-1)] = 1;
                
                addChild(parent, child);
                pathOptions.push(child);
            }
        }
    }
    
    // check upper-right
    if(x<width-1){
        if(y<height-1){
            if(grid[(y+1)*width + (x+1)] == false){
                if(penaltyMode){
                    currentCost = amount + 1.41421 
                                * getPenalty(parent, x+1, y+1);
                }
                else
                    currentCost = amount + 1.41421;
                
                if(aStar){
                    child = newNode(currentCost + getDistance(x+1, y+1), 
                                    x+1, y+1, parent);
                    child->pathCost = currentCost;
                }
                else
                    child = newNode(currentCost, x+1, y+1, parent);
                
                //printer->insertLine(x, y, x+1, y+1, true);
                grid[(y+1)*width + (x+1)] = 1;
                
                addChild(parent, child);
                pathOptions.push(child);
            }
        }
    }
    
     // check lower-left
    if(x>0){
        if(y>0){
            if(grid[(y-1)*width + (x-1)] == false){
                if(penaltyMode){
                    currentCost = amount + 1.41421 
                                * getPenalty(parent, x-1, y-1);
                }
                else
                    currentCost = amount + 1.41421;
                
                if(aStar){
                    child = newNode(currentCost + getDistance(x-1, y-1), 
                                    x-1, y-1, parent);
                    child->pathCost = currentCost;
                }
                else
                    child = newNode(currentCost, x-1, y-1, parent);
                
                //printer->insertLine(x, y, x-1, y-1, true);
                grid[(y-1)*width + (x-1)] = 1;
                
                addChild(parent, child);
                pathOptions.push(child);
            }
        }
    }
    
    // check lower-right
    if(x<width-1){
        if(y>0){
            if(grid[(y-1)*width + (x+1)] == false){
                currentCost = amount + 1.41421;
                if(penaltyMode){
                    currentCost = amount + 1.41421 
                                * getPenalty(parent, x+1, y-1);
                }
                else
                    currentCost = amount + 1.41421;
                
                if(aStar){
                    child = newNode(currentCost + getDistance(x+1, y-1), 
                                    x+1, y-1, parent);
                    child->pathCost = currentCost;
                }
                else
                    child = newNode(currentCost, x+1, y-1, parent);
                
                //printer->insertLine(x, y, x+1, y-1, true);
                grid[(y-1)*width + (x+1)] = 1;
                
                addChild(parent, child);
                pathOptions.push(child);
            }
        }
    }
    
    
/*    printCounter++;
    if(printCounter > 1000){
        printCounter = 0;
        printer->insertPause(.000001);
    }*/
}

double UniformCostArraySearcher::getPenalty(node_uc* parent, int x, int y)
{
    double result = 1.0;
    bool nextTo, parentNextTo;
    
    nextTo = isNextToObject(x, y);
    parentNextTo = parent->nextTo;
    
    if(nextTo && parentNextTo)
        result = 1.5;
    if(!nextTo && parentNextTo)
        result = 1.1;
    if(nextTo && !parentNextTo)
        result = 1.3;
    
    return result;
}

double UniformCostArraySearcher::getDistance(int x, int y)
{
    return pow((pow(targetX - x, 2) + pow(targetY - y, 2)), 0.5);
}
