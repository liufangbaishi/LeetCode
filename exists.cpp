#include <vector>
using namespace std;
//  矩阵中的路径

bool hasPath(vector<vector<char>> board, string word, int i, int j, int row, int col, int &index, vector<vector<bool>>& visited)
{
	if (word[index] == '\0')
		return true;
	bool ret = false;
	if (i >= 0 && i < row && j >= 0 && j < col && board[i][j] == word[index] && !visited[i][j])
	{
		++index;
		visited[i][j] = true;
		ret = hasPath(board, word, i, j - 1, row, col, index, visited)
			|| hasPath(board, word, i - 1, j, row, col, index, visited)
			|| hasPath(board, word, i + 1, j, row, col, index, visited)
			|| hasPath(board, word, i, j + 1, row, col, index, visited);
		if (!ret)
		{
			--index;
			visited[i][j] = false;
		}
	}
	return ret;
}

bool exist(vector<vector<char> > &board, string word) {
	if (board.size() == 0 || board[0].size() == 0||word.size()==0)
		return false;
	int row = board.size();
	int col = board[0].size();
	vector<vector<bool>> visited(row, vector<bool>(col, false));
	int index = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (hasPath(board, word, i, j, row, col, index, visited))
				return true;
		}
	}
	return false;
}

int main()
{
	vector<vector<char>> v;
	v.resize(3);
	string s[3] = { "ABCE", "SFCS", "ADEE" };
	for (int i = 0; i < 3; i++)
		v[i].resize(4);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			v[i][j] = s[i][j];
		}
	}
	string word = "ABCCED";
	int ret = exist(v, word);
	return 0;
 }