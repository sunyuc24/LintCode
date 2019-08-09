class Solution {
public:
	/**
	* @param A: sorted integer array A
	* @param B: sorted integer array B
	* @return: A new sorted integer array
	*/
	vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
		// write your code here
		if (A.size() < B.size()){// let B be smaller one
			vector<int> temp = A;
			A = B;
			B = temp;
		}
		for (int i = 0; i < B.size(); i++){
			int left = 0, right = A.size() - 1;
			while (left + 1 < right){
				int mid = left + (right - left) / 2;
				if (B[i] < A[mid]){
					right = mid;
				}
				else{
					left = mid;
				}
			}
			if (B[i] < A[left]){
				A.insert(A.begin() + left, B[i]);
			}
			else if (B[i] > A[right]){
				A.insert(A.begin() + right + 1, B[i]);
			}
			else{
				A.insert(A.begin() + right, B[i]);
			}
		}
		return A;
	}
};