#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "math.h"
using namespace std;
class point{
    public:
    point(int x, int y, int id){
        _x = x;
        _y = y;
        _id = id;
    }

    int getX(){
        return _x;
    }

    int getY(){
        return _y;
    }

    int getID(){
        return _id;
    }

    void setFlag(){
        _visited = true;
    }

    bool getFlag(){
        return _visited;
    }

    private:    
    int _x = 0;
    int _y = 0;
    int _id = 0;
    bool _visited = false;
};

static vector<point> pts;
static float traveledDistance = 0;


void ReadFile(){
        ifstream input_file("input.txt");
        if(!input_file.is_open()){
            cout << "The file is not existed. Please check the input file name." << endl;
            exit(0);
        } else {
            int num;
            input_file >> num;
            for(int i = 0; i < num; i++){
                int x;
                input_file >> x;
                int y;
                input_file >> y;
                point p(x,y,i);
                pts.push_back(p);
            }

        }
        input_file.close();
}

float CalcDist(point &ptr1, point &ptr2){
    int x1 = ptr1.getX();
    int y1 = ptr1.getY();
    int x2 = ptr2.getX();
    int y2 = ptr2.getY();

    float xDist = (x1 - x2)*(x1 - x2);
    float yDist = (y1 - y2)*(y1 - y2);
    float distance = sqrt(xDist+yDist);
    return distance;
}

point SelectPoint(point &ptr){
    int id = ptr.getID();
    int selectedID = 0;
    float distance = 99999999;
    for(int i = 0; i < pts.size(); i++){
        float temp = 0;
        if(pts.at(i).getFlag() == false && i != id){
            temp = CalcDist(ptr,pts.at(i));
            if(temp < distance){
                distance = temp;
                selectedID = i;
            }
        }
    }
    traveledDistance += distance;

    return pts[selectedID];
}

bool unvisitedPoint(){
    for(int i  = 0; i < pts.size(); i++){
        if(pts[i].getFlag() == false){
            return true;
        }
    }
    return false;
}

int main(int argc, char* argv[]){
    ReadFile();
    /*
    cout << "The input points are: " << endl;
    for(int i = 0; i < pts.size(); i++){
        int x = pts.at(i).getX();
        int y = pts.at(i).getY();
        int id = pts.at(i).getID();
        cout << "Position: " << x << " " << y << " ID: " << id << endl;
    }
    cout << endl;
    */
    clock_t initT;
    initT = clock();
    
    cout << "Processing ============================ " << endl;
    point currentPoint = pts[0];
    pts[0].setFlag();
    vector<point> route;
    route.push_back(pts[0]);
    int secondLastID = 0;
    while(unvisitedPoint() == true){
        currentPoint = SelectPoint(currentPoint);
        pts[currentPoint.getID()].setFlag();
        route.push_back(currentPoint);
        secondLastID = currentPoint.getID();
        //cout << "Traveled Distance is: " << traveledDistance << endl;
    }
    traveledDistance += CalcDist(pts[secondLastID],pts[0]);
    route.push_back(pts[0]);
    cout << endl;
    clock_t t = clock() - initT;
    double time = (double)t/CLOCKS_PER_SEC;
    cout << endl;


    cout << "Results ============================ " << endl;
    cout << "The route is: ";
    for(int i = 0; i < route.size(); i++){
        int id = route.at(i).getID();
        cout << id << " ";
    }
    cout << endl;
    cout << "Traveled Distance is: " << traveledDistance << endl;
    cout << endl;
    cout << "The running time is: " << time << "s" << endl;
}