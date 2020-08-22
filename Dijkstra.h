#pragma once

#include <tuple>
#include <vector>
#include <set>
#include "Graph.h"
#include <iostream>


class Dijkstra {
    private:
        Graph graph;
        std::unordered_map<std::string, std::pair<double, std::string>> unvisited;      //
        std::unordered_map<std::string, std::pair<double, std::string>> visited;        // visited 
        std::unordered_map<std::string, std::string> frommap;
        std::string cache;  //use this to cache last path
        int graphhash;      //use this to check if the graph has changed since last call
        void setuplist(std::string s, std::string e);
        std::string findlowest();
        //bool nodesexist(std::string s, std::string e);

    public:
        Dijkstra(Graph g);
        std::string shortestpath(std::string s, std::string e);
};

