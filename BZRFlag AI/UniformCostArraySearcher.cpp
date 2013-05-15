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
    aStar = false;
    penaltyMode = false;
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
    aStar = cost;
    penaltyMode = penalty;
    
    grid = new bool[width*height];
    for(int i = 0; i < width*height; i++)
        grid[i] = occgrid[i];
    
    node_uc* tempNode = newNode(0.0, startPosition.x, startPosition.y, NULL);
    int tempX = targetPosition.x;
    int tempY = targetPosition.y;
    
    pathOptions.push(tempNode);
    tree = tempNode;
    
    while(!(pathOptions.empty())){
        tempNode = pathOptions.top();
        pathOptions.pop();
        
        if(tempNode->x == tempX && tempNode->y == tempY)
            break;
        
        grid[tempNode->y*width + tempNode->x] = 1;
        addchildren(tempNode);
        
    }
    
    if(tempNode->x != tempX && tempNode->y != tempY)
        return false;
    
    while(tempNode->parent != NULL){
        Point pathPoint(tempNode->x, tempNode->y); 
        path.push_back(pathPoint);
        tempNode = tempNode->parent;
    }
    
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
    
    if(aStar && penaltyMode)
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
    int x = parent->x;
    int y = parent->y;
    double amount = parent->cost;
    node_uc* child;
    // left side
    if(x>0){
        if(y>0){
            // check lower-left
            if(grid[(y-1)*width + (x-1)] == false){
                child = newNode(amount + 1.0, x-1, y-1, parent);
                
                pathOptions.push(child);
            }
        }
        
        // check left
        if(grid[(y)*width + (x-1)] == false){
                child = newNode(amount + 1.0, x-1, y, parent);
                
                pathOptions.push(child);
            }
        
        if(y<height-1){
            // check upper-left
            if(grid[(y+1)*width + (x-1)] == false){
                child = newNode(amount + 1.0, x-1, y+1, parent);
                
                pathOptions.push(child);
            }
        }
    }
    
    // middle
    if(y>0){
        // check down
        if(grid[(y-1)*width + (x)] == false){
                child = newNode(amount + 1.0, x, y-1, parent);
                
                pathOptions.push(child);
            }
    }
    
    if(y<height-1){
        // check up
        if(grid[(y+1)*width + (x)] == false){
                child = newNode(amount + 1.0, x, y+1, parent);
                
                pathOptions.push(child);
            }
    }
    
    // right
    if(x<width-1){
        if(y<0){
            // check lower-right
            if(grid[(y-1)*width + (x+1)] == false){
                child = newNode(amount + 1.0, x+1, y-1, parent);
                
                pathOptions.push(child);
            }
        }
        
        // check right
        if(grid[(y)*width + (x+1)] == false){
                child = newNode(amount + 1.0, x+1, y, parent);
                
                pathOptions.push(child);
            }
        
        if(y>height-1){
            // check upper-right
            if(grid[(y+1)*width + (x+1)] == false){
                child = newNode(amount + 1.0, x+1, y+1, parent);
                
                pathOptions.push(child);
            }
        }
    }
    
}
