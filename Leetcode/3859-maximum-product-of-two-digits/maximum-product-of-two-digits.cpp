class Solution {
public:
    int maxProduct(int n) {
        
        int max1=INT_MIN;
        int max2=INT_MIN;


        while(n>0){

            int a=n%10;
            n=n/10;
            if(a>max1){
                
                max2=max1;
                max1=a;
            }
            else if(a>max2){

                max2=a;
            }
        }

        int b=(max1*max2);
        return min(81,b);
    }
};