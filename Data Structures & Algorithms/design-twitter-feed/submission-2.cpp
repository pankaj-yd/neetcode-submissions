class Twitter {
private:
    int time;
    unordered_map<int, unordered_set<int> > follows;
    unordered_map<int, vector<pair<int,int>> > tweets;
public:
    Twitter(){
        time = 0;
    }
    
    void postTweet(int userId, int tweetId){
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId){
        vector<int> res;

        follows[userId].insert(userId);

        auto comp = [](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(comp) > pq(comp); 
        for(int user : follows[userId]){
            int size = tweets[user].size();
            if(size > 0){
                pq.push({tweets[user][size - 1].first, user, size - 1});
            }
        }

        while(!pq.empty() && res.size() < 10){
            vector<int> top = pq.top();
            pq.pop();
            
            res.push_back(tweets[top[1]][top[2]].second);

            if(top[2] > 0){
                pq.push({tweets[top[1]][top[2]-1].first, top[1], top[2] - 1});
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId){
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId){
        follows[followerId].erase(followeeId);
    }
};
