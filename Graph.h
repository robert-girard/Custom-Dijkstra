/* 
unordered_map of points
//http://www.cplusplus.com/reference/unordered_map/unordered_map/find/

overload the [] to give access to underlying map

*/
#pragma once
#include <unordered_map>
#include <iostream>
#include "Point.h"
#include "csv.h" // https://github.com/ben-strasser/fast-cpp-csv-parser

class Graph {
    private:
        std::unordered_map<std::string, Point> graph;
        std::unordered_map<std::string, int> idvals;
    public:
        Graph(std::string CSVfile);
        Point& operator [] (std::string name);
        std::vector<Point> getallpoints();
        void addedge(std::string p1, std::string p2, double w);
        void addedge(int p1, int p2, double w);
        std::unordered_map<std::string, Point>::iterator begin() { return graph.begin(); }
        std::unordered_map<std::string, Point>::const_iterator begin() const { return graph.begin(); }
        std::unordered_map<std::string, Point>::iterator end() { return graph.end(); }
        std::unordered_map<std::string, Point>::const_iterator end() const { return graph.end(); }
};
