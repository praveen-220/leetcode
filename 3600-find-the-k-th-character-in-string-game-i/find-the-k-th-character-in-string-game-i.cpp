class Solution {
public:
    char kthCharacter(int k) {
        string word="a";
        string next="";
        int i=0;
        while(pow(2,i)<k)
        {
            i++;
        }
       
        for(int j=0;j<i;j++)
        {
             int l=0;
            string temp=word;
            while(l<word.size()){
            next=next+char(temp[l++]+1);
            }
            
            word+=next;
            next="";
        }
        return word[k-1];
    }
};