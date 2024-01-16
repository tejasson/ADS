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

class City {
    public:
        string city;
        City *next;
};

class Flight {
    string city[5];
    string source;
    string destination;
    City* headArr[5];

    City* newCityNode1 = new City;
    City* newCityNode2 = new City;
    City* newCityNode3 = new City;
    City* newCityNode4 = new City;
    City* newCityNode5 = new City;

    City *headcity1 = NULL, *headcity2 = NULL, *headcity3 = NULL, *headcity4 = NULL, *headcity5 = NULL;

    public:
        Flight() {
            headArr[0] = newCityNode1;
            headArr[1] = newCityNode2;
            headArr[2] = newCityNode3;
            headArr[3] = newCityNode4;
            headArr[4] = newCityNode5;

            city[0] = "Nashik";
            newCityNode1 -> city = city[0];
            newCityNode1 -> next = NULL;
            newCityNode1 = headcity1;

            city[1] = "Mumbai";
            newCityNode2 -> city[1];
            newCityNode2 -> next = NULL;
            newCityNode2 = headcity2;

            city[2] = "Pune";
            newCityNode3 -> city[2];
            newCityNode3 -> next = NULL;
            newCityNode3 = headcity3;

            city[3] = "Gwalior";
            newCityNode4 -> city[3];
            newCityNode4 -> next = NULL;
            newCityNode4 = headcity4;

            city[4] = "Indore";
            newCityNode5 -> city[4];
            newCityNode5 -> next = NULL;
            newCityNode5 = headcity5;
        }

        void addFlight() {
            City *temp = NULL;
            City *destinationNode = new City;
            int ch = 1;
            while (ch == 1) {
                cout<<"enter source>>  ";
                cin>>source;
                cout<<"enter destination>>  ";
                for ( int i = 0; i < 5; i++ ) {
                    if ( city[i] == source ) {
                        headArr[i] -> next = destinationNode;
                        destinationNode -> city = destination;
                        destinationNode -> next = NULL;
                    }
                }

                cout<<"want to add flight?? (1/0):  ";
                cin>>ch;
            }
        }
};