class Solution {
public:
    string toGoatLatin(string sentence) {

        string ans;
        stringstream ss(sentence);
        string word;
            int count=1;
        while(ss>>word )
        {char first = word[0];

            if(word[0]=='a'||word[0]=='e'||word[0]=='i'||word[0]=='o'||word[0]=='u'||word[0]=='A'||word[0]=='E'||word[0]=='I'||word[0]=='O'||word[0]=='U'){

                word+="ma";
            }
            else
            {word =word.substr(1)+first;

           
            word+="ma";
          }
            for(int i = 0; i < count; i++)
                {
                    word += 'a';
                }
            ans+=word;
            ans+=' ';

             count++;
            }

          
               

            ans.pop_back();

            return ans;
        
    }
};