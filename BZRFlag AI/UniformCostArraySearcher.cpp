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

UniformCostArraySearcher::UniformCostArraySearcher(const UniformCostArraySearcher& orig)
{
}

UniformCostArraySearcher::~UniformCostArraySearcher()
{
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
    printer->insertClearGraph();
    while(parent != NULL){
        int x1 = parent->x;
        int y1 = parent->y;
        int x2 = tempNode->x;
        int y2 = tempNode->y;
        
        printer->insertLine(x1, y1, x2, y2, true);
        
        Point pathPoint(x2, y2); 
        path.push_back(pathPoint);
        tempNode = parent;
        parent = parent->parent;
    }
    
    printer->insertSquare(targetX, targetY);
    printer->outputToFile("UCSearch");
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
    // left side
    if(x>0){
        if(y>0){
            // check lower-left
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
                
                printer->insertLine(x, y, x-1, y-1, true);
                grid[(y-1)*width + (x-1)] = 1;
                
                pathOptions.push(child);
            }
        }
        
        if(y<height-1){
            // check upper-left
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
                
                printer->insertLine(x, y, x-1, y+1, true);
                grid[(y+1)*width + (x-1)] = 1;
                
                pathOptions.push(child);
            }
        }
        // check left
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
                
                printer->insertLine(x, y, x-1, y, true);
                grid[(y)*width + (x-1)] = 1;
                
                pathOptions.push(child);
            }
        
        
    }
    
    // right
    if(x<width-1){
        if(y>0){
            // check lower-right
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
                
                printer->insertLine(x, y, x+1, y-1, true);
                grid[(y-1)*width + (x+1)] = 1;
                
                pathOptions.push(child);
            }
        }
        
        if(y<height-1){
            // check upper-right
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
                
                printer->insertLine(x, y, x+1, y+1, true);
                grid[(y+1)*width + (x+1)] = 1;
                
                pathOptions.push(child);
            }
        }
        
        // check right
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
                
                printer->insertLine(x, y, x+1, y, true);
                grid[(y)*width + (x+1)] = 1;
                
                pathOptions.push(child);
            }

    }
    
    // middle
    if(y>0){
        // check down
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
                
                printer->insertLine(x, y, x, y-1, true);
                grid[(y-1)*width + (x)] = 1;
                
                pathOptions.push(child);
            }
    }
    
    if(y<height-1){
        // check up
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
                
                printer->insertLine(x, y, x, y+1, true);
                grid[(y+1)*width + (x)] = 1;
                
                pathOptions.push(child);
            }
    }
    
    printCounter++;
    if(printCounter > 1000){
        printCounter = 0;
        printer->insertPause(.000001);
    }
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
