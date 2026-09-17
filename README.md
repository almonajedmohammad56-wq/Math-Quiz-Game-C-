🧮 Math Quiz Game (C++)
An interactive, terminal-based math quiz application built using C++. This project is designed to test and improve arithmetic skills with customizable difficulty levels, operations, and detailed performance tracking.

✨ Features
Customizable Questions: Choose the number of questions per quiz session.

Difficulty Levels: Select from Easy, Medium, Hard, or a Mixed mode with varying number ranges.

Operation Types: Practice Addition, Subtraction, Multiplication, Division, or choose a Mixed operations mode.

Dynamic Feedback: Real-time console color changes and audio alerts for correct (Green) and wrong (Red) answers.

Comprehensive Results: Displays final pass/fail status, total questions, correct/wrong answers breakdown, and selected settings at the end of the game.

Replayability: Option to restart and play multiple rounds seamlessly.

🛠️ Concepts & Technical Skills Applied
Structured Programming: Clean separation of logic using modular functions.

Data Structures: Utilized custom struct definitions (stQuestion, stQuiz) to manage question lists, player inputs, and game states efficiently.

User-Defined Types: Used enum (enLevelQuestion, enTypeOperator, enResult) for clean state management and readability.

Randomization: Utilized srand() and time() for dynamic question and mix-mode generation.

CLI UX/UI Enhancement: Implemented system commands (system("color"), system("cls")) for visual feedback and screen control.

💻 How to Run
Clone the repository or download the source code.

Open the file in any C++ IDE (such as Visual Studio).

Compile and run the main.cpp file.
