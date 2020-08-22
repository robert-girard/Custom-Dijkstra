#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include "Point.h"
#include <string>

/*
Point(int id);
double weighttoid(int id);
double weighttopoint(Point& point);
void addconnection(Point& point, double wieght);
void addconnection(int pid, double wieght);
void removeconnection();
int getid();
*/

Point::Point(std::string pid) : id(pid) {}

double Point::weighttoid(std::string pid) {
    /* returns weight of point to id, and max weight if not found */

    for (std::pair<double, std::string> const &val : connections ) {
        if (val.second == pid) {
            return val.first;
        }
    };
    return __builtin_inf();
}


std::string Point::getid() {
    return id;
}


double Point::weighttopoint(Point& point) {
    /* returns weight of point to id, and max weight if not found */

    for (std::pair<double, std::string> const &val : connections ) {
        if (val.second == point.getid()) {
            return val.first;
        }
    };
    return __builtin_inf();
}

void Point::addconnection(std::string pid, double wieght) { // need to update to see if there is already connection then use only shorter connection
    for (auto &p : connections) {
        if (p.second == pid) {
            if (p.first > wieght) {
                p.first = wieght;
            }
            return;
        }
    }
    std::pair<double, std::string> p;
    p.first = wieght;
    p.second = pid;
    connections.push_back(p);
    std::push_heap(connections.begin(), connections.end(), std::greater<std::pair<double, std::string>>());
    return;
}

void Point::addconnection(Point& point, double wieght) {
    std::pair<double, std::string> p;
    p.first = wieght;
    p.second = point.getid();
    connections.push_back(p);
    std::push_heap(connections.begin(), connections.end(), std::greater<std::pair<double, std::string>>());
}