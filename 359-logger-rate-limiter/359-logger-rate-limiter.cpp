// @Author: KING-SEN

class Logger {
private:
    std::map<std::string, int> timer_;
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (timer_.count(message)) {
            if (timer_[message] + 10 <= timestamp) {
                timer_[message] = timestamp;
                return true;
            }
        } else {
            timer_[message] = timestamp;
            return true;
        }
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */