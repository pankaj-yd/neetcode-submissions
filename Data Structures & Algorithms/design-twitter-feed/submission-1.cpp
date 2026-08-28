class Twitter {
    int time;
    map<int, set<int>> followers;
    map<int, vector<vector<int>> > postsByUser;

public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        postsByUser[userId].push_back({time, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        followers[userId].insert(userId);
        

        auto compare = [](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> pq(compare);
        set<int> userFollowed = followers[userId];
        for(int user : userFollowed){
            // cout << "user Id: " << userId << " , follows: " << user << endl;
            if( postsByUser[user].size() ){
                vector<vector<int>> &posts = postsByUser[user];
                int idx = posts.size() - 1;
                pq.push({posts[idx][0], posts[idx][1], user, idx});
            }
        }

        vector<int> res;
        while(!pq.empty() && res.size() < 10){
            vector<int> top = pq.top();
            pq.pop();
            res.push_back(top[1]);
            
            int idx = top[3];
            if(idx > 0){
                vector<vector<int>> &posts = postsByUser[top[2]];
                pq.push({posts[idx-1][0], posts[idx-1][1], top[2], idx - 1});
            }
        }

        return res;

    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
        
    }
};
