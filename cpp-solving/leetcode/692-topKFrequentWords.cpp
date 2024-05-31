#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution {
    struct Word {
        string word;
        int frequency;
        Word(string word, int frequency) : word(word), frequency(frequency) {}
    };

    struct comparator {
        bool operator() (Word& w1, Word& w2) {
            if (w1.frequency == w2.frequency) {
                return w1.word > w2.word;
            }
            return w1.frequency < w2.frequency;
        }
    };

private:
    map<string, int> m;

public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<Word, vector<Word>, comparator> q;
        for (auto& word : words) {
            m[word]++;
        }

        for (auto it = m.begin(); it != m.end(); it++) {
            Word w(it->first, it->second);
            q.push(w);
        }

        vector<string> result;

        for (int i = 0; i < k; i++) {
            Word w = q.top();
            q.pop();

            result.push_back(w.word);
        }

        return result;
    }
};

int main() {
    Solution *s;

    vector<string> v = {"i", "love", "leetcode", "i", "love", "coding"};

    s = new Solution();
    vector<string> ret = s->topKFrequent(v, 2);
    delete s;

    for (auto &elem : ret) {
        cout << elem << ' ';
    }
    cout << '\n';
}

static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();
