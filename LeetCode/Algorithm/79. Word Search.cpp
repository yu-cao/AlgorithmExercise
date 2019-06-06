//回溯剪枝+dfs
class Solution
{
public:
	bool exist(vector<vector<char>> &board, string word)
	{
		vector<vector<bool>> store;
		vector<bool> temp;
		for (int i = 0; i < board[0].size(); i++)
			temp.push_back(false);
		for (int i = 0; i < board.size(); i++)
			store.push_back(temp);

		if (word.length() == 0) return false;
		char begin = word[0];
		word.erase(word.begin());
		bool flag = false;
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[i].size(); j++)
			{
				if (begin == board[i][j])
				{
					store[i][j] = true;
					flag = check(board, store, i, j, word);
					if (flag) return flag;
					else store[i][j] = false;
				}
			}
		}
		return flag;
	}

	bool check(vector<vector<char>> &board, vector<vector<bool>> &used, int hang, int lie, string word)
	{
		if (word.empty()) return true;
		char ch = word[0];
		word.erase(word.begin());
		bool flag = false;
		if (hang > 0 && board[hang - 1][lie] == ch)
		{
			if (!used[hang - 1][lie])
			{
				used[hang - 1][lie] = true;
				flag = check(board, used, hang - 1, lie, word);
				if (flag) return flag;
				else used[hang - 1][lie] = false;
			}
		}
		if (hang < board.size() - 1 && board[hang + 1][lie] == ch)
		{
			if (!used[hang + 1][lie])
			{
				used[hang + 1][lie] = true;
				flag = check(board, used, hang + 1, lie, word);
				if (flag) return flag;
				else used[hang + 1][lie] = false;
			}

		}
		if (lie > 0 && board[hang][lie - 1] == ch)
		{
			if (!used[hang][lie - 1])
			{
				used[hang][lie - 1] = true;
				flag = check(board, used, hang, lie - 1, word);
				if (flag) return flag;
				else used[hang][lie - 1] = false;
			}
		}
		if (lie < board[0].size() - 1 && board[hang][lie + 1] == ch)
		{
			if (!used[hang][lie + 1])
			{
				used[hang][lie + 1] = true;
				flag = check(board, used, hang, lie + 1, word);
				if (flag) return flag;
				else used[hang][lie + 1] = false;
			}
		}
		return flag;
	}
};

//优化策略，used部分用*直接在原来的board上替换即可，同时可以合写dfs
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return true;
        if (board.empty() || board[0].empty()) return false;
        
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                // traverse the board to find the first char
                if (dfsSearch(board, word, 0, i, j)) return true;
        return false;
    }
private:
    int m;
    int n;
    bool dfsSearch(vector<vector<char>>& board, string& word, int k, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || word[k] != board[i][j]) return false;
        if (k == word.length() - 1) return true;  // found the last char

        char cur = board[i][j];
        board[i][j] = '*';  // used
        bool search_next = dfsSearch(board, word, k+1, i-1 ,j) 
                        || dfsSearch(board, word, k+1, i+1, j) 
                        || dfsSearch(board, word, k+1, i, j-1)
                        || dfsSearch(board, word, k+1, i, j+1);
        board[i][j] = cur;  // reset
        return search_next;
    }
};