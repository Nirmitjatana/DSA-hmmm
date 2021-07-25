// class Solution {
//     map<int,list<int>> graph;
// public:
//     void addEdge(int x, int y){
//         graph[x].push_back(y);
//         return;
//     }
//     void dfs_helper(int src, map<int,bool> &visited, list<int> &ordering){
//         visited[src] = true;
//         for(int nbr:graph[src]){
//             if(!visited[nbr]){
//                 dfs_helper(src,visited,ordering);
//             }
//         }
//         ordering.push_front(src);
//         return;
//     }
//     void dfs(int src,int &count){
//         map<int,bool> visited;
//         list<int> ordering;
//         for(auto p:graph){
//             int node = p.first;
//             visited[node] = false;
//         }
//         dfs_helper(src,visited,ordering);
//         count = ordering.size();
//         return;
//     }
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         for(int i=0;i<prerequisites.size();i++){
//             addEdge(prerequisites[i][0],prerequisites[i][1]);
//         }
//         int count=0;
//         for(int i=0;i<numCourses;i++){
//             dfs(i,count);
//         }
//         if(count == numCourses) return true;
//         return false;
//     }
// };

class Solution {
public:
    //TOPOLOGICAL SORT USING BFS
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(n,vector<int>());
        queue<int> q;
        vector<int> in_degree(n,0);
        vector<int> ans;
        //Making graph edge is unidirictional(p[1] --> p[0]) 
        for(auto p: prerequisites) {
            graph[p[1]].push_back(p[0]);
            ++in_degree[p[0]];
        }
        //Push all the elements in the queue which has 0 in_degree
        for(int i=0;i<n;++i) {
            if(in_degree[i]==0) {
                q.push(i);
            }
        }
        //if we remove the parent of a node then its in_degree will decreases by 1 unit
        while(!q.empty()) {
            int cur=q.front();
            q.pop();
            ans.push_back(cur);
            for(int child: graph[cur]) {
                --in_degree[child];
                if(in_degree[child]==0) {
                    q.push(child);
                }
            }
        }
        return ans.size()==n;
    }
};