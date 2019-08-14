class Solution {
public:
    /*
     * @param n: A long integer
     * @return: An integer, denote the number of trailing zeros in n!
     */
    long long trailingZeros(long long n) {
        // write your code here, try to do it without arithmetic operators.
        long long count = 0, aa = 5;
        do{
            count += n / aa;
        }while ((aa *= 5) <= n);
        
        return count;
    }
};