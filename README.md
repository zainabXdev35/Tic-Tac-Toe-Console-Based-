#Tic-Tac-Toe Game in C++

A feature-rich console-based Tic-Tac-Toe game built in C++ with player record tracking, animated displays, and comprehensive input validation. This project demonstrates fundamental C++ programming concepts and game development logic.

#Project Overview

This is an interactive two-player Tic-Tac-Toe game that runs in the console. Players can enjoy a classic game experience with modern features like persistent score tracking, animated text displays, and detailed help menus. The game includes a robust scoring system that rewards strategic diagonal wins with bonus points.

#Features

- **Two-Player Gameplay**: Classic turn-based Tic-Tac-Toe for two human players
- **Player Name Customization**: Personalized gaming experience with custom player names
- **Animated Text Display**: Smooth, typewriter-style text animations for enhanced UX
- **Comprehensive Help Menu**: Built-in tutorial explaining game rules and scoring
- **Smart Input Validation**: Robust error handling for invalid inputs and occupied spaces
- **Score Tracking System**: 
  - Win: 10 points 
  - Tie game: 0 points
- **Player Records**: Persistent statistics across multiple games including:
  - Total wins
  - Total points
  - Tie count
- **Replay Functionality**: Play multiple rounds without restarting the program
- **Clear Visual Board**: Well-formatted 3×3 grid with intuitive position numbering

#Technologies Used

- **Language**: C++ (C++11 or higher)
- **Standard Libraries**:
  - `<iostream>` - Input/output operations
  - `<thread>` - Multi-threading for animations
  - `<chrono>` - Time management for delays
  - `<iomanip>` - Output formatting
  - `<string>` - String manipulation
- **Compiler**: Any C++ compiler (GCC, Clang, MSVC)
- **Platform**: Windows (uses `system("cls")` for screen clearing)

#Project Structure

```
final_tic_tac.cpp
├── Structures
│   └── PlayerRecord (stores player stats)
├── Global Variables
│   ├── Game board array
│   ├── Player turn tracker
│   └── Player record objects
├── Functions
│   ├── helpMenu()         - Displays game instructions
│   ├── animated_display() - Creates typewriter effect
│   ├── get_player_names() - Captures player names
│   ├── display_board()    - Renders game board
│   ├── player_turn()      - Handles player moves
│   ├── game_Over()        - Checks win/draw conditions
│   ├── update_records()   - Updates player statistics
│   └── display_records()  - Shows final scoreboard
└── main()                 - Game loop and menu system
```

#How to Run

### Prerequisites
- C++ compiler installed (g++, MinGW, or Visual Studio)
- Windows OS (for `system("cls")` command)

### Compilation & Execution

**Using g++ (Command Line):**
```bash
g++ final_tic_tac.cpp -o TicTacToe
TicTacToe.exe
```

**Using MinGW:**
```bash
g++ -std=c++11 final_tic_tac.cpp -o TicTacToe
TicTacToe.exe
```

**Using Visual Studio:**
1. Create a new C++ Console Application project
2. Add `final_tic_tac.cpp` to the project
3. Build and run (F5)

#Gameplay Instructions
1. Launch the program
2. Choose option 1 to play or 2 for help menu
3. Enter player names when prompted
4. Players take turns entering numbers 1-9 corresponding to board positions
5. First to get three in a row (horizontal, vertical, or diagonal) wins
6. View final statistics after exiting

#Concepts Covered

This project demonstrates mastery of core C++ programming concepts:

### **1. Data Structures**
- **Structures** (`PlayerRecord`) for organizing related data
- **2D Arrays** for game board representation

### **2. Control Flow**
- `if-else` statements for game logic
- `switch-case` for menu navigation and position selection
- `do-while` and `while` loops for game continuation

### **3. Functions**
- Modular programming with dedicated functions
- Parameter passing and return types
- Void functions for display operations

### **4. Input/Output**
- Console I/O using `cin` and `cout`
- Formatted output with `setw()` and alignment
- Input validation and error handling

### **5. String Manipulation**
- `getline()` for multi-word input
- String operations and comparisons

### **6. Advanced Features**
- **Threading** (`std::thread`) for animations
- **Timing** (`std::chrono`) for delays
- System calls for screen management

### **7. Error Handling**
- Input stream validation with `cin.fail()`
- Clearing error states with `cin.clear()`
- Ignoring invalid input with `cin.ignore()`

### **8. Game Development Logic**
- Win condition detection (rows, columns, diagonals)
- Draw condition checking
- Turn-based gameplay implementation
- Score tracking across multiple sessions

#Sample Output

```
Welcome to Tic-Tac-Toe!

1. To Play the Game
2. To Help

-----> 1

        WELCOME TO TIC-TAC-TOE!

-Enter name for Player 1 [X]: Ali
-Enter name for Player 2 [O]: Sara

        LET'S START THE GAME!

        T I C   T A C   T O E   G A M E

        Alice [X] 
        Bob [O]

                 |           |           
           X     |     2     |    3      
                 |           |           
        ---------|-----------|----------
                 |           |           
           4     |     O     |     6     
                 |           |           
        ---------|-----------|----------
                 |           |           
           7     |     8     |     9     
                 |           |           
                 |           |           


        Alice [X] turn: 3

[Game continues...]

---> Alice won <---

     Congratulations!!!

---> Play Again? (Y/N): N

                THANKS for playing !

                ------------------------
                | <-- GAME RECORD -->  |
                ------------------------

Ali's Record:

        ------------------------------
        | >Total Wins:              1 |
        | >Total Points:           10 |
        | >Tie Games:               0 |
        ------------------------------

Sara's Record:

        ------------------------------
        | >Total Wins:              0 |
        | >Total Points:            0 |
        | >Tie Games:               0 |
        ------------------------------
```

---

#Future Improvements

Potential enhancements for future versions:

- [ ] **Cross-platform compatibility** - Replace `system("cls")` with portable screen clearing
- [ ] **AI opponent** - Implement single-player mode with computer opponent
- [ ] **Difficulty levels** - Add Easy, Medium, Hard AI strategies
- [ ] **Persistent data storage** - Save player records to file between sessions
- [ ] **Graphical interface** - Transition to GUI using Qt or SFML
- [ ] **Online multiplayer** - Network-based gameplay
- [ ] **Undo/Redo moves** - Allow players to revert moves
- [ ] **Larger board sizes** - Support 4×4, 5×5 grids
- [ ] **Sound effects** - Add audio feedback for moves and wins
- [ ] **Leaderboard system** - Global ranking of players
- [ ] **Game timer** - Add time limits per move or per game
- [ ] **Themes/Customization** - Different visual styles and color schemes

<div align="center">

###  If you found this project helpful, please consider giving it a star!

**Made with ❤️ and C++**

</div>
