class MedianFinder {
private:
    std::vector<int> arr;

public:
    MedianFinder() {
        // No initialization needed for vector, it's done automatically
    }

    void addNum(int num) {
        // Binary search to find the correct position to insert
        int beg = 0;
        int end = arr.size();
        while (beg < end) {
            int mid = (end + beg) / 2;
            if (arr[mid] > num) {
                end = mid;
            } else {
                beg = mid + 1;
            }
        }
        arr.insert(arr.begin() + beg, num);
    }

    double findMedian() {
        int n = arr.size();
        if (n % 2 == 1) {
            return arr[n / 2];
        } else {
            return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */