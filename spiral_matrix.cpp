class Solution {
public:
    
    vector<int> sequence;
    int visited[1000][1000];
    void generateSequence(int n, int x, int y, int direction){
        if(x >= n || x < 0 || y >= n || y < 0){
            return;
        }
        if(visited[x][y]){
           return; 
        }
        visited[x][y] = 1;
        sequence.push_back(x);
        sequence.push_back(y);
        //1 represent go  right, 2 represents go down, 3 represents go left, 4 represents go up
        if(direction == 1){
            generateSequence(n, x, y + 1, 1);
            generateSequence(n, x + 1, y, 2);
            generateSequence(n, x, y - 1, 3);
            generateSequence(n, x - 1, y, 4);
        }else
            if(direction == 2){
                generateSequence(n, x + 1, y, 2);
                generateSequence(n, x, y + 1, 1);
                generateSequence(n, x, y - 1, 3);
                generateSequence(n, x - 1, y, 4);
            }
        else
            if(direction == 3){
                generateSequence(n, x, y - 1, 3);
                generateSequence(n, x + 1, y, 2);
                generateSequence(n, x, y + 1, 1);
                generateSequence(n, x - 1, y, 4);
            }
        else
            if(direction == 4){
                generateSequence(n, x - 1, y, 4);
                generateSequence(n, x, y - 1, 3);
                generateSequence(n, x + 1, y, 2);
                generateSequence(n, x, y + 1, 1);
                
            }
       
    }

    vector<vector<int> > generateMatrix(int n) {
        sequence.clear();
        memset(visited, 0, sizeof(visited));
        generateSequence(n, 0, 0, 1);
        vector<vector<int> > result;
        for(int i = 0; i < n; ++i){
            result.push_back(*(new vector<int>()));
            for(int j = 0; j < n; ++j){
                result[i].push_back(j);
            }
        }
        int count = 0;
        for(int i = 0; i < sequence.size(); i += 2){
            result[sequence[i]][sequence[i + 1]] = ++count;
        }
        
        return result;
    }
};
