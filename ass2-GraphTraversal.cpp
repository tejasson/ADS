// Graph traversal: The area around the college and the prominent
// landmarksNode of it are represented using graphs.
// Write a menu driven C++ program to represent this as a graph using
// adjacency matrix /list and perform DFS and BFS.

// https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class landmarksNode {
    public:
        string place;
        landmarksNode *next;
};

class GraphTraversal {
    int landmarkIndex = 0;
    landmarksNode *temp;

    landmarksNode *landmarksArr[10];

    string visitedQ[10];
    queue<string> q;

    string visitedStk[10];
    stack<string> stk;

    public:
        void addplace (string place) {
            landmarksNode *newPlace = new landmarksNode;
            landmarksArr[landmarkIndex] = newPlace;
            newPlace->place = place;
            newPlace->next = NULL;
            landmarkIndex++;
            cout<<"landmark added"<<endl;
        }

        void addedge (string from, string to) {
            landmarksNode *newPlace = new landmarksNode;
            for (int i = 0; i < landmarkIndex; i++) {
                if (from == landmarksArr[i]->place) {
                    temp = landmarksArr[i];
                    while (temp->next != NULL) {
                        temp = temp->next;
                    }
                    temp->next = newPlace;
                    newPlace->place = to;
                    newPlace->next = NULL;
                }
            }
            cout<<"edge added"<<endl;
        }

        void BFSTraversal (string start) {  //Breadth first traversal
            cout<<endl << "BFS starting from node '" << start << "': "<<endl;
            
            int visitedIndex = 1;
            string flag = "green";
            temp = landmarksArr[0];
            q.push(start);
            visitedQ[0] = start;

            while (!q.empty()) {
                q.pop();               
                while (temp->next != NULL) {
                    temp = temp->next;
                    
                    for (int i = 0; i < visitedIndex; i++) {
                        flag = "green";
                        if (temp->place == visitedQ[i]) {
                            flag = "red";
                            break;
                        }
                    }
                    if (flag == "green") {
                        q.push(temp->place);
                        visitedQ[visitedIndex] = temp->place;
                        visitedIndex++;
                    }
                }
                for (int i = 0; i < landmarkIndex; i++) {
                    if (q.front() == landmarksArr[i]->place) {
                        temp = landmarksArr[i];
                        break;
                    }
                }
            }
            for (int i = 0; i < visitedIndex; i++) {
                cout<<visitedQ[i]<<" | ";
            }
            cout<<endl;
        }

        void DFSTraversal (string start) { //Depth first search
            cout<<endl << "DFS starting from node '" << start << "': "<<endl;

            int visitedIndex = 0;
            string flag = "green";
            for (int i = 0; i < landmarkIndex; i++) {
                if (start == landmarksArr[i]->place) {
                    temp = landmarksArr[i];
                    stk.push(temp->place);
                    visitedStk[visitedIndex] = temp->place;
                    visitedIndex++;
                    break;
                }
            }
            while (!stk.empty()) {
                stk.pop();
                while (temp->next != NULL) {
                    temp = temp->next;
                    for (int i = 0; i < visitedIndex; i++) {
                        if (temp->place == visitedStk[i]) {
                            flag = "red";
                            break;
                        }
                    }
                    if (flag == "green") {
                        stk.push(temp->place);
                    }
                }
                visitedStk[visitedIndex] = stk.top();
                visitedIndex++;

                for (int i = 0; i < landmarkIndex; i++) {
                    if (stk.top() == landmarksArr[i]->place) {
                        temp = landmarksArr[i];
                        break;
                    }
                }
            }
            for (int i = 0; i < visitedIndex; i++) {
                cout<<visitedStk[i]<<"   ";
            }
            cout<<endl;
        }
};

int main() {
    GraphTraversal obj;
    obj.addplace("engg");
    obj.addplace("poly");
    obj.addplace("pharma");
    obj.addplace("canteen");
    obj.addplace("parking");

    cout<<endl;
    obj.addedge("engg","parking");
    obj.addedge("engg","canteen");
    obj.addedge("pharma","poly");
    obj.addedge("pharma","canteen");
    obj.addedge("poly","parking");
    obj.addedge("poly","pharma");
    obj.addedge("canteen","parking");
    obj.addedge("canteen","engg");
    obj.addedge("canteen","pharma");
    obj.addedge("parking","canteen");
    obj.addedge("parking","poly");
    obj.addedge("parking","engg");

    obj.BFSTraversal("engg");
    
    obj.DFSTraversal("engg");

    return 0;
}
