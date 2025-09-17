class FoodRatings {
public:
    struct cmp {
        bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
            if(a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        }
    };
    unordered_map<string, int> foodRating;
    unordered_map<string, string> foodCuisine;
    unordered_map<string, priority_queue<pair<int,string>, vector<pair<int,string>>, cmp>> mp;


    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0; i < n; ++i) {
            foodRating[foods[i]] = ratings[i];
            foodCuisine[foods[i]] = cuisines[i];
            mp[cuisines[i]].push({ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating) {
        foodRating[food] = newRating;
        string cuisine = foodCuisine[food];
        mp[cuisine].push({newRating, food});
    }

    string highestRated(string cuisine) {
        auto& pq = mp[cuisine];
        while(!pq.empty()) {
            auto [rating, food] = pq.top();
            if(foodRating[food] == rating) return food;
            pq.pop();
        }
        return "";
    }
};
