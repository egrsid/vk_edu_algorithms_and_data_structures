int startTernarySearchRecursion(const std::vector<int>& vect, const int target) {
    if (vect.empty()) { return -1; }

    int left = 0;
    int right = vect.size() - 1;

    if (vect[left] > target || vect[right] < target) { return -1; }

    return ternarySearchRecursion(vect, target, left, right);
}