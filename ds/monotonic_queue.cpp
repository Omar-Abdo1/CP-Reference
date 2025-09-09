
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


class MonotonicQueue {
public:
    void push(int value) {
        inputStack.push(value);
    }

    void pop() {
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                int value = inputStack.top();
                inputStack.pop();
                outputStack.push(value);
            }
        }
        outputStack.pop();
    }

    int max() const {
        if (inputStack.empty()) {
            return outputStack.max();
        } else if (outputStack.empty()) {
            return inputStack.max();
        } else {
            return std::max(inputStack.max(), outputStack.max()); // if min max become min 
        }
    }

    bool empty() const {
        return inputStack.empty() && outputStack.empty();
    }

private:
    MaxStack inputStack;
    MaxStack outputStack;
};
