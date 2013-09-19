class Solution {
public:
		void solve(vector<vector<char> > &board){
		    int height = board.size();
		    if(height == 0){
		        return;
		    }
			int width = board[0].size();
            if(width == 0){
                return;
            }
			const char c = 'k';
			for(int i = 0;i < width; ++i){
				if(board[0][i] == 'O'){
					fillRegion(board, c, 0, i);
				}
				if(board[height - 1][i] == 'O'){
					fillRegion(board, c, height - 1, i);
				}
			}

			for(int i = 0; i < height; ++i){
				if(board[i][0] == 'O'){
					fillRegion(board, c, i, 0);
				}
				if(board[i][width - 1] == 'O'){
					fillRegion(board, c, i, width - 1);
				}
			}


            for(int i = 0; i < height; ++i){
                for(int j = 0; j < width; ++j){
                    if(board[i][j] == 'O'){
                        board[i][j] = 'X';
                    }  
                }
            }

			for(int i = 0; i < height; ++i){
				for(int j = 0; j < width; ++j){
					if(board[i][j] == c){
						board[i][j] = 'O';
					}
                   
				}
			}	
		}

		void fillRegion(vector<vector<char> > &board, char c, int x, int y){
			if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size()){
				return;
			}
			if(board[x][y] == 'O'){
				board[x][y] = c;
				fillRegion(board, c, x - 1, y);
				fillRegion(board, c, x , y - 1);
				fillRegion(board, c, x + 1 , y);
				fillRegion(board, c, x , y + 1);
			}
		}
};