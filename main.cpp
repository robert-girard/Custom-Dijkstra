#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <fstream>
#include "Dijkstra.h"

//using namespace std;

void license() {
    std::cout << "\n\n\nThis programs uses Fast C++ CSV Parser (https://github.com/ben-strasser/fast-cpp-csv-parser) for csv parsing \n\n";
    std::string lic = 
        "Copyright: (2012-2015) Ben Strasser <code@ben-strasser.net>\n"
        "License: BSD-3\n"
        "\n"
        "All rights reserved.\n"
        "\n"
        "Redistribution and use in source and binary forms, with or without\n"
        "modification, are permitted provided that the following conditions are met:\n"
        "\n"
        " 1. Redistributions of source code must retain the above copyright notice,\n"
        "    this list of conditions and the following disclaimer.\n"
        "\n"
        "2. Redistributions in binary form must reproduce the above copyright notice,\n"
        "   this list of conditions and the following disclaimer in the documentation\n"
        "   and/or other materials provided with the distribution.\n"
        "\n"
        "3. Neither the name of the copyright holder nor the names of its contributors\n"
        "   may be used to endorse or promote products derived from this software\n"
        "   without specific prior written permission.\n"
        "\n"
        "THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\"\n"
        "AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE\n"
        "IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE\n"
        "ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE\n"
        "LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR\n"
        "CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF\n"
        "SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS\n"
        "INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN\n"
        "CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)\n"
        "ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE\n"
        "POSSIBILITY OF SUCH DAMAGE. ";
    std::cout << lic +"\n\n\n";

}


bool validateinput(Graph graph, std::string start, std::string end) {
    bool s = false;
    bool e = false;

    //make sure they are diff points
    if (start.compare(end) == 0) {
        std::cout << "Start and End nodes must be different\n";
        return false;
    }

    std::vector<Point> points = graph.getallpoints();
    for (Point p : points) {
        std::string nodename = p.getid();
        if (start.compare(nodename) == 0) {
            s = true;
        } else if (end.compare(nodename) == 0) {
            e = true;
        }
    }

    if ((s & e) == false ) {
        std::cout << "Start and end nodes must be one of the following: \n";
        for (Point p : points) {
            std::cout << p.getid() + "\n";
        }
        return false;
    }
    return true;
}

std::string* getnodes() {
    std::string *nodes = new std::string[2];

    std::cout << "Please enter the starting node: \n";
    std::cin >> nodes[0];
    std::cout << "Please enter the ending node: \n";
    std::cin >> nodes[1];

    return nodes;
}


int main()
{
    std::string *nodes;

    license();
    
    Graph mygraph = Graph("Graph.csv");
    Dijkstra alg =  Dijkstra(Graph("Graph.csv"));

    nodes = getnodes();
    while (!validateinput(mygraph, nodes[0], nodes[1])) {
        nodes = getnodes();
    }

    std::cout << alg.shortestpath(nodes[0], nodes[1]);

    
}