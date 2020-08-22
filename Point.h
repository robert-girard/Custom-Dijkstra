#pragma once

#include <vector>
#include <queue>
#include <utility>
#include <tuple>
#include <set>

//using namespace std;

class Point {
    private:
        std::string id;
        std::vector <std::pair<double, std::string>> connections;
    public:
        Point(std::string pid);
        double weighttoid(std::string pid);
        double weighttopoint(Point& point);
        void addconnection(Point& point, double wieght);
        void addconnection(std::string pid, double wieght);
        void removeconnection();
        std::string getid();
        std::vector<std::pair<double, std::string>>::iterator begin() { return connections.begin(); }
        std::vector<std::pair<double, std::string>>::const_iterator begin() const { return connections.begin(); }
        std::vector<std::pair<double, std::string>>::iterator end() { return connections.end(); }
        std::vector<std::pair<double, std::string>>::const_iterator end() const { return connections.end(); }
};

