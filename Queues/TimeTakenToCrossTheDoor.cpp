class Solution {
public:
    vector<int> timeTaken(vector<int>& arrival, vector<int>& state) {
        queue<pair<int,int>> enter, exit;
        int n = arrival.size();
        for(int i=0;i<n;i++){
            if(state[i]){
                exit.push({i,arrival[i]});
            }
            else{
                enter.push({i,arrival[i]});
            }
        }
        int time = 0;
        vector<int> res(n,0);
        while(!enter.empty() && !exit.empty()){
            time = max(time, min(exit.front().second,enter.front().second));

            if( exit.front().second <= enter.front().second){
                while(!exit.empty() && exit.front().second <=time){
                    res[exit.front().first] = time++;
                    exit.pop();
                }
            }
            else{
                while(!enter.empty() && enter.front().second <=time){
                    res[enter.front().first] = time++;
                    enter.pop();
                }
            }
        }
        while(!exit.empty()){
            time = max(time, exit.front().second);
            res[exit.front().first] = time++;
            exit.pop();
        }
        while(!enter.empty()){
            time = max(time, enter.front().second);
            res[enter.front().first] = time++;
            enter.pop();
        }
        return res;

    }
};
