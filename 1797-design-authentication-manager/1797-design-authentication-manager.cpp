class AuthenticationManager {
public:

    int ttl;
    unordered_map<string, int> mp;

    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }

    void generate(string tokenId, int currentTime) {
        mp[tokenId] = currentTime + ttl;
    }

    void renew(string tokenId, int currentTime) {

        if (mp.find(tokenId) != mp.end() &&
            mp[tokenId] > currentTime) {

            mp[tokenId] = currentTime + ttl;
        }
    }

    int countUnexpiredTokens(int currentTime) {

        int count = 0;

        for (auto x : mp) {

            if (x.second > currentTime) {
                count++;
            }
        }

        return count;
    }
};