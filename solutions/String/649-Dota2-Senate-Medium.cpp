class Solution {
public:
    string predictPartyVictory(string senate) {
        int R = 0, D = 0;

        while(true){
            string s = "";
            for(char c : senate){
                if(c == 'D'){
                    if (R == 0){
                        D++; 
                        s += 'D';
                    }else R--;
                }else{
                    if(D == 0){ 
                        R++; 
                        s += 'R'; 
                    }else D--;
                }
            }

            if (count(s.begin(), s.end(), 'R') == 0) return "Dire";
            if (count(s.begin(), s.end(), 'D') == 0) return "Radiant";

            senate = s;
        }
    }
};