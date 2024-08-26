#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

const int NUM_STUDENTS = 3; // numner of students
const int NUM_QUIZZES = 4;  //number of quizzes

// to read quiz grades for each student
void readScores(int scores[][NUM_QUIZZES]) {
    cout << "**ENTER GRADE FOR EACH STUDENT**" << endl;
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        cout << "Student " << (i + 1) << " " << endl;  //Tells you the student by number
        for (int j = 0; j < NUM_QUIZZES; ++j) {
            cout << "Quiz " << (j + 1) << ": ";
            cin >> scores[i][j];
        }
    }
}

// to compute the average grade for each student and the average grade for each quiz
void computeAverages(int scores[][NUM_QUIZZES], double studentAvg[], double quizAvg[]) {
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        double sum = 0;
        for (int j = 0; j < NUM_QUIZZES; ++j) {
            sum += scores[i][j]; // Calculate the sum of quiz grade
            quizAvg[j] += scores[i][j]; // grades for each quiz to compute quiz average later
        }
        studentAvg[i] = sum / NUM_QUIZZES; // Compute average grade for the current student
    }
    for (int j = 0; j < NUM_QUIZZES; ++j) {
        quizAvg[j] /= NUM_STUDENTS; // Compute average grade for each quiz
    }
}

// Function to display quiz grade and averages
void displayScores(int scores[][NUM_QUIZZES], double studentAvg[], double quizAvg[]) {
    cout << "\nQuiz Scores:\n";
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        cout << "Student " << (i + 1) << ": ";
        for (int j = 0; j < NUM_QUIZZES; ++j) {
            cout << setw(4) << scores[i][j]; // Display quiz grades
        }
        cout << "   Average: " << studentAvg[i] << endl; // Display the average grades
    }
    
    cout << "\nQuiz Averages:\n";
    for (int j = 0; j < NUM_QUIZZES; ++j) {
        cout << "Quiz " << (j + 1) << " average: " << quizAvg[j] << endl; // Display average grade for each quiz
    }
}

int main() {
    int scores[NUM_STUDENTS][NUM_QUIZZES];
    double studentAvg[NUM_STUDENTS] = {0};
    double quizAvg[NUM_QUIZZES] = {0};
    
    readScores(scores); // function to read quiz grades
    computeAverages(scores, studentAvg, quizAvg); // Call function to compute average grades
    displayScores(scores, studentAvg, quizAvg); // Call function to display scores and grades
    
    return 0;
}
