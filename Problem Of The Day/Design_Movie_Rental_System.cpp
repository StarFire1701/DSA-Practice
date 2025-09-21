#include <bits/stdc++.h>
using namespace std;

struct PairHash {
    size_t operator()(const pair<int,int>& p) const {
        // Simple hash: combine the two ints
        return ((size_t)p.first) * 1000003u + p.second;
    }
};

class MovieRentingSystem {
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e : entries) {
            int shop = e[0];
            int movie = e[1];
            int price = e[2];
            unrented[movie].insert({price, shop});
            shopMoviePrice[{shop, movie}] = price;
        }
    }
    
    vector<int> search(int movie) {
        vector<int> ans;
        if (unrented.count(movie) == 0) return ans;
        auto &s = unrented[movie];
        int cnt = 0;
        for (auto &pr : s) {
            ans.push_back(pr.second);  // shop
            if (++cnt == 5) break;
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        int price = shopMoviePrice[{shop, movie}];
        // remove from available
        unrented[movie].erase({price, shop});
        // add to rented
        rented.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int price = shopMoviePrice[{shop, movie}];
        // remove from rented
        rented.erase({price, shop, movie});
        // add back to available
        unrented[movie].insert({price, shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int cnt = 0;
        for (auto &tpl : rented) {
            // tuple is (price, shop, movie)
            ans.push_back({tpl.shop, tpl.movie});
            if (++cnt == 5) break;
        }
        return ans;
    }
    
private:
    // movie → set of (price, shop) for **available** copies
    unordered_map<int, set<pair<int,int>>> unrented;
    // (shop, movie) → price
    unordered_map<pair<int,int>, int, PairHash> shopMoviePrice;
    // set of rented copies: sorted by (price, then shop, then movie)
    struct RentedEntry {
        int price, shop, movie;
        bool operator<(const RentedEntry &other) const {
            if (price != other.price) return price < other.price;
            if (shop != other.shop) return shop < other.shop;
            return movie < other.movie;
        }
    };
    set<RentedEntry> rented;
};
