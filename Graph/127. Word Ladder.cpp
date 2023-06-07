/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no 
such sequence exists.
Example 1:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
Example 2:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
Constraints:

1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.
*/

// Solution

class Solution {
public:
    int ladderLength(string startWord, string targetWord, vector<string>& wordList) {
        queue<pair<string, int>>q;
        unordered_set<string>st(wordList.begin(), wordList.end());
        q.push({startWord, 1});
        st.erase(startWord);
        while(!q.empty())
        {
            string tmp=q.front().first;
            int b=q.front().second;
            q.pop();
            if(tmp==targetWord)
                return b;
            for(int i=0; i<tmp.length(); i++)
            {
                string word=tmp;
                for(char c='a'; c<='z'; c++)
                {
                    word[i]=c;
                    if(st.find(word)!=st.end())
                    {
                        st.erase(word);
                        q.push({word, b+1});
                    }
                }
            }
        }
        return 0;
    }
};
