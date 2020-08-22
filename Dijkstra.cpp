#include "Dijkstra.h"

Dijkstra::Dijkstra(Graph g) : graph(g) {};

void Dijkstra::setuplist(std::string s, std::string e) {
    unvisited = std::unordered_map<std::string, std::pair<double, std::string>>();
    Point start = graph[s];
    for (auto p : graph) {
        if (p.first == start.getid()){
            unvisited[p.first] = std::pair<double, std::string>(0.0, "");
        } else {
            unvisited[p.first] = std::pair<double, std::string>(__DBL_MAX__, "");
        }
    }
    //std::sort(queue.begin(), queue.end(), std::greater<int>());
}

std::string Dijkstra::findlowest() {
    double smallestweight = __DBL_MAX__;
    std::string smallestname = "no node";
    for (auto const &p : unvisited) {
        if (p.second.first < smallestweight) {
            smallestweight = p.second.first;
            smallestname = p.first;
        }
    }
    return smallestname;
}

//bool nodesexist(std::string s, std::string e) {   
//}

std::string Dijkstra::shortestpath(std::string s, std::string e) {
    setuplist(s, e);
    for (auto g : unvisited) {
        std::cout << "graph Node: " << g.first << ", graph wieght: " << g.second.first <<"\n";
    }
    do {
        auto node = findlowest();
        if (node.compare("no node") == 0) {
            break;
        }
        std::cout << "Current Node: " << node <<"\n";
        visited[node] = unvisited[node];
        //visited.emplace(std::pair<std::string, double>(unvisited[node].second, unvisited[node].first));
        if (node == e) {
            for (auto &p : visited) {
                std::cout << p.first << " " << p.second.first << " " << p.second.second<< "\n";
            }
            std::string finalPath = e;
            std::string transversal = e;
            while (visited[transversal].second != s) {
                transversal = visited[transversal].second;
                finalPath += "->" + transversal;
                //std::cout << finalPath;
            }
            finalPath += "->" + visited[transversal].second;
            return "Found Shortest Path: " + finalPath; //replace is string of nodes and wieghts
        }
        for (auto &edge : graph[node]) {
            if (visited.find(edge.second) != visited.end()) {
                continue;
            }
            std::cout << "edge Node: " << edge.second << ", edge weight: " << edge.first + unvisited[node].first <<"\n";
            std::cout << "current node weight: " << unvisited[node].first <<"\n";
            unvisited[edge.second].first = edge.first + unvisited[node].first;
            unvisited[edge.second].second = node;
        }
        unvisited.erase(node);
        for (auto g : unvisited) {
            std::cout << "graph Node: " << g.first << ", graph wieght: " << g.second.first <<"\n";
        }
    } while (unvisited.size());
    return "No path found";

}