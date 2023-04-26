class Solution {
public:
    int sumofDigit(int num){
        int sum=0;
        while(num){
            int rem = num%10;
            sum += rem;
            num = num/10;
        }
        return sum;
    }
    int addDigits(int num) {
        while(num>=10){
           
            num = sumofDigit(num);
        }
        return num;
    }
};