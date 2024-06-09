#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

// Function declarations
void displayMenu();
void drawLine(vector<vector<char>>& canvas, int x1, int y1, int x2, int y2, char ch);
void drawRectangle(vector<vector<char>>& canvas, int x1, int y1, int x2, int y2, char ch);
void drawCircle(vector<vector<char>>& canvas, int xc, int yc, int r, char ch);
void displayCanvas(const vector<vector<char>>& canvas);

int main() {
    const int width = 50;
    const int height = 20;
    vector<vector<char>> canvas(height, vector<char>(width, ' '));

    char choice;
    do {
        system("cls"); // Clear the screen
        displayCanvas(canvas);
        displayMenu();
        cin >> choice;

        switch (choice) {
            case '1': {
                int x1, y1, x2, y2;
                char ch;
                cout << "Enter start point (x1 y1): ";
                cin >> x1 >> y1;
                cout << "Enter end point (x2 y2): ";
                cin >> x2 >> y2;
                cout << "Enter character to draw with: ";
                cin >> ch;
                drawLine(canvas, x1, y1, x2, y2, ch);
                break;
            }
            case '2': {
                int x1, y1, x2, y2;
                char ch;
                cout << "Enter top-left corner (x1 y1): ";
                cin >> x1 >> y1;
                cout << "Enter bottom-right corner (x2 y2): ";
                cin >> x2 >> y2;
                cout << "Enter character to draw with: ";
                cin >> ch;
                drawRectangle(canvas, x1, y1, x2, y2, ch);
                break;
            }
            case '3': {
                int xc, yc, r;
                char ch;
                cout << "Enter center (xc yc): ";
                cin >> xc >> yc;
                cout << "Enter radius: ";
                cin >> r;
                cout << "Enter character to draw with: ";
                cin >> ch;
                drawCircle(canvas, xc, yc, r, ch);
                break;
            }
            case 'q':
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 'q');

    return 0;
}

void displayMenu() {
    cout << "Simple Drawing Program" << endl;
    cout << "1. Draw Line" << endl;
    cout << "2. Draw Rectangle" << endl;
    cout << "3. Draw Circle" << endl;
    cout << "q. Quit" << endl;
    cout << "Enter your choice: ";
}

void drawLine(vector<vector<char>>& canvas, int x1, int y1, int x2, int y2, char ch) {
    int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
    int dy = -abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
    int err = dx + dy, e2;

    while (true) {
        if (x1 >= 0 && x1 < canvas[0].size() && y1 >= 0 && y1 < canvas.size()) {
            canvas[y1][x1] = ch;
        }
        if (x1 == x2 && y1 == y2) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x1 += sx; }
        if (e2 <= dx) { err += dx; y1 += sy; }
    }
}

void drawRectangle(vector<vector<char>>& canvas, int x1, int y1, int x2, int y2, char ch) {
    for (int x = x1; x <= x2; ++x) {
        if (y1 >= 0 && y1 < canvas.size() && x >= 0 && x < canvas[0].size()) {
            canvas[y1][x] = ch;
        }
        if (y2 >= 0 && y2 < canvas.size() && x >= 0 && x < canvas[0].size()) {
            canvas[y2][x] = ch;
        }
    }
    for (int y = y1; y <= y2; ++y) {
        if (x1 >= 0 && x1 < canvas[0].size() && y >= 0 && y < canvas.size()) {
            canvas[y][x1] = ch;
        }
        if (x2 >= 0 && x2 < canvas[0].size() && y >= 0 && y < canvas.size()) {
            canvas[y][x2] = ch;
        }
    }
}

void drawCircle(vector<vector<char>>& canvas, int xc, int yc, int r, char ch) {
    int x = 0, y = r;
    int d = 3 - 2 * r;
    while (y >= x) {
        if (xc + x >= 0 && xc + x < canvas[0].size() && yc + y >= 0 && yc + y < canvas.size()) canvas[yc + y][xc + x] = ch;
        if (xc - x >= 0 && xc - x < canvas[0].size() && yc + y >= 0 && yc + y < canvas.size()) canvas[yc + y][xc - x] = ch;
        if (xc + x >= 0 && xc + x < canvas[0].size() && yc - y >= 0 && yc - y < canvas.size()) canvas[yc - y][xc + x] = ch;
        if (xc - x >= 0 && xc - x < canvas[0].size() && yc - y >= 0 && yc - y < canvas.size()) canvas[yc - y][xc - x] = ch;
        if (xc + y >= 0 && xc + y < canvas[0].size() && yc + x >= 0 && yc + x < canvas.size()) canvas[yc + x][xc + y] = ch;
        if (xc - y >= 0 && xc - y < canvas[0].size() && yc + x >= 0 && yc + x < canvas.size()) canvas[yc + x][xc - y] = ch;
        if (xc + y >= 0 && xc + y < canvas[0].size() && yc - x >= 0 && yc - x < canvas.size()) canvas[yc - x][xc + y] = ch;
        if (xc - y >= 0 && xc - y < canvas[0].size() && yc - x >= 0 && yc - x < canvas.size()) canvas[yc - x][xc - y] = ch;
        if (d < 0) {
            d = d + 4 * x + 6;
        } else {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

void displayCanvas(const vector<vector<char>>& canvas) {
    for (const auto& row : canvas) {
        for (const auto& ch : row) {
            cout << ch << ' ';
        }
        cout << '\n';
    }
}
