class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int maxF = INT_MIN;
        unordered_map<int,int> map;
        for(int right= 0;right<fruits.size() ;right++){
            map[fruits[right]]++;
            while(map.size()>2){
                map[fruits[left]]--;
                if(map[fruits[left]] == 0){
                    map.erase(fruits[left]);
                }
                left++;
            }
            maxF = max(maxF, right-left+1);
        }
        return maxF;
    }
};
