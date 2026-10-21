class FoodRatings {
    unordered_map<string,int>frmap;
    unordered_map<string,string>fcmap;
    unordered_map<string,set<pair<int,string>>>cfmap;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            frmap[foods[i]]=ratings[i];
            fcmap[foods[i]]=cuisines[i];
            cfmap[cuisines[i]].insert({-ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string c=fcmap[food];
        auto it=cfmap[c].find({-frmap[food],food});
        cfmap[c].erase(it);
        frmap[food]=newRating;
        cfmap[c].insert({-newRating,food});
    }
    
    string highestRated(string cuisine) {
        auto it=*cfmap[cuisine].begin();
        return it.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */