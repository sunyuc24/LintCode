class Solution {
public:
    /**
     * @param source: 
     * @param target: 
     * @return: return the index
     */
    int strStr(string &source, string &target) {
        // Write your code here
        int Tsize = target.size();
        int Ssize = source.size();
        int indx; 
        if (Tsize == 0){
            return 0;
        }
        if (Tsize > Ssize){
            return -1;
        }
        else {
            for (int i = 0; i < Ssize - Tsize + 1; i++){
                if (source[i] == target[0]){
                    indx = i;
                    if (source.substr(indx, Tsize) == target){
                        return indx;
                        break;
                    } 
                }
            }    
        }
        return -1;
    }
};

            /*KMP algorithm8, O(n) */
    
/*    int strStr(string &source, string &target) {
        // Write your code here
        int Tsize = target.size();
        int Ssize = source.size();
        if (Tsize == 0){
            return 0;
        }
        //got next[]
        int* pnext = new int [Tsize];
        pnext[0] = -1;
        int p = -1;
	    int s = 0;
	    while (s < Tsize - 1){
		    if (p == -1 || target[s] == target[p]){
		    	++p;
		    	++s;
		    	pnext[s] = p;
		    }
		    else {
			    p = pnext[p];
		    }
	    }
        
	    int i = 0;
    	int j = 0;
    	while (i < Ssize && j < Tsize){
		    if (j == -1 || source[i] == target[j]){
		    	i++;
		    	j++;
		    }
		    else{
		    	j = pnext[j];
	    	}
	    }
	    delete [] pnext;
	    if (j == Tsize)
		    return i - j;
	    else
	    	return -1;   
    }
*/