class Solution {
private:
    void bfs(vector<vector<int>>& heights, queue<pair<int, int>>& q, vector<vector<bool>>& vis){
        vector<int> dir = {0, 1, 0, -1, 0};
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int xi = x.first+dir[i];
                int yi = x.second+dir[i+1];
                if(xi>=0 && yi>=0 && xi<heights.size() && yi<heights[0].size() && !vis[xi][yi] && heights[xi][yi]>=heights[x.first][x.second]){
                    vis[xi][yi] = true;
                    q.push({xi, yi});
                }
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        queue<pair<int, int>> pacQ;
        queue<pair<int, int>> atlQ;
        vector<vector<bool>> pacVis(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> atlVis(heights.size(), vector<bool>(heights[0].size(), false));
        for(int i=0;i<heights.size();i++){
            pacQ.push({i, 0});
            pacVis[i][0] = true;
            atlQ.push({i, heights[0].size()-1});
            atlVis[i][heights[0].size()-1] = true;
        }
        for(int i=0;i<heights[0].size();i++){
            pacQ.push({0, i});
            pacVis[0][i] = true;
            atlQ.push({heights.size()-1, i});
            atlVis[heights.size()-1][i] = true;
        }
        bfs(heights, pacQ, pacVis);
        bfs(heights, atlQ, atlVis);
        vector<vector<int>> ans;
        for(int i=0;i<heights.size();i++){
            for(int j=0;j<heights[i].size();j++){
                if(pacVis[i][j] && atlVis[i][j]) ans.push_back({i, j});
            }
        }
        return ans;
    }
};
