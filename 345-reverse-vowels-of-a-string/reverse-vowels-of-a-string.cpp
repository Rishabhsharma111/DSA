class Solution {
public:
    string reverseVowels(string s) {
        

        int left=0;
        int right =s.size()-1;
            
             while(left<right){
            if(s[left]!='a'&&s[left]!='e'&&s[left]!='i'&&s[left]!='u'&&s[left]!='o'&&s[left]!='A'&&s[left]!='E'&&s[left]!='I'&&s[left]!='O'&&s[left]!='U')
            {
                left++;
            }
            else if(s[right]!='a'&&s[right]!='e'&&s[right]!='i'&&s[right]!='u'&&s[right]!='o'&&s[right]!='A'&&s[right]!='E'&&s[right]!='I'&&s[right]!='O'&&s[right]!='U')
            {
                right--;
            }
            else
            {
                // This executes ONLY if:
                // left is a vowel
                // AND right is a vowel
                swap(s[left], s[right]);
                left++;
                right--;
            }
                }
                return s;
    }
};