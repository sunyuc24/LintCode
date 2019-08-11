class Solution {
public:
    /**
     * @param n: An integer
     * @return: A list of strings.
     */
    vector<string> fizzBuzz(int n) {
        // write your code here
        vector<string> vstr;
	    string str;
	    for (int i = 1; i < n + 1; i++){
		    while (!(i % 3) || !(i % 5)){
			    while (!(i % 15)){
				    vstr.push_back("fizz buzz");
				    i += 1;
				    break;
			    }
			    while (!(i % 3)){
				    vstr.push_back("fizz");
				    i += 1;
				    break;
			    }
			    while (!(i % 5)){
				    vstr.push_back("buzz");
				    i += 1;
				    break;
			    }
		    }
		str = to_string(i);
		vstr.push_back(str);
	}
	while (vstr.size() > n){
		vstr.pop_back();
	}
	return vstr;
    }
};