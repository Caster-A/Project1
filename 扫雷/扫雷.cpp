/*2451454 电信 杨翰卓*/
#include <iostream>
#include <cstdlib>

using namespace std;

const int ROWS = 10;
const int COLS = 26;
const int MINES = 50;  // 设定地雷数量

void initializeBoard(char board[ROWS][COLS], bool mines[ROWS][COLS]) {
    // 初始化棋盘和地雷位置
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            board[i][j] = '0';
            mines[i][j] = false;
        }
    }

    // 固定种子，不使用 ctime
    srand(time(0));  // 这里的 42 是任意的种子值，可以更改

    int placedMines = 0;
    while (placedMines < MINES) {
        int x = rand() % ROWS;
        int y = rand() % COLS;
        if (!mines[x][y]) {
            mines[x][y] = true;
            board[x][y] = '*';  // 使用 '*' 代表地雷
            placedMines++;
        }
    }
}

void calculateNumbers(char board[ROWS][COLS], bool mines[ROWS][COLS]) {
    // 计算周围地雷数
    int dx[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
    int dy[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (mines[i][j]) continue;

            int count = 0;
            for (int k = 0; k < 8; ++k) {
                int ni = i + dx[k], nj = j + dy[k];
                if (ni >= 0 && ni < ROWS && nj >= 0 && nj < COLS && mines[ni][nj]) {
                    count++;
                }
            }
            board[i][j] = count + '0';  // 转换为字符
        }
    }
}

void printBoard(char board[ROWS][COLS]) {
    // 打印棋盘
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    char board[ROWS][COLS];
    bool mines[ROWS][COLS];

    initializeBoard(board, mines);
    calculateNumbers(board, mines);
    printBoard(board);

    return 0;
}