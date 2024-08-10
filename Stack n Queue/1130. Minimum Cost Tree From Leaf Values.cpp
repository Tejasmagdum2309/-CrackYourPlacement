class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        arr.insert(arr.begin(),INT_MAX);
        arr.push_back(INT_MAX);
        int res = 0;
        while (arr.size() > 3) {
            // Step 3: Find the smallest element
            auto it = std::min_element(arr.begin() + 1, arr.end() - 1);  // Ignoring the first and last elements
            int ind = std::distance(arr.begin(), it);

            // Step 4: Multiply with the smaller neighbor
            if (arr[ind - 1] < arr[ind + 1]) {
                res += arr[ind - 1] * arr[ind];
            } else {
                res += arr[ind + 1] * arr[ind];
            }

            // Step 5: Remove the smallest element
            arr.erase(it);
        }

        // Step 6: Return the final result
        return res;

    }
};