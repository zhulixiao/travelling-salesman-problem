/**
 * The updated version of the exhaustive algorithm is to 
 * store some intermediate calculation to save time.
 * 
 **/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include "math.h"
using namespace std;

// Basic Data structure for a point
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

// A basic data structure to store given points
static vector<point> pts;
// A 2D vector to store distance calculation between different points
static vector<vector<float>> distance_pts;
// A map to store distance calculation between different routes
static map<int,float> distance_map;
// Number of given pts
static int num_pts = -1;

void ReadFile(string file_name){
        ifstream input_file(file_name);
        if(!input_file.is_open()){
            cout << "The file is not existed. Please check the input file name." << endl;
            exit(0);
        } else {
            int num;
            input_file >> num;
            num_pts = num;
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
    int x2 = ptr2.getX();
    int y1 = ptr1.getY();
    int y2 = ptr2.getY();

    float xDist = (x1 - x2)*(x1 - x2);
    float yDist = (y1 - y2)*(y1 - y2);
    float distance = sqrt(xDist+yDist);
    return distance;
}

void StoreDist(){

    // Initialize the 2d vector
    for(int i = 0; i < num_pts; i++){
        vector<float> temp_vec;
        for(int j = 0; j < num_pts; j++){
            temp_vec.push_back(0);
        }
        distance_pts.push_back(temp_vec);
    }

    for(int i = 0; i < (int)distance_pts.size(); i++){
        for(int j = 0; j < (int)distance_pts.size(); j++){
            // Same point
            if(i == j) continue;
            // Already know
            if(distance_pts.at(i).at(j) != 0) continue;

            float temp_dis = CalcDist(pts[i],pts[j]);
            distance_pts.at(i).at(j) = distance_pts.at(j).at(i) = temp_dis;
        }
    }

// Uncomment the next block of code to check if the stored value are correct.
/*
    for(int i = 0; i < (int)distance_pts.size(); i++){
        for(int j = 0; j < (int)distance_pts.size(); j++){
            cout << distance_pts.at(i).at(j) << " ";
        }
        cout << endl;
    }
*/
}




float traveledDistance(vector<int> &route) {
    float distance = 0;

    // Check if the same route is calculated
    for(int i = (route.size() - 4); i > 1; i--){
        int temp_route;
        for(int j = 0; i < )

    }

    
    for(int i = 0; i < (route.size() - 1); i++){
        distance += distance_pts[route.at(i)][route.at(i+1)];
    }
    return distance;
}

void BruteForce(){
    cout << "Processing =============================================" << endl;
    vector<int> route;
    for(int i = 0; i < pts.size(); i++){
        route.push_back(pts[i].getID());
    }
    route.push_back(pts[0].getID());
   
    vector<int> bestRoute(route);

    float traveled_distance = traveledDistance(route);
    cout << "The traveled distance is " << traveled_distance << endl;
    
    while(next_permutation(route.begin()+1, route.end()-1)){
        float temp = traveledDistance(route);
        if( temp < traveled_distance){
            traveled_distance = temp;
            bestRoute = route;
            cout << "The best travel distance for now is: " << traveled_distance << endl;
            
            /*
            cout << "The current best route is: ";
            
            for(int i = 0; i < bestRoute.size(); i++){
                cout << bestRoute[i] << " ";
            }
            cout << endl;
            */
        }
    }

    cout << "Results =============================================" << endl;
    cout << "The best route is from: ";
    for(int i = 0; i < bestRoute.size(); i++){
        int id = pts[bestRoute[i]].getID();
        cout << id << " ";
    }
    cout << endl;
    cout << "The best travel distance is " << traveled_distance << endl;
}


int main(int argc, char* argv[]){
    ReadFile(argv[1]);

    /*
    cout << "The input points are: " << endl;
    for(int i = 0; i < pts.size(); i++){
        int x = pts.at(i).getX();
        int y = pts.at(i).getY();
        int id = pts.at(i).getID();
        cout << "Position: " << x << " " << y << " ID: " << id << endl;
    }
    */

    cout << endl;
    clock_t initT;
    initT = clock();
    StoreDist();
    BruteForce();
    clock_t t = clock() - initT;
    double time = (double)t/CLOCKS_PER_SEC;
    cout << endl;
    cout << "The running time is: " << time << "s" << endl;

}