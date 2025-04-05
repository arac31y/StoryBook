//============================================================================
// Name        : Text.cpp
// Author      : Aracely
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
using namespace std;
#include <vector>
#include <string.h>


void start();
void forwardOption();
void lookOver();
void askPeople();
void walkBus();
void observeSurroundings();
void line1();
void line2();
void line3();
void walkUptown();
void walkDowntown();
void takeMap();
void leaveMap();
void stayBus();
void takeLine1();


vector<string> inventory{};
int score = 0;

int main() {
  cout << "Welcome to the story book we all loved as kids - you choose your own fate based on the decisions you make and directions you go. Your journey awaits you!\n";
  start();
}

// a function which takes a vector of options and prints them
void showOptions(vector<string> options) {
  for (string option : options) {
    // cout option
    cout << option << "\n";
  }
}

// a function which determines if a given item is contained in the given vector
bool contains(vector<string> options, string s) {
  // should return true if s in options, false otherwise
  // hint: use a for loop
  for(string option : options){
    if(option == s){
      return true;
    }
  }
  return false;
}

// a function which takes a vector of options and asks what the player wants to do and doesn't return the option until the player selects one of the given options
string getOption(vector<string> options) {
  // Hint: use a while loop
  cout << "> ";
  // string option;
  char option[256];
  cin.getline (option, 256);
  if(strcmp(option, "inventory")== 0){
    showOptions(inventory);
    return getOption(options);
  }
  while(!contains(options, option)) {
    cout << "Not an option, try again.\n";
    cout << "> ";
    cin.getline (option, 256);
    if(strcmp(option, "inventory")== 0){
      showOptions(inventory);
      return getOption(options);
    }
  }
  return option;
}

void start(){
  cout << "Starting Location: You opened your eyes and you found yourself in a world you're not familiar with. You can choose to walk around, but you you realize you're standing on top of a bridge. You can look over the bridge or decide to keep walking?  \n";

  vector<string> options {"Move forward", "Look over the bridge"};

  showOptions(options);

  string option = getOption(options);

  if(option == "Move forward"){
    forwardOption();
  }
  if(option == "Look over the bridge"){
    cout << "There is a group of people gathered at a park. It might be a good idea to ask them where you are, but you also can decide to continue moving forward and figuring out this adventure on your own. What will you do?";
      
      vector<string> options {"Ask people", "Move forward"};
      
      showOptions(options);
      
      string option = getOption(options);
      
      if(option == "Ask people"){
          askPeople();
      }
      if(option == "Move forward"){
          forwardOption();
      }
  }
}

void askPeople(){
    cout << "You are walking up to the group of people. None of them seem to be familiar, so you feel a bit intimidated asking them where you could be going.\n";
    cout << "They all turn to watch as you approach them. 'Hey' one of them tells you, they seem friendly, you give a wave back.\n";
    cout << "What will you say?\n";
    
}
//cin-  input

void forwardOption(){
  cout << "You're now at the end of the bridge.\n";
  cout << "You are entering the big city. Do you want to walk to the bus stop, or take a moment to look around? \n";

  vector<string> options {"walk to the bus stop", "stop to observe your surroundings"};

  showOptions(options);

  string option = getOption(options);

  if(option == "walk to the bus stop"){
    walkBus();
  }
  if(option == "stop to observe your surroundings"){
    observeSurroundings();
  }
}
void walkBus(){
  cout << "There are 3 different bus lines you could take. Line 1 takes you downtown, line 2 takes you to lake, line 3 takes you to the airport.\n";

  vector<string> options {"line 1", "line 2", "line 3"};

  showOptions(options);

  string option = getOption(options);

  if(option == "line 1"){
    line1();
  }
  if(option == "line 2"){
    line2();
  }
  if(option == "line 3"){
      
  }
}
void observeSurroundings(){
    cout << "You're on 8th Street and Montgomery. If you walk a few blocks going uptown, you will see tall buildings. If you walk going towards downtown, you will see be able to see the rest of the city\n";

    vector<string> options{"walk uptown", "walk downtown"};

    showOptions(options);

    string option = getOption(options);

    if(option == "walk uptown"){
      walkUptown();
    }
    if(option == "walk downtown"){
      walkDowntown();
    }
}
void line1(){
  cout <<"You are now heading towards downtown. The bus is going pretty fast and there are a lot of passengers getting on. There are maps available at the front of the bus\n";

  vector<string> options {"take a map", "don't take a map"};

  showOptions(options);

  string option = getOption(options);

  if(option == "take a map"){
    takeMap();
  }
}
void line2() {
    cout<<"This bus is taking you out of the city. You will get onto the highway and head towards another town.\n";
    
    vector<string> options {"take the map out your inventory"};
    
    showOptions(options);
    
    string option = getOption(options);
    
}

void line3() {
      cout<<"You are going to the airport. Once you arrive there, you are able to book a ticket to the following: Trinidad and Tobago, Seattle, Washington, and Tokyo, Japan. which will you choose?.\n";

      vector<string> options {"Trinidad and Tobago", "Seattle", "Tokyo"};

      showOptions(options);

      string option = getOption(options);

}
void walkUptown() {
  cout<<"It was not a good idea to walk, you are extremely tired. Take the nearest bus to save some energy.\n ";

  vector<string> options {"line 1"};

  showOptions(options);

  string option = getOption(options);

  if (option == "line 1"){
    line1();
  }
}

void walkDowntown() {
  cout<<"You're walking downtown but you're starting to feel really tired. Bus line 2 is about to pass you. Run to the bus stop to catch it.\n";

  vector<string> options {"line 2"};

  showOptions(options);

  string option = getOption(options);

  if (option == "line 2"){
    line2();
  }
}

void takeMap() {
  cout<< "Because you took the map, it will be stored in your inventory. You notice that there is a parade taking place on 57th street. Take the line until that stop.\n";

  inventory.push_back("map");

}

