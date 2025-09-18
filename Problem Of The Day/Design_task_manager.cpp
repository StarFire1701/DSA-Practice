#include <bits/stdc++.h>
using namespace std;

struct Task {
    int userId;
    int taskId;
    int priority;
    Task(int u, int t, int p) : userId(u), taskId(t), priority(p) {}
};

// Comparator: higher priority first; if equal, higher taskId first
struct Cmp {
    bool operator()(Task const& a, Task const& b) const {
        if (a.priority != b.priority)
            return a.priority > b.priority;
        return a.taskId > b.taskId;
    }
};

class TaskManager {
private:
    // Map taskId → Task info (userId + priority)
    unordered_map<int, pair<int,int>> taskInfo;
    // Ordered set of tasks, with custom comparator
    set<Task, Cmp> taskSet;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            int u = t[0], id = t[1], p = t[2];
            add(u, id, p);
        }
    }

    void add(int userId, int taskId, int priority) {
        // insert both into map and set
        Task t(userId, taskId, priority);
        taskSet.insert(t);
        taskInfo[taskId] = {userId, priority};
    }

    void edit(int taskId, int newPriority) {
        auto it = taskInfo.find(taskId);
        if (it == taskInfo.end()) return;  // or throw / handle error
        int oldPriority = it->second.second;
        int userId = it->second.first;
        // Remove old Task from set
        Task oldTask(userId, taskId, oldPriority);
        auto sit = taskSet.find(oldTask);
        if (sit != taskSet.end()) {
            taskSet.erase(sit);
        }
        // Insert updated
        Task newTask(userId, taskId, newPriority);
        taskSet.insert(newTask);
        it->second.second = newPriority;
    }

    void rmv(int taskId) {
        auto it = taskInfo.find(taskId);
        if (it == taskInfo.end()) return;
        int priority = it->second.second;
        int userId = it->second.first;
        Task t(userId, taskId, priority);
        auto sit = taskSet.find(t);
        if (sit != taskSet.end()) {
            taskSet.erase(sit);
        }
        taskInfo.erase(it);
    }

    int execTop() {
        if (taskSet.empty()) return -1;
        auto it = taskSet.begin();
        Task t = *it;
        taskSet.erase(it);
        // remove from map
        taskInfo.erase(t.taskId);
        return t.userId;
    }
};
