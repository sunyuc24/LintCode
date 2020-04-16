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
	int x, y;  //����
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
	int nBack = 0, nCheak = 0, nSolu = 0; //���ݴ�������̽������N�ʺ�����
	stack<queen> solu;
	queen q(0, 0);

	while (q.x > 0 || q.y < N){
		if (N <= solu.size() || q.y >= N){ //�ж��Ƿ������ѻ��ȫ�ֽ�
			//����, ��̽��һ��
			q = solu.top(); solu.pop();
			q.y++; nCheak++; nBack++;
		}
		else{
			while ((q.y < N) && (!canPlace(q, solu))){ //Ѱ����һ���ɷ��õ���
				q.y++; nCheak++;
			}
			if (q.y < N){ //���ڿɷ��õĵ�
				solu.push(q);
				if (N <= solu.size()){ //�ҵ�ȫ�ֽ�
					nSolu++;
					cout << "  ";
					cout << nSolu << "th solution(s), "
						<< nBack << " backs, "
						<< nCheak << " cheaks.\n";
					printSolu(N, solu);

				}
				q.x++; q.y = 0; nCheak++; //������һ��,�ӵ�0�п�ʼ
			}
		}
	}
	if (!nSolu)
		cout << "no solution";
}

bool helper(stack<queen>& solu, queen q, int& N){
	if (N <= solu.size()){  //�ҵ�ȫ�ֽ�
		printSolu(N, solu);
		return false;
	}

	while (q.y < N && !canPlace(q, solu)){ //��̽��һ��
		q.y++;
	}
	if (q.y < N){ //�ҵ��˿��Է��õ���һ��
		queen temp(q.x + 1, 0);    //������һ��, �ӵ�0�п�ʼ
		while (q.y < N){
			solu.push(q); //��ջ
			if (helper(solu, temp, N)){
				return true;
			}
			else{
				solu.pop();
				do{ //��̽��һ��
					q.y++;
				} while (q.y < N && !canPlace(q, solu));
			}
		}
		
	}
	//����
	return false;
}
 #endif
