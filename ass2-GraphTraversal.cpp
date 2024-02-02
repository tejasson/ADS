// Graph traversal: The area around the college and the prominent landmarks of it are represented using graphs. Write a menu driven C++ program to represent this as a graph using adjacency matrix /list and perform DFS and BFS.

#include<iostream>
using namespace std;

class Vertices {
    public:
        string place;
        Vertices *next;
};

class GraphTraversal {
    Vertices *places[100];
    int placesIndex, flag;
    Vertices *firstplace = new Vertices;
    Vertices *nextPlace = new Vertices;
    Vertices *temp;
    
    public:
        GraphTraversal() {
            placesIndex = 0;
        }
        void addEdge(string place1, string place2) {
            //to check if the place1 already is in the array or not
            for (int i = 0; i < placesIndex; i++) {
                flag = 0;
                if (places[i]->place == place1) {
                    flag = 1;
                    break;
                }
            }
            if (flag != 1) {
                places[placesIndex] = firstplace;
                firstplace->place = place1;
                firstplace->next = NULL;
                placesIndex++;
            }        

            //to add edge
            for (int i = 0; i < placesIndex; i++) {
                temp = places[i];
                if (temp->place == place1) {
                    while (temp->next != NULL) {
                        temp = temp->next;
                    }
                    temp->next = nextPlace;
                    nextPlace->place = place2;
                    nextPlace->next = NULL;
                }
            }
            cout<<"added"<<endl;
        }
};

int main() {
    GraphTraversal obj;
    obj.addEdge("library","xerox");

    return 0;
}