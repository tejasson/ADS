// Flight management: There are flight paths between cities. If there is a
// flight between city A and city B then there is an edge between the cities.
// The cost of the edge can be the time that flight takes to reach city B from
// A, or the amount of fuel used for the journey.
// Write a menu driven C++ program to represent this as a graph using
// adjacency matrix and adjacency list. The node can be represented by the
// airport name or name of the city. Check whether cities are connected
// through flight or not. Compare the storage representation.

#include<iostream>
using namespace std;

class CityNode {
    public:
        string city;
        int flightTime;
        CityNode *next;
};

class FlightGraph {
    CityNode *temp;
    CityNode *CityArr[10];
    int cityIndex = 0;

    public:
        void addCity (string city) {
            CityNode *newCity = new CityNode;
            CityArr[cityIndex] = newCity;
            newCity->city = city;
            newCity->flightTime = 0;
            newCity->next = NULL;
            cityIndex++;
            cout<<"City added"<<endl;
        }

        void addFlight (string src, string dest, int time) {
            CityNode *newCity = new CityNode;
            for (int i = 0; i < cityIndex; i++) {
                if (CityArr[i]->city == src) {
                    temp = CityArr[i];
                    while (temp->next != NULL) {
                        temp = temp->next;                        
                    }
                    temp->next = newCity;
                    newCity->city = dest;
                    newCity->flightTime = time;
                    newCity->next=NULL;
                }
            }
            cout<<"route added"<<endl;
        }

        void checkFlight(string src, string dest) {
            for (int i = 0; i < cityIndex; i++) {
                if (src == CityArr[i]->city) {
                    temp = CityArr[i];
                    while (temp->next != NULL) {
                        temp = temp->next;
                        if (dest == temp->city) {
                            cout<<endl<<"there's a flight which takes "<<temp->flightTime<<" min"<<endl;
                            return;
                        }
                    }
                }
            }
            cout<<"no flight between these cities"<<endl;
        }

        void adjacencyList() {
            cout << endl << "----------ADJACENCY LIST----------" << endl;
            for (int i = 0; i < cityIndex; i++) {
                temp = CityArr[i];
                cout<<temp->city;
                while (temp->next != NULL) {
                    temp = temp->next;
                    cout<<" -> "<<temp->city;
                }
                cout<<endl;
            }
        }

        void adjacencyMatrix() {
            cout << endl << "----------ADJACENCY MATRIX----------" << endl;
            int matrix[cityIndex][cityIndex];
            for (int i = 0; i < cityIndex; i++) {
                for (int j = 0; j < cityIndex; j++) {
                    matrix[i][j] = 0;
                }
            }
            for (int i = 0; i < cityIndex; i++) {
                temp = CityArr[i];
                for (int j = 0; j < cityIndex; j++) {
                    string cityB = CityArr[j]->city;
                    while (temp->next != NULL) {
                        temp = temp->next;
                        if (temp->city == cityB) { 
                            matrix[i][j] = 1;
                        }
                    }
                }
            }
            for (int i = 0; i < cityIndex; i++) {
                for (int j = 0; j < cityIndex; j++) {
                    cout<<matrix[i][j]<<"  ";
                }
                cout<<endl;
            }
        }
};

int main() {
    FlightGraph obj;

    obj.addCity("nashik");
    obj.addCity("mumbai");
    obj.addCity("udaipur");
    obj.addCity("rishikesh");

    obj.addFlight("nashik", "mumbai", 60);
    obj.addFlight("mumbai", "udaipur", 150);
    obj.addFlight("udaipur", "nashik", 180);
    obj.addFlight("rishikesh", "mumbai", 180);

    obj.checkFlight("nashik","mumbai");
    obj.checkFlight("mumbai","nashik");

    obj.adjacencyList();

    obj.adjacencyMatrix();

    return 0;
}
