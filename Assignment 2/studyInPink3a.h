/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2022
* Author: Vu Van Tien
* Date: 15.02.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

class Point {
private:
    int x;
    int y;
public:
    Point(int x=0, int y=0)
    {
        this -> x = x;
        this -> y = y;
    }
    string toString() const
    {
        string x = to_string(this -> x);
        string y = to_string(this -> y);
        string s = "<Point[" + x + "," + y + "]>";
        return s;
    }

    int distanceTo(const Point & otherPoint) const
    {
        int d = ceil(sqrt(pow(x - otherPoint.x, 2) + pow(y - otherPoint.y, 2)));
        return d;
    }
};

class Node {
private:
    Point point;
    Node * next;

    friend class Path;

public:
    Node(const Point & point=Point(), Node * next=NULL)
    {
        this -> point = point;
        this -> next = next;
    }
    string toString() const
    {
        return "<Node[" + point.toString() + "]>";
    }
};

class Path {
private:
    Node * head;
    Node * tail;
    int count;
    int length;

public:
    Path() 
    {
        head = tail;
        count = 0;
        length = -1;
    }
    ~Path() 
    {
        delete head;
        delete tail;
    }
    int getLength()
    {
        int dai;
        dai = length;
        return dai;
    }
    void addPoint(int x, int y)
    {
        Node* ins = new Node;
        ins -> point = Point(x,y);
        count++;
        if (count == 1) 
        {
            length = 0;
            tail = ins;
            head = ins;
        }
        else 
        {
            ins -> next = tail -> next;
            tail -> next = ins;
            length += (tail -> point).distanceTo(ins -> point);
            tail = ins;
        }
    }
    string toString() const
    {
        string s = "";
        Node* ins = head;
        for (int i = 0; i < count; i++)
        {
            if (i == 0) s += ins -> toString();
            else s += "," + ins -> toString();
            ins = ins -> next;
        }
        
        return "<Path[count:" + to_string(count) + ",length:" + to_string(length) + ",[" + s + "]]>";
    }
    Point getLastPoint() const
    {
        return tail -> point;
    }
};

class Character {
private:
    string name;
    Path * path;

public:
    Character(const string & name = "")
    {
        this -> name = name;
        path = new Path;
    }
    Path* getPath()
    {
        Path* list = path;
        return list;
    }
    ~Character()
    {    }

    string getName() const
    {
        return name;
    }
    void setName(const string & name)
    {
        this -> name = name;
    }

    void moveToPoint(int x, int y)
    {
        path -> addPoint(x,y);
    }
    string toString() const
    {
        return "<Character[name:" + name + ",path:" + path -> toString() + "]>";
    }
};

bool rescueSherlock(
        const Character & chMurderer,
        const Character & chWatson,
        int maxLength,
        int maxDistance,
        int & outDistance
        ) 
{
    Character mur = chMurderer;
    Character wat = chWatson;
    if ((wat.getPath()) -> getLength() - (mur.getPath()) -> getLength() <= maxLength) 
    {
        outDistance = ((wat.getPath()) -> getLastPoint()).distanceTo((mur.getPath()) -> getLastPoint());
        if (outDistance <= maxDistance) return true;
        else return false;
    }
    else 
    {
        outDistance = -1;
        return false;
    }
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */