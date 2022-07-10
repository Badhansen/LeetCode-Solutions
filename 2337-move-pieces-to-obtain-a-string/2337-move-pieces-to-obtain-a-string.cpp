class Solution {
private:
    queue<pair<char, int>> start_queue, target_queue;
public:
    bool canChange(string start, string target) {
        if(start.size() != target.size()){
            return false;
        }
        
        for(int index = 0; index < start.size(); index++){
            if(start[index] != '_'){
                start_queue.push({start[index], index});
            }
            
            if(target[index] != '_'){
                target_queue.push({target[index], index});
            }
        }
        
        if(start_queue.size() != target_queue.size()){
            return false;
        }
        
        while(!start_queue.empty()){
            auto s_item = start_queue.front();
            auto t_item = target_queue.front();
            
            start_queue.pop();
            target_queue.pop();
            
            if(s_item.first != t_item.first){
                return false;
            }
            if(s_item.first == 'L' && t_item.second > s_item.second){
                return false;
            }
            if(s_item.first == 'R' && t_item.second < s_item.second){
                return false;
            }
        }
        return true;
    }
    ~Solution(){
        while(!start_queue.empty()) start_queue.pop();
        while(!target_queue.empty()) target_queue.pop();
    }
};