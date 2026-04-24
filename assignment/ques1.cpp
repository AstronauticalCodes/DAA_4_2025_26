#include <iostream>
#include <vector>
#include <string>

using namespace std;

class NQueens {
public:
    int n;
    vector<vector<char>> board;
    int count = 0;

    vector<bool> col;
    vector<bool> diag1;
    vector<bool> diag2;

    void solve(int row) {
        if (row == n) {
            count++;
            printBoard();
            return;
        }

        for (int c = 0; c < n; c++) {
            if (!col[c] && !diag1[row - c + n - 1] && !diag2[row + c]) {
                board[row][c] = 'Q';
                col[c] = diag1[row - c + n - 1] = diag2[row + c] = true;

                solve(row + 1);

                board[row][c] = '.';
                col[c] = diag1[row - c + n - 1] = diag2[row + c] = false;
            }
        }
    }

    void printBoard() {
        cout << "Solution " << count << ":" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cout << "\nEnter size of board: ";
    if (!(cin >> n)) return 0;

    NQueens obj;
    obj.n = n;

    obj.board.assign(n, vector<char>(n, '.'));
    obj.col.assign(n, false);
    obj.diag1.assign(2 * n - 1, false);
    obj.diag2.assign(2 * n - 1, false);

    obj.solve(0);

    cout << "Total solutions: " << obj.count << endl;

    return 0;
}