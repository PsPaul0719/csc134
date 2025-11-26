/*
CSC 134
spencep
11/16/25
M6LAB2
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>
using namespace std;

// Define constants for directions
enum Direction {
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3,
    NUM_DIRECTIONS = 4
};

// Direction strings for output
const string DIRECTION_NAMES[NUM_DIRECTIONS] = {
    "north", "east", "south", "west"
};

// Define constants for rooms
enum Room {
    CORRIDOR = 0,
    LIBRARY = 1,
    ROOM_304 = 2,
    ROOM_299 = 3,
    BROOM_CLOSET = 4,
    NUM_ROOMS = 5
};

// Function that randomly selects a name from the list
string getRandomName(const vector<string>& names) {
    int randomIndex = rand() % names.size();
    return names[randomIndex];
}

// Function to handle searching Room 299 for the key
bool searchRoom299(const string& correctName) {
    string action;
    
    cout << "\nYou notice something glinting in the corner of the room." << endl;
    cout << "Would you like to search the room? (yes/no): ";
    cin.ignore();
    getline(cin, action);
    
    if (action == "yes" || action == "y") {
        cout << "\nYou search the seemingly empty room carefully..." << endl;
        cout << "You found a KEY with a name engraved on it!" << endl;
        cout << "The name on the key is: " << correctName << endl;
        return true;
    }
    
    return false;
}

// Function to handle the name lock puzzle on the creature's cage
bool handleNameLock(const string& correctName, bool hasKey) {
    string enteredName;
    string action;
    
    cout << "\n=== NAME LOCK SYSTEM ===" << endl;
    cout << "One of the cages containing the hideous creature has a name-based lock." << endl;
    cout << "What would you like to do?" << endl;
    cout << "1. Try to unlock the cage" << endl;
    cout << "2. Leave without trying" << endl;
    cout << "\nEnter your choice (1 or 2): ";
    cin.ignore();
    getline(cin, action);
    
    // Unlock attempt
    if (action == "1") {
        cout << "\nEnter the name to unlock: ";
        getline(cin, enteredName);
        
        // Check if the entered name matches the correct name
        if (enteredName == correctName) {
            cout << "\n*** Realeasing " << correctName<< ". ***" << endl;
            cout << "The creature's cage opens with a click!" << endl;
            cout << "The creature looks at you with gratitude before escaping..." << endl;
            if (hasKey) {
                cout << "Was freeing '" << correctName << "' really a good idea?"  << endl;
            }
            return true; // Successfully unlocked
        } else {
            cout << "\n*** ACCESS DENIED ***" << endl;
            cout << "Incorrect name. The cage remains locked." << endl;
            if (!hasKey) {
                cout << "Perhaps there's a clue somewhere else in the building..." << endl;
            }
            return false; // Failed to unlock
        }
    }
    
    return false; // Didn't try to unlock
}

int main() {
    // Seed the random number generator
    srand(time(0));
    
    // Create a list of possible names for the lock
    vector<string> nameList = {"Alice", "Bob", "Charlie", "Diana", "Edward", "Fiona"};
    string correctName = getRandomName(nameList);
    bool hasKey = false;
    bool cageUnlocked = false;
    bool searchedRoom299 = false;
    
    // Room names array
    string roomNames[NUM_ROOMS] = {
        "Corridor",
        "Library",
        "Room 304",
        "Room 299",
        "Broom Closet"
    };
    
    // Room descriptions array
    string roomDescriptions[NUM_ROOMS] = {
        "The hall that holds the haunting memories of The Doctor's operations.",
        "Walls lined with ancient books. The air smells of old paper.",
        "A spacious office that has an array of cages. One of these cages holds a hideous creature that seems human...",
        "A seemingly empty room, is it void of purpose and meaning?",
        "A dark, damp broom closet full of rusted and bloodied tools"
    };
    
    // Adjacency list using a 2D array
    // connections[from_room][direction] = to_room or -1 if no connection
    int connections[NUM_ROOMS][NUM_DIRECTIONS];
    
    // Initialize all connections to -1 (no connection)
    for (int i = 0; i < NUM_ROOMS; i++) {
        for (int j = 0; j < NUM_DIRECTIONS; j++) {
            connections[i][j] = -1;
        }
    }
    
    // Define the connections between rooms using the Room enum
    // Entrance Hall connections
    connections[CORRIDOR][NORTH] = LIBRARY;    // Entrance Hall -> North -> Library
    connections[CORRIDOR][EAST] = ROOM_304;     // Entrance Hall -> East -> ROOM_304
    connections[CORRIDOR][SOUTH] = -1;         // No connection south
    connections[CORRIDOR][WEST] = ROOM_299;      // Entrance Hall -> West -> ROOM_299
    
    // Library connections
    connections[LIBRARY][NORTH] = -1;               // No connection north
    connections[LIBRARY][EAST] = -1;                // No connection east
    connections[LIBRARY][SOUTH] = CORRIDOR;    // Library -> South -> Entrance Hall
    connections[LIBRARY][WEST] = -1;                // No connection west
    
    // ROOM_304 connections
    connections[ROOM_304][NORTH] = -1;               // No connection north
    connections[ROOM_304][EAST] = -1;                // No connection east
    connections[ROOM_304][SOUTH] = BROOM_CLOSET;         // ROOM_304 -> South -> BROOM_CLOSET
    connections[ROOM_304][WEST] = CORRIDOR;     // ROOM_304 -> West -> Entrance Hall
    
    // ROOM_299 connections
    connections[ROOM_299][NORTH] = -1;                // No connection north
    connections[ROOM_299][EAST] = CORRIDOR;      // ROOM_299 -> East -> Entrance Hall
    connections[ROOM_299][SOUTH] = -1;                // No connection south
    connections[ROOM_299][WEST] = -1;                 // No connection west
    
    // BROOM_CLOSET connections
    connections[BROOM_CLOSET][NORTH] = ROOM_304;         // BROOM_CLOSET -> North -> ROOM_304
    connections[BROOM_CLOSET][EAST] = -1;               // No connection east
    connections[BROOM_CLOSET][SOUTH] = -1;              // No connection south
    connections[BROOM_CLOSET][WEST] = -1;               // No connection west
    
    // Game state
    int currentRoom = CORRIDOR; // Start in the Entrance Hall
    bool gameRunning = true;
    
    // Game loop
    while (gameRunning) {
        // Display current room information
        cout << "\nYou are in the " << roomNames[currentRoom] << endl;
        cout << roomDescriptions[currentRoom] << endl;
        
        // Special interaction for Room 299 - searching for key
        if (currentRoom == ROOM_299 && !searchedRoom299 && !hasKey) {
            if (searchRoom299(correctName)) {
                hasKey = true;
                searchedRoom299 = true;
            }
        }
        
        // Special interaction for Room 304 - cage lock puzzle
        if (currentRoom == ROOM_304 && !cageUnlocked) {
            string cageAction;
            cout << "\nYou notice the creature cage has a name lock on it." << endl;
            cout << "Would you like to examine it? (yes/no): ";
            cin >> cageAction;
            
            if (cageAction == "yes" || cageAction == "y") {
                cageUnlocked = handleNameLock(correctName, hasKey);
            }
        }
        
        // Show available exits
        cout << "Exits: ";
        bool hasExits = false;
        for (int dir = 0; dir < NUM_DIRECTIONS; dir++) {
            if (connections[currentRoom][dir] != -1) {
                cout << DIRECTION_NAMES[dir] << " ";
                hasExits = true;
            }
        }
        if (!hasExits) {
            cout << "none";
        }
        cout << endl;
        
        // Get player input
        string command;
        cout << "\nWhat would you like to do? ";
        cin >> command;
        
        // Process movement commands
        if (command == "north" || command == "n") {
            if (connections[currentRoom][NORTH] != -1) {
                currentRoom = connections[currentRoom][NORTH];
            } else {
                cout << "You can't go that way." << endl;
            }
        } else if (command == "east" || command == "e") {
            if (connections[currentRoom][EAST] != -1) {
                currentRoom = connections[currentRoom][EAST];
            } else {
                cout << "You can't go that way." << endl;
            }
        } else if (command == "south" || command == "s") {
            if (connections[currentRoom][SOUTH] != -1) {
                currentRoom = connections[currentRoom][SOUTH];
            } else {
                cout << "You can't go that way." << endl;
            }
        } else if (command == "west" || command == "w") {
            if (connections[currentRoom][WEST] != -1) {
                currentRoom = connections[currentRoom][WEST];
            } else {
                cout << "You can't go that way." << endl;
            }
        } else if (command == "quit" || command == "q") {
            gameRunning = false;
        } else {
            cout << "I don't understand that command." << endl;
        }
    }
    
    cout << "Thanks for playing!" << endl;
    return 0;
}