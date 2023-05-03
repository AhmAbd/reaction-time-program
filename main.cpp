#include <iostream>
#include <chrono>
#include <cstdint>
#include <ctime>
#include <cstdlib>
using namespace std;
  //Test
  uint64_t highScore = 999999;

  uint64_t timeSinceEpochMillisec() {
  using namespace std::chrono;
  return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
  }

  void endloopbetween3and15secs() {
      auto startcount = chrono::high_resolution_clock::now();
      int duration = 0;

      while (duration < 3000) {
        duration = chrono::duration_cast<chrono::milliseconds>(
        chrono::high_resolution_clock::now() - startcount).count();
      }

      int mostduration = rand() % 12000 + 3000;

      while (duration < mostduration) {
        duration = chrono::duration_cast<chrono::milliseconds>(
        chrono::high_resolution_clock::now() - startcount).count();
      }

  }
    
  void reactionTime() {
    uint64_t firsttime, secondtime;
    uint64_t last;
    srand(time(NULL));
    uint64_t random_num;
    string input;
    cout << "Please wait for a prompt to click enter and view your reaction time. The prompt will appear randomly within the next 3 to 15 seconds";
    cout << endl << "THE PROGRAM WILL NOT WORK PROPERLY IF YOU PRESS BEFORE YOU GET THE PROMPT!" << endl << endl;
    endloopbetween3and15secs();
    fflush(stdin);
    cout << "CLICK NOW";
    firsttime = timeSinceEpochMillisec();
    getline(cin, input);
    secondtime = timeSinceEpochMillisec();
    last = secondtime - firsttime;
    if(last < highScore || highScore == 0) {
      highScore = last;
    }
    cout << endl << endl << endl << "Your reaction time is " << last << " ms." << endl;
    cout << "Highscore: " << highScore << endl << endl;
  }

  void showMenu() {
    int input1;
    while(input1 != 1 && input1 != 2) {
      cout << "Choose one of the options:" << endl <<"1. Reaction Time tester" << endl << "2. Exit Program" << endl;
      cin >> input1;
    }
    switch(input1) {
      case 1:
      reactionTime();
      break;
      case 2:
      cout << "Exiting..."
      exit(0);
      break;
    }
    showMenu();
  }

int main() {
    showMenu();
    return 0;
}