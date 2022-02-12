// @author: KING-SEN
// Programming Language Used: C++

class Solution {
public:
    void makeTranformation(vector<string>& wordList, unordered_map<string, vector<string>>& allCombWords){
        for(auto &word : wordList){
            for(int i = 0; i < word.size(); i++){
                string temp = word;
                temp[i] = '*';
                allCombWords[temp].push_back(word);
            }
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> allCombWords;
        unordered_map<string, int> distWord;
        queue<string> queueList;
        
        makeTranformation(wordList, allCombWords);
        queueList.push(beginWord);
        distWord[beginWord] = 1;
        
        while(!queueList.empty()){
            string word = queueList.front();
            queueList.pop();
            
            if(word == endWord) return distWord[endWord];
            
            for(int i = 0; i < word.size(); i++){
                string temp = word;
                temp[i] = '*';
                if(allCombWords.count(temp)){
                    for(auto &item : allCombWords[temp]){
                        if(distWord.count(item) == 0){
                            queueList.push(item);
                            distWord[item] = distWord[word] + 1;
                        }
                    }
                }
            }
        }
        return 0;
    }
};

// Time Complexity: O(M ^ 2 * N), where M is the length of each word and N is the total number of words in the word list
// for each word list we have to iterate over it's length to find all the intermediate words corresponding to it. Since the of each word is M and we have N words, the total number of iterations the algorithm takes to create is M * N. Additionally, forming each of the intermediate word takes O(M)time because of the substring operation used to create the new string.
// So combining the above steps, the overall time complexity of this approach is O(M ^ 2 * N).


// Space Complexity: O(M ^ 2 * N), each word in the word list would have M intermediate combinations. for each of M intermediae words we save the original word. Thus all combination would take O(M ^ 2 * N) space. ans for visited and BFS queue we need O(M * N) space.
// so overall time complexity: O(M ^ 2 * N) + O(M * N) + O(M * N) = O(M * N) space
