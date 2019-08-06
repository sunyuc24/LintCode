
class Solution {
public:
    /**
     * @param str: An array of char
     * @param offset: An integer
     * @return: nothing
     */
    void rotateString(string &str, int offset) {
        // write your code here
        if (str.size() != 0){
        int nsize = str.size();
        int mod = offset % nsize;
        std::string str1, str2;
        str2 = str.substr(0, nsize-mod);
        str1 = str.substr(nsize-mod); 
        str = str1 + str2;
        }
    }
                    /*ANOTHER WAY*/
    // void rotateString(string &str, int offset) {
    //     // write your code here
    //     if (str.size() != 0){
    //     int nsize = str.size();
    //     int mod = offset % nsize;
    //     std::string str1, str2;
    //     for (int i =0; i < nsize-mod;i++){
    //         str2 += str[i];
    //     }
    //     for (int i = nsize-mod; i < nsize; i++){
    //         str1 += str[i]; 
    //     }
    //     str = str1 + str2;
    //     }
    // }
};
