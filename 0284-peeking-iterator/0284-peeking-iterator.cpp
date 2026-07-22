class PeekingIterator : public Iterator {
public:

    int nextValue;
    bool hasValue;

    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        hasValue = Iterator::hasNext();

        if(hasValue)
            nextValue = Iterator::next();
    }

    int peek() {
        return nextValue;
    }

    int next() {
        int ans = nextValue;

        hasValue = Iterator::hasNext();

        if(hasValue)
            nextValue = Iterator::next();

        return ans;
    }

    bool hasNext() const {
        return hasValue;
    }
};