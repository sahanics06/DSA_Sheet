/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if 
no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: []
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 

Constraints:

1 <= beginWord.length <= 5
endWord.length == beginWord.length
1 <= wordList.length <= 500
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.
The sum of all shortest transformation sequences does not exceed 105.
*/

// Solution -> Full optimised for CP purpose

class Solution {
public:
    unordered_map<string, int>mp;
    string target;
    void dfs(string word, vector<string>&vec, vector<vector<string>>&ans)
    {
        if(word==target)
        {
            // Since we have backtracked, so vector will contains words in reverse order
            reverse(vec.begin(), vec.end());
            ans.push_back(vec);
            // again we have to make the order of vector like previous or else for next call the order will change, since it uses call  by reference
            reverse(vec.begin(), vec.end());
            return;
        }
        int n=word.size();
        int steps=mp[word];
        for(int i=0; i<n; i++)
        {
            char original=word[i];
            for(char c='a'; c<='z'; c++)
            {
                word[i]=c;
                if(mp.find(word)!=mp.end() && mp[word]+1==steps)// if steps is equal means we got the correct top order to traverse back the word.
                {
                    vec.push_back(word);
                    dfs(word, vec, ans);
                    vec.pop_back(); // pop_back so that for different call the previous word doesnot come again.
                }
            }
            word[i]=original;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(), wordList.end());
        queue<string>q;
        target=beginWord;
        vector<vector<string>>ans;
        q.push({beginWord});
        mp[beginWord]=1;
        st.erase(beginWord);// since we don't keep using the same word
        int sz=beginWord.length();
        while(!q.empty())
        {
            string word=q.front();
            q.pop();
            int steps=mp[word];
            if(word==endWord)
                break;
            for(int i=0; i<sz; i++)
            {
                char original=word[i];
                for(char c='a'; c<='z'; c++)
                {
                    word[i]=c;
                    if(st.count(word)>0)
                    {
                        q.push(word);
                        st.erase(word); // since we don't keep using the same word
                        mp[word]=steps+1;
                    }
                }
                word[i]=original;
            }
        }
        
        if(mp.find(endWord)!=mp.end())
        {
            vector<string>vec;
            vec.push_back(endWord);
            dfs(endWord, vec, ans);
        }
        return ans;
    }
};

// Solution TLE in Leetcode but Good for Interview

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(), wordList.end());
        queue<vector<string>>q;
        vector<string>used;
        vector<vector<string>>ans;
        used.push_back(beginWord);
        q.push({beginWord});
        int level=0;
        while(!q.empty())
        {
            vector<string>vec=q.front();
            q.pop();
            if(vec.size()>level)
            {
                level++;
                for(auto it:used)
                {
                    st.erase(it);
                }
            }
            used.clear();
            string word=vec.back();
            if(word==endWord)
            {
                if(ans.size()==0)
                {
                    ans.push_back(vec);
                }
                else if(ans[0].size()==vec.size())
                {
                    ans.push_back(vec);
                }
            }
            for(int i=0; i<word.length(); i++)
            {
                char original=word[i];
                for(char c='a'; c<='z'; c++)
                {
                    word[i]=c;
                    if(st.count(word)>0)
                    {
                        vec.push_back(word);
                        q.push(vec);
                        used.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i]=original;
            }
        }
        return ans;
    }
};
