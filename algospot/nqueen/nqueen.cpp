#include <iostream>
#include <vector>

//#define DEBUG
//#define DEBUG_S
//#define DEBUG_MARK

using namespace std;

void print_chess(int n, vector<vector<int>> chess)
{
    for(int i {0}; i < n; i++)
    {
        for(int j {0}; j < n; j++)
        {
            cout << chess[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

vector<vector<int>> make_mark(int n,
               int row, 
               int col, 
               vector<vector<int>>& input, 
               int mark = 1)
{
    vector<vector<int>> chess = input;
    chess[row][col] = mark;

    // Row, Column
    for(int i = 0; i < n; i++)
    {
        chess[row][i] = mark;
        chess[i][col] = mark;
    }

    // 대각선
    for(int row_idx {row}, col_idx {col}; 
        row_idx < n; 
        row_idx++, col_idx++)
    {
        if(col_idx >= n)
            break;
        chess[row_idx][col_idx] = mark;
    }

#if 0
    for(int row_idx {row}, col_idx {col}; 
        row_idx >= 0; 
        row_idx--, col_idx--)
    {
        if(col_idx < 0)
            break;
        chess[row_idx][col_idx] = mark;
    }
#endif

#ifdef DEBUG_MARK
    if(row == 0 && col == 0)
        print_chess(n, chess);
#endif

#if 0
    // 나머지 대각선
    for(int row_idx {row}, col_idx {col}; 
        row_idx < n; 
        row_idx++, col_idx--)
    {
        if(col_idx < 0)
            break;
        chess[row_idx][col_idx] = mark;
    }
#endif

#ifdef DEBUG_MARK
    if(row == 0 && col == 0)
        print_chess(n, chess);
#endif

    for(int row_idx {row}, col_idx {col}; 
        row_idx >= 0; 
        row_idx--, col_idx++)
    {
        if(col_idx >= n)
            break;
        chess[row_idx][col_idx] = mark;
    }

#ifdef DEBUG_MARK
    if(row == 0 && col == 0)
        print_chess(n, chess);
#endif

    return chess;
}

int nqueen_start(int n, int col, vector<vector<int>>& input)
{
    vector<vector<int>> chess = input;
    int count {0};
    bool isEmpty {false};

    if(col == n)
    {
        return 1;
    }

    // Empty Space Checking
    for(int i {0}; i < n; i++)
    {
        if(chess[i][col] == 0)
        {
            isEmpty = true;
            break;
        }
    }

    if(!isEmpty)
        return 0;

    // 지금 행에 비어있는 자리가 하나라도 있으면 Nqueen 탐색 계속
    for(int i {0}; i < n; i++)
    {
        if(chess[i][col] == 0)
        {
            vector<vector<int>> next =
            make_mark(n, i, col, chess);
            count += nqueen_start(n, col + 1, next);
#ifdef DEBUG
            if(col == 0)
                cout << "chess[0][" << i << "] : " << count << endl;
#endif
        }
    }

    return count;
}

int main()
{
    int nr_sample;
    cin >> nr_sample;

    for(int i {0}; i < nr_sample; i++)
    {
        int n;
        cin >> n;
        vector<vector<int>> chessfield;
        chessfield.resize(n, vector<int>(n, 0));
        cout << nqueen_start(n, 0, chessfield) << endl;
    }

    return 0;
}
