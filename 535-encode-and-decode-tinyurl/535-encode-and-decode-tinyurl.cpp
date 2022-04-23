class Solution {
public:
    map<string, string> lUrl, sUrl;
    string rec(){
        string ar = "";
        for(int i = 0; i < 10; i++){
            if(i & 1)
                ar.push_back('a' + rand() % 26);
            else
                ar.push_back('A' + rand() % 26);
            return ar;
        }
        return ar;
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string ret = rec();
        if(lUrl.find(longUrl) != lUrl.end()){
            return lUrl[longUrl];
        }
        else{
            
            while(sUrl.find(ret) != sUrl.end()){
                ret = rec();
            }
            lUrl[longUrl] = ret;
            sUrl[ret] = longUrl;
        }
        return ret;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return sUrl[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));