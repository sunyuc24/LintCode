    int dire[4][4] = {{0,-1}, {1, 0}, {0, 1}, {-1, 0}};//四个方向
    struct node{
        int x;  //坐标
        int y;  //坐标
        int d;  //方向
        node(int xx = -1, int yy = -1, int dd = -1): x(xx), y(yy), d(dd){};
    };


//BFS 迭代版：
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty())
			return 0;

		int nums = 0;  // the number of islands
		int row = grid.size(), col = grid[0].size();
		int new_x, new_y;
		//BFS
		for (int x = 0; x < row; x++){
			for (int y = 0; y < col; y++){
				queue<node*> Q;   //BFS, make use of queue to storge coordinate
				if (grid[x][y] == '1'){
					nums++; Q.push(new node(x, y )); grid[x][y] = '0';
					while(!Q.empty()){
						node* pfront = Q.front(); Q.pop();
						for (int direct = 0; direct < 4; direct++){ 
							// BFS, four directions
							new_x = pfront->x + dire[direct][0];
							new_y = pfront->y + dire[direct][1];
							if (new_x >= 0 && new_x < row && new_y >= 0 && new_y < col 
								&& grid[new_x][new_y] == '1'){
									Q.push(new node(new_x, new_y));
									grid[new_x][new_y] = '0';
							}
						}
						delete pfront;
					}
				}
			}
		}
		return nums;
	}
	
//BFS 递归版：
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty())
			return 0;
		int row = grid.size(), col = grid[0].size(); int nums = 0; // the number of islands
		queue<Node*> Q;

		for (int x = 0; x < row; x++){
			for (int y = 0; y < col; y++){
				if (grid[x][y] == '1'){
					nums++;
					grid[x][y] = '0';
					Q.push(new Node(x, y));
					helper(grid, Q);
				}
			}
		}
		return nums;
	}

	void helper(vector<vector<char>>& grid, queue<Node*>& Q){ //DFS
		if (Q.empty())
			return;
		
		Node* pPos = Q.front(); Q.pop();
		int row = grid.size(), col = grid[0].size();
		int x = pPos->x, y = pPos->y;
		int new_x, new_y;

		for (int i = 0; i < 4; i++){// DFS, four directions
			new_x = x + dire[i][0];
			new_y = y + dire[i][1];
			if (new_x >= 0 && new_x < row && new_y >= 0 && new_y < col 
			 && grid[new_x][new_y] == '1'){   
				Q.push(new Node(new_x, new_y));
				grid[new_x][new_y] = '0';
			} 
		}
		helper(grid, Q);
		delete pPos;
	}



//DFS 迭代版：
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty())
			return 0;
		
		int nums = 0;  // the number of islands
		row = grid.size(); col = grid[0].size();
		//DFS
		stack<node*> S; // make use of queue to storge coordinate
		for (int x = 0; x < row; x++){
			for (int y = 0; y < col; y++){
				if (grid[x][y] == '1'){
					nums++;
					S.push(new node(x, y, 0)); grid[x][y] = '0';
					int new_x, new_y, direct; node* pfront;
					while(!S.empty()){
						pfront = S.top();
						direct = pfront->d;
						if (direct == 4){ // back
							S.pop(); delete pfront;
						}
						else {
						// DFS, four directions
							new_x = pfront->x + dire[direct][0]; 
								 new_y = pfront->y + dire[direct][1];
							
							if (new_x >= 0 && new_x < row && new_y >= 0 && new_y < col 
							&& grid[new_x][new_y] == '1'){
								S.push(new node(new_x, new_y, 0)); 
								 grid[new_x][new_y] = '0';
							}
							pfront->d++;
						}
					}
				}
			}
		}
		return nums;
	}

//DFS 递归版：
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty())
			return 0;
		int dire[4][4] = {{0,-1}, {1, 0}, {0, 1}, {-1, 0}}; //方向
		int row = grid.size(), col = grid[0].size();
		int nums = 0;  // the number of islands
		for (int x = 0; x < row; x++){
			for (int y = 0; y < col; y++){
				if (grid[x][y] == '1'){
					helper(x, y, grid, dire);  // DFS
					nums++;
				}
			}
		}
		return nums;
	}

	void helper(int x, int y, vector<vector<char>>& grid, int (*dire)[4]){ //DFS
		int row = grid.size(), col = grid[0].size();

		grid[x][y] = '0';
		int new_x, new_y;
		for (int i = 0; i < 4; i++){// DFS, four directions
			new_x = x + dire[i][0];
			new_y = y + dire[i][1];
			if (new_x >= 0 && new_x < row && new_y >= 0 
				 && new_y < col && grid[new_x][new_y] == '1')
				helper(new_x, new_y, grid, dire);
		}
	}
