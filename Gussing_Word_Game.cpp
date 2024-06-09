#include <iostream>
#include <windows.h>
#include <cstring>
#include <conio.h>
#include <cstdlib>
#include <ctime> // Include for seeding random number generator

using namespace std;

// Function declarations
void display();
int GameFunction();

int main()
{
    // Seed random number generator
    srand(time(0));

    string name;
    cout << "Enter input name: ";
    getline(cin, name);
    cout << endl;

    int score = 0;
    char input;

    do
    {
        // Clear screen
        system("cls");
        display();
        score = score + GameFunction();
        cout << "Would you like to play again y/n: ";
        cin >> input;
        cout << endl;
    } while (input != 'n');

    cout << name << ", your score is: " << score;
    cout << endl << endl << endl;
    cout << "***************************************************" << endl;

    return 0;
}

void display()
{
    cout << "************************Word Searching Puzzle Game********************************" << endl;
    cout << "A puzzle of words alphabet is shown on screen. You have to guess a hidden correct " << endl;
    cout << "word from the puzzle. For each correct guess you will get one score." << endl << endl << endl;
}

int GameFunction()
{
    string array[10] = { "Java", "C++", "Python", "Scala", "Php", "Html", "Css", "Kotlin", "hello", "Hyee" };
    char matrix[10][10];
    int r;
    char c;

    // Fill the matrix with random alphabets
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            r = rand() % 26;
            c = 'a' + r;
            matrix[i][j] = c;
        }
    }

    // Select a random word from the array
    int index = rand() % 10;
    string output = array[index];

    // Insert the word into the matrix
    if (array[index].length() % 2 == 0)
    {
        int row = rand() % 10;
        int col = rand() % 3;
        for (int i = 0; array[index][i] != '\0'; i++, col++)
        {
            matrix[row][col] = array[index][i];
        }
    }
    else
    {
        int row = rand() % 3;
        int col = rand() % 10;
        for (int i = 0; array[index][i] != '\0'; i++, row++)
        {
            matrix[row][col] = array[index][i];
        }
    }

    // Display the matrix with spaces between characters
    cout << "      Puzzle  " << endl << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << matrix[i][j] << ' '; // Add space between characters
            Sleep(100);
        }
        cout << "\n";
    }
    cout << "\n\n";

    string guess;
    int hint;
    cout << "Press 1 for direct guess input" << endl;
    cout << "Press 2 to first see hint and then enter guess input" << endl;

    a:
    cout << "Enter input: ";
    cin >> hint;
    cout << endl;

    if (hint == 1)
    {
        cout << "Enter guessing word: ";
        cin >> guess;
        cout << endl;
    }
    else if (hint == 2)
    {
        cout << "The guessing word size is " << output.length() << endl;
        cout << "Enter guessing word: ";
        cin >> guess;
        cout << endl;
    }
    else
    {
        cout << "Enter valid input" << endl;
        goto a;
    }

    if (output == guess)
    {
        cout << "Congratulations! You guessed the right word in the puzzle" << endl;
        return 1;
    }
    else
    {
        cout << "Sorry, you guessed the wrong word" << endl;
        return 0;
    }
}
