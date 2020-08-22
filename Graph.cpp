#include "Graph.h"

Graph::Graph(std::string CSVfile) {
    io::CSVReader<3> in(CSVfile);
    in.read_header(io::ignore_extra_column,"Point1", "Point2", "Weight");
    std::string p1; std::string p2; double w;
    while (in.read_row(p1, p2, w)) {
        addedge(p1,p2,w);
    }
    return;
}
Point& Graph::operator[] (std::string name) {
    return graph.at(name);
}

std::vector<Point> Graph::getallpoints() {
    std::vector<Point> points;
    points.reserve(graph.size());
    for (auto const &kv : graph) {
        points.push_back(kv.second);
    }
    return points;
}

void Graph::addedge(std::string p1, std::string p2, double w) {
    if (graph.find(p1) == graph.end()) {
        graph.emplace(p1, Point(p1));
    } 
    if (graph.find(p2) == graph.end()) {
        graph.emplace(p2,Point(p2));
    }
    graph.at(p1).addconnection(p2, w);
    graph.at(p2).addconnection(p1, w);
}