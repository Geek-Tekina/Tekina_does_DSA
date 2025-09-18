class TaskManager {
public:
    // mp => taskId - <userID, priority>
    // pq => priority - taskId
    // activeTasks => taskId - bool
    struct cmp{
        bool operator()( const pair<int, int> p1,const pair<int, int> p2) const{
            if(p1.first == p2.first) return p1.second < p2.second;
            return p1.first < p2.first;
        }
    };
    unordered_map <int, pair<int, int>> mp;
    priority_queue <pair<int, int>, vector<pair<int, int>>, cmp> pq;
    unordered_map <int, bool> activeTasks;

    TaskManager(vector<vector<int>>& tasks) {
        for(auto it : tasks){
            mp[it[1]] = {it[0], it[2]};
            pq.push({it[2], it[1]});
            activeTasks[it[1]] = true;
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mp[taskId] = {userId, priority};
        pq.push({priority, taskId});
        activeTasks[taskId] = true;
    }
    
    void edit(int taskId, int newPriority) {
        auto data = mp[taskId];
        int userId = data.first;

        mp[taskId] = {userId, newPriority};
        pq.push({newPriority, taskId});
    }
    
    void rmv(int taskId) {
        mp.erase(taskId);
        activeTasks[taskId] = false;
    }
    
    int execTop() {
        while(!pq.empty() && (activeTasks[pq.top().second] != true || pq.top().first != mp[pq.top().second].second) ) {
            pq.pop();
        }
        if(pq.empty()) return -1;
        auto temp = pq.top();
        auto details = mp[temp.second];
        pq.pop();
        activeTasks[temp.second] = false;
        mp.erase(temp.second);

        return details.first;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */