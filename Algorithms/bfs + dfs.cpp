#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<vector<int> > & adj, int pieces [][1], int city, vector<bool> & vis) {
    queue<int> q;
    int foundPieces = 0;

    if (!vis[city]){
        q.push(city);
        foundPieces += pieces[city][0];
        vis[city] = true;
    }

    while(!q.empty()) {
        int adjCity = q.front();
        q.pop();

        for (int i = 0; i < adj[adjCity].size(); i++) {
            int currCity = adj[adjCity][i];
            if (!vis[currCity]) {
                q.push(currCity);
                foundPieces += pieces[currCity][0];
                vis[currCity] = true;
            }
        }
    }
    return foundPieces;
}

void dfs(vector<vector<int> > & adj, int pieces [][1], int city, vector<bool> & vis, int & foundPieces) {

    if (!vis[city])
        foundPieces += pieces[city][0];
    vis[city] = true;

    for (int i = 0; i < adj[city].size(); i++) {
        if (!vis[adj[city][i]]) {
            dfs(adj, pieces, adj[city][i], vis, foundPieces);
        }
    }
}

int main() {

    int foundPieces = 0, totalPieces = 0;

    int numOfCities, numOfRoads, numOfLocations, numOfFriends;
    cin >> numOfCities >> numOfRoads >> numOfLocations >> numOfFriends;
    vector<bool> vis (numOfCities, false);
    vector<vector<int> > adj (numOfCities, vector<int>());
    int friends [numOfFriends][1];
    int friendsCollection[numOfFriends];

    int pieces [numOfCities][1];
    for (int i = 0; i<numOfCities; i++) {
        pieces[i][0] = 0;
    }

    for (int i = 0; i < numOfRoads; i++) {
        int c1, c2;
        cin >>  c1 >> c2;
        adj[c1].push_back(c2);
        adj[c2].push_back(c1);
    }

    for (int i = 0; i < numOfLocations; i++) {
        int c, p;
        cin >> c >> p;
        pieces[c][0] = p;
        totalPieces += p;
    }

    for (int i = 0; i < numOfFriends; i++) {
        int c, f;
        cin >> c >> f;
        friends[f][0] = c;
    }

    //  USING BFS

    ofstream myStream ("result.txt", ios::out);
    if (!myStream.is_open()) {
        cout << "Error accessing the file" << endl;
        exit(1);
    }

    myStream << "Finding the result using BFS\n==============================\n";
    cout << "\nWriting BFS results in result.txt file..." << endl;

    for (int i = 0; i < numOfFriends; i++) {
        int singleFriendFound = bfs(adj, pieces, friends[i][0], vis);
        friendsCollection[i] = singleFriendFound;
        foundPieces += singleFriendFound;

    }

    if (foundPieces == totalPieces) {
        myStream << "Mission Accomplished" << endl;

    } else {
        myStream << "Mission Impossible" << endl;

    }

    myStream << foundPieces << " out of " << totalPieces << " pieces are collected" << endl;

    for (int i = 0; i < numOfFriends; i++) {
        myStream << i << " collected " << friendsCollection[i] << " pieces" << endl;
    }

    //  NOW USING DFS

    myStream << "\n\nFinding the result using DFS\n==============================\n";
    cout << "\nWriting DFS results in result.txt file..." << endl;

    vector<bool> vis2 (numOfCities, false);

    int previouslyFound = 0;
    foundPieces = 0;

    for (int i = 0; i < numOfFriends; i++) {
        dfs(adj, pieces, friends[i][0], vis2, foundPieces);
        friendsCollection[i] = foundPieces - previouslyFound;
        previouslyFound = foundPieces;

    }

    if (foundPieces == totalPieces) {
        myStream << "Mission Accomplished" << endl;
    } else {
        myStream << "Mission Impossible" << endl;
    }

    myStream << foundPieces << " out of " << totalPieces << " pieces are collected" << endl;

    for (int i = 0; i < numOfFriends; i++) {
        myStream << i << " collected " << friendsCollection[i] << " pieces" << endl;
    }
}



/*

10 8 4 3
0 4
0 1
2 0
2 1
1 3
6 5
5 7
9 8
0 5
3 6
5 3
9 2
4 0
7 2
2 1

Mission Impossible
14 out of 16 pieces are collected
0 collected 11 pieces
1 collected 0 pieces
2 collected 3 pieces

================

10 8 4 3
0 4
0 1
2 0
2 1
1 3
6 5
5 7
9 8
0 5
3 6
5 3
9 2
4 0
7 2
8 1

Mission Accomplished
16 out of 16 pieces are collected
0 collected 11 pieces
1 collected 2 pieces
2 collected 3 pieces

*/
