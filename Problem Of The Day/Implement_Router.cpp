#include <bits/stdc++.h>
using namespace std;

struct Packet {
    int source;
    int destination;
    int timestamp;
    // For uniqueness: define operator< or define hash+eq
    bool operator==(const Packet &o) const {
        return source == o.source && destination == o.destination && timestamp == o.timestamp;
    }
};

struct PacketHash {
    size_t operator()(Packet const &p) const noexcept {
        // Combine hashes
        // Make sure this avoids collisions; can use 64-bit combined
        size_t h1 = std::hash<long long>()(((long long)p.source << 32) ^ p.destination);
        size_t h2 = std::hash<long long>()(p.timestamp);
        return h1 ^ (h2 + 0x9e3779b97f4a7c15ULL + (h1<<6) + (h1>>2));
    }
};

class Router {
private:
    int memoryLimit;
    queue<Packet> q;  // store packets in arrival order
    unordered_set<Packet, PacketHash> uniquePackets;  // to check duplicates

    // For each destination, keep all timestamps of packets added for that destination
    unordered_map<int, vector<int>> destTimestamps;

    // For each destination, how many have been forwarded (so we skip them when counting)
    unordered_map<int, int> forwardedCount;

public:
    Router(int memoryLimit) : memoryLimit(memoryLimit) {}

    bool addPacket(int source, int destination, int timestamp) {
        Packet p{source, destination, timestamp};
        if (uniquePackets.find(p) != uniquePackets.end()) {
            return false;
        }
        // If queue full, forward oldest
        if ((int)q.size() == memoryLimit) {
            forwardPacket();
        }
        // Add new packet
        q.push(p);
        uniquePackets.insert(p);
        destTimestamps[destination].push_back(timestamp);
        // Note: forwardedCount for this destination stays as is
        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty()) return {};
        Packet p = q.front();
        q.pop();
        // Remove from unique set
        uniquePackets.erase(p);
        // Mark that one more packet from this destination has been forwarded
        forwardedCount[p.destination]++;
        return {p.source, p.destination, p.timestamp};
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it = destTimestamps.find(destination);
        if (it == destTimestamps.end()) return 0;
        const vector<int>& timestamps = it->second;
        int startIdx = forwardedCount[destination];  
        // We ignore the first startIdx timestamps since those have been forwarded

        // Find lower_bound and upper_bound in timestamps[startIdx..end]
        auto lb = std::lower_bound(timestamps.begin() + startIdx, timestamps.end(), startTime);
        auto ub = std::upper_bound(timestamps.begin() + startIdx, timestamps.end(), endTime);
        return (int)(ub - lb);
    }
};
