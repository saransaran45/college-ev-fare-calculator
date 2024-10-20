#include <bits/stdc++.h>
using namespace std;

#define MAX_LOCATIONS 5

struct Location {
    string name;
    double fare;
};

class CollegeGraph {
    public:
    Location locations[MAX_LOCATIONS];
    double adjacencyMatrix[MAX_LOCATIONS][MAX_LOCATIONS];

public:
    CollegeGraph() {
        for (int i = 0; i < MAX_LOCATIONS; i++) {
            for (int j = 0; j < MAX_LOCATIONS; j++) {
                adjacencyMatrix[i][j] = numeric_limits<double>::max();
            }
        }
    }

    void addLocation(int index, const string& name, double fare) {
        locations[index] = {name, fare};
    }

    void addEdge(int source, int destination, double distance) {
        adjacencyMatrix[source][destination] = distance;
    }

    double calculateFare(int source, int destination) {
        double distance[MAX_LOCATIONS];
        bool visited[MAX_LOCATIONS] = {false};

        for (int i = 0; i < MAX_LOCATIONS; i++) {
            distance[i] = numeric_limits<double>::max();
        }

        distance[source] = 0.0;

        for (int count = 0; count < MAX_LOCATIONS - 1; count++) {
            int minDistanceIndex = -1;
            double minDistance = numeric_limits<double>::max();

            for (int i = 0; i < MAX_LOCATIONS; i++) {
                if (!visited[i] && distance[i] < minDistance) {
                    minDistance = distance[i];
                    minDistanceIndex = i;
                }
            }

            visited[minDistanceIndex] = true;

            for (int i = 0; i < MAX_LOCATIONS; i++) {
                if (!visited[i] && adjacencyMatrix[minDistanceIndex][i] != numeric_limits<double>::max() &&
                    distance[minDistanceIndex] + adjacencyMatrix[minDistanceIndex][i] < distance[i]) {
                    distance[i] = distance[minDistanceIndex] + adjacencyMatrix[minDistanceIndex][i];
                }
            }
        }

        return distance[destination];
    }
};

int main() {
    

    CollegeGraph graph;

    graph.addLocation(0, "main building", 0.0);
    graph.addLocation(1, "kp", 0.0);
    graph.addLocation(2, "gurunath", 0.0);
    graph.addLocation(3, "Vivek Audi", 0.0);
    graph.addLocation(4, "kottu gate", 0.0);
    
    graph.addEdge(0, 1, 20);
    graph.addEdge(0, 2, 15);
    graph.addEdge(1, 0, 20);
    graph.addEdge(1, 2, 10);
    graph.addEdge(1, 3, 30);
    graph.addEdge(2, 0, 15);
    graph.addEdge(2, 1, 10);
    graph.addEdge(2, 3, 25);
    graph.addEdge(2, 4, 30);
    graph.addEdge(3, 1, 30);
    graph.addEdge(3, 2, 25);
    graph.addEdge(3, 4, 20);
    graph.addEdge(4, 2, 30);
    graph.addEdge(4, 3, 20);

    cout<< "\t\t\t\tWELCOME TO CEG EV"<<endl;
    cout<<"\t\t\t\t-----------------\n\n";
    cout << "Available locations:" << endl;
    cout<<"--------------------\n";
    cout << "1. main building" << endl;
    cout << "2. kp" << endl;
    cout << "3. gurunath" << endl;
    cout << "4. Vivek Audi" << endl;
    cout << "5. kottur gate\n" << endl;

    int sourceIndex, destinationIndex,no_tickets;
    cout << "Enter the source location (number): ";
    cin >> sourceIndex;

    cout << "Enter the destination location (number): ";
    cin >> destinationIndex;
    double fare = graph.calculateFare(sourceIndex - 1, destinationIndex - 1);
	
	cout << "Fare from " << graph.locations[sourceIndex - 1].name << " to " << graph.locations[destinationIndex - 1].name << ":Rs." <<fare << endl;
   
    cout<<"\nEnter the no of tickets =";
    cin>>no_tickets;
    if (sourceIndex < 1 || sourceIndex > MAX_LOCATIONS || destinationIndex < 1 || destinationIndex > MAX_LOCATIONS) {
        cout << "Invalid source or destination location!" << endl;
        return 1;
    }

    
    
    cout << "Total Fare from " << graph.locations[sourceIndex - 1].name << " to " << graph.locations[destinationIndex - 1].name << ":Rs." << fare*no_tickets << endl;
    cout<<"\nCome Visit us Again!!!!"<<endl;
    cout<<"Thank you for using the App."<<endl;
    return 0;
}
