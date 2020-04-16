#ifndef _NQUEENS_H_
#define _NQUEENS_H_

#include <iostream>
#include <stack>
using std::cout;
using std::stack;
using std::endl;
	
struct queen
{
	/*********************
		+ # + # +
		# + + + #
		+ + + + +
		# + + + #
		+ # + # + 
	********************/
	int x, y;  //坐标
	queen(int xx = -1, int yy = -1) : x(xx), y(yy) {};
	bool operator == (queen const& q) const{
		return	(x == q.x)
			|| (y == q.y)
			|| (x + y == q.x + q.y)
			|| (x - y == q.x - q.y);
	}
	bool operator != (queen const& q) const{
		return !(*this == q);
	}
};

void printSolu(int N, stack<queen> S){
	queen q;
	for (int i = N - 1; i >= 0; i--){
		q = S.top();
		cout << "    ";
		for (int j = 0; j < N; j++){
			if (j == q.y && i == q.x)
				cout << "+ ";
			else
				cout << "# ";
		}
		S.pop();
		cout << endl;
	}
	cout << endl;
}

bool canPlace(queen& Q, stack<queen> S){
	while (!S.empty()){
		if (Q == S.top())
			return false;
		S.pop();
	}
	return true;
}

void nQueens(int N){
	int nBack = 0, nCheak = 0, nSolu = 0; //回溯次数，试探次数，N皇后解个数
	stack<queen> solu;
	queen q(0, 0);

	while (q.x > 0 || q.y < N){
		if (N <= solu.size() || q.y >= N){ //判断是否出界或已获得全局解
			//回溯, 试探下一列
			q = solu.top(); solu.pop();
			q.y++; nCheak++; nBack++;
		}
		else{
			while ((q.y < N) && (!canPlace(q, solu))){ //寻找下一个可放置的列
				q.y++; nCheak++;
			}
			if (q.y < N){ //存在可放置的点
				solu.push(q);
				if (N <= solu.size()){ //找到全局解
					nSolu++;
					cout << "  ";
					cout << nSolu << "th solution(s), "
						<< nBack << " backs, "
						<< nCheak << " cheaks.\n";
					printSolu(N, solu);

				}
				q.x++; q.y = 0; nCheak++; //进入下一行,从第0列开始
			}
		}
	}
	if (!nSolu)
		cout << "no solution";
}

bool helper(stack<queen>& solu, queen q, int& N){
	if (N <= solu.size()){  //找到全局解
		printSolu(N, solu);
		return false;
	}

	while (q.y < N && !canPlace(q, solu)){ //试探下一列
		q.y++;
	}
	if (q.y < N){ //找到了可以放置的下一列
		queen temp(q.x + 1, 0);    //进入下一行, 从第0列开始
		while (q.y < N){
			solu.push(q); //入栈
			if (helper(solu, temp, N)){
				return true;
			}
			else{
				solu.pop();
				do{ //试探下一列
					q.y++;
				} while (q.y < N && !canPlace(q, solu));
			}
		}
		
	}
	//回溯
	return false;
}
 #endif
