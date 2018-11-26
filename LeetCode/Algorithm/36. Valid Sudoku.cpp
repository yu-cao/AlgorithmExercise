class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int test[10] = {0};
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] >= '0' && board[i][j] <= '9')
                {
                    test[board[i][j] - '0']++;
                    if (test[board[i][j] - '0'] > 1) return false;
                }
            }
            memset(test, 0, sizeof(int) * 10);
        }
        for (int j = 0; j < 9; j++)
        {
            for (int i = 0; i < 9; i++)
            {
                if (board[i][j] >= '0' && board[i][j] <= '9')
                {
                    test[board[i][j] - '0']++;
                    if (test[board[i][j] - '0'] > 1)return false;
                }
            }
            memset(test, 0, sizeof(int) * 10);
        }
        for (int count = 0; count < 3; count++)
        {
            for (int i = count * 3; i < (count + 1) * 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (board[i][j] >= '0' && board[i][j] <= '9')
                    {
                        test[board[i][j] - '0']++;
                        if (test[board[i][j] - '0'] > 1)return false;
                    }
                }
            }
            memset(test, 0, sizeof(int) * 10);
        }
        for (int count = 0; count < 3; count++)
        {
            for (int i = count * 3; i < (count + 1) * 3; i++)
            {
                for (int j = 3; j < 6; j++)
                {
                    if (board[i][j] >= '0' && board[i][j] <= '9')
                    {
                        test[board[i][j] - '0']++;
                        if (test[board[i][j] - '0'] > 1)return false;
                    }
                }
            }
            memset(test, 0, sizeof(int) * 10);
        }
        for (int count = 0; count < 3; count++)
        {
            for (int i = count * 3; i < (count + 1) * 3; i++)
            {
                for (int j = 6; j < 9; j++)
                {
                    if (board[i][j] >= '0' && board[i][j] <= '9')
                    {
                        test[board[i][j] - '0']++;
                        if (test[board[i][j] - '0'] > 1)return false;
                    }
                }
            }
            memset(test, 0, sizeof(int) * 10);
        }
        return true;
    }
};