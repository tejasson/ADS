// Graph traversal: The area around the college and the prominent
// landmarksNode of it are represented using graphs.
// Write a menu driven C++ program to represent this as a graph using
// adjacency matrix /list and perform DFS and BFS.

// https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/

#include<iostream>
#include<queue>
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

    string visited[10];
    queue<string> q;

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

        void BFSTraversal (string start) {
            cout<<endl << "BFS starting from node '" << start << "': "<<endl;
            int visitedIndex = 1, flag = 0;
            
            temp = landmarksArr[0];
            q.push(start);
            visited[0] = start;

            while (!q.empty()) {
                q.pop();               
                while (temp->next != NULL) {
                    temp = temp->next;
                    
                    for (int i = 0; i < visitedIndex; i++) {
                        flag = 0;
                        if (temp->place == visited[i]) {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0) {
                        q.push(temp->place);
                        visited[visitedIndex] = temp->place;
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
                cout<<visited[i]<<"   ";
            }
        }
};

int main() {
    GraphTraversal obj;
    obj.addplace("engg");
    obj.addplace("poly");
    obj.addplace("pharma");
    obj.addplace("canteen");
    obj.addplace("parking");

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

    return 0;
}
