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
    string city[4];
    string source;
    string destination;  
    City* cityNodeArr[4];

    City *City1Node = new City;
    City *City2Node = new City;
    City *City3Node = new City;
    City *City4Node = new City;

    City *headcity1 = NULL, *headcity2 = NULL, *headcity3 = NULL, *headcity4 = NULL;

    public:
        Flight() {
            cityNodeArr[0] = City1Node;
            cityNodeArr[1] = City2Node;
            cityNodeArr[2] = City3Node;
            cityNodeArr[3] = City4Node;

            city[0] = "nashik";
            headcity1 = City1Node;
            headcity1 -> city = city[0];
            headcity1 -> next = NULL;

            city[1] = "mumbai";
            headcity2 = City2Node;
            headcity2 -> city[1];
            headcity2 -> next = NULL;

            city[2] = "pune";
            headcity3 = City3Node;
            headcity3 -> city[2];
            headcity3 -> next = NULL;

            city[3] = "gwalior";
            headcity4 = City4Node;
            headcity4 -> city[3];
            headcity4 -> next = NULL;
        }

        void addFlight() {
            cout<<endl<<"----------ADD FLIGHT----------"<<endl;
            cout<<"enter source>>  ";
            cin>>source;

            int ch = 1;
            while ( ch == 1 ) {
                City *currentNode = NULL;
                City *destinationNode = new City;
                
                cout<<"enter destination>>  ";
                cin>>destination;
                for ( int i = 0; i < 4; i++ ) {
                    if ( city[i] == source ) {
                        currentNode = cityNodeArr[i];
                        while ( currentNode -> next != NULL ) {
                            currentNode = currentNode -> next ;
                        }
                        currentNode -> next = destinationNode;
                        destinationNode -> city = destination;
                        destinationNode -> next = NULL;
                        cout<<"route added"<<endl;
                    }
                }
                cout<<"want to add more flight from same destination ?? (1/0):  ";
                cin>>ch;
            }
        }

        void checkFlight() {
            cout<<endl<<"----------CHECK FLIGHT----------"<<endl;
            City* currentNode;

            cout<<"source>>  ";
            cin>>source;
            cout<<"destination>>  ";
            cin>>destination;

            for ( int i = 0; i < 4; i++ ) {
                if ( city[i] == source ) {
                    currentNode = cityNodeArr[i];
                    while ( currentNode -> next != NULL ) {
                        if ( currentNode -> city == destination ) {
                            cout<< "Yes, the flight exists"<<endl;
                            return;
                        }
                        currentNode = currentNode -> next;
                    }
                    if ( currentNode -> city == destination ) {
                        cout<< "Yes, the flight exists"<<endl;
                        return;
                    }
                    cout<< "Sorry no direct flight is available"<<endl;
                    return;
                }
            }
            cout<<"No flight available from this source";
        }
};

int main() {
    Flight obj;

    int choice = 0;
    while ( choice != 3 ) {
        cout<<endl<<"********** MENU **********"<<endl;
        cout<<"1. add flight"<<endl;
        cout<<"2. check flight routes"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"enter choice: "; cin>>choice;

        switch( choice ) {
            case 1:
                obj.addFlight();
                break;
            
            case 2:
                obj.checkFlight();
                break;

            case 3:
                cout<<endl<<"exited..."<<endl<<endl;
                break;
            
            default:
                cout<<"enter a valid choice";
                break;
        }
    }

    return 0;
}
