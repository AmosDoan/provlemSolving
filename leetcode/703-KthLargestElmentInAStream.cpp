class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> q;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (auto& num : nums) {
            q.push(num);
            if (q.size() > k) {
                q.pop();
            }
        }
    }

    int add(int val) {
        q.push(val);

        if (q.size() > k) {
            q.pop();
        }

        return q.top();
    }
};
