class Solution {
public:
    int countCommas(int n) {
        int commas=0;
        int no;
        if(no<1000){
            return -1;
        }
        for(no=1000;no<=n;no++){
            commas++;
        }
        return commas;
    }
};