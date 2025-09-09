class MaxStack {
public:
    void push(int value) {
        dataStack.push(value);
        if (maxStack.empty() || value >= maxStack.top()) { // if min   value<= 
            maxStack.push(value);
        }
    }

    void pop() {
        if (dataStack.top() == maxStack.top()) {
            maxStack.pop();
        }
        dataStack.pop();
    }

    int max() const {
        return maxStack.top();
    }

    bool empty() const {
        return dataStack.empty();
    }

    int top() const {
        return dataStack.top();
    }

private:
    std::stack<int> dataStack;
    std::stack<int> maxStack;
};
