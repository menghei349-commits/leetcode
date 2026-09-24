class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        deque<int> v;
        vector<int> ans;

        for(auto it : asteroids){
            if(it > 0) v.push_back(it);
            else{
                while(!v.empty()){
                    if(abs(it) == v.back()){
                        it = 0;
                        v.pop_back();
                        break;
                    }else if(abs(it) < v.back()){
                        break;
                    }else v.pop_back();
                }

                if(v.empty() && it != 0) ans.push_back(it);
            }
        }

        while(!v.empty()){
            ans.push_back(v.front());
            v.pop_front();
        }

        return ans;
    }
};