class Solution {
public:
    bool detectCapitalUse(string word) {

        int upper=0;
        int lower=0;

        for(int i=0;i<word.size();i++){

            if(isupper(word[i])){
                upper++;
            }
            else{
                lower++;
            }


        }

        if(upper==word.size()){
            return true;
        }

        else if(lower==word.size()){
            return true;
        }

        else if(upper==1){
            if(isupper(word[0])){
                return true;
            }
        }

        return false;



        
    }
};