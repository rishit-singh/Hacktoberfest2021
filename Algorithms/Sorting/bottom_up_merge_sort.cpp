//Good for objects that don't perform their own heap allocations on copy construction
#include <vector>
#include <cmath>
template <typename rand_access_container_t, typname element_t>
void merge(rand_access_conatiner_t &buf, std::vector<element_t> &arr, const int left, const int mid, const int right)
{
    buf.clear();
    long rightIt = mid;
    long leftIt = left;
    const int leftBounds = rightIt;
    for(;leftIt < leftBounds && rightIt < right;)
    {
        if(arr[leftIt] < arr[rightIt])
        {
            buf.push_back(arr[leftIt++]);
        }
        else
        {
            buf.push_back(arr[rightIt++]);
        }
    }
    for(;rightIt < right; rightIt++)
    {
        buf.push_back(arr[rightIt]);
    }
    for(;leftIt < leftBounds; leftIt++)
    {
        buf.push_back(arr[leftIt]);
    }
    for(int i = 0; i < buf.size(); i++)
    {
        arr[i+left] = buf[i];
    }
}
template <typename rand_access_container_t, typename element_t>
void sortm(rand_access_container_t<elemtent_t> &arr)
{
    int depth = std::log(arr.size())/std::log(2);
    std::vector<t> buffer(arr.size());
    for(int i = 1; i <= depth; i++)
    {
        for(long j = 1<<i; j <= arr.size(); j += 1<<i)
        {
            const long lower = (j - (1<<i));
            merge(buffer, arr, lower, (lower+j)>>1, j);
        }
    }
    merge(buffer, arr, 0, 1<<(depth), (int) arr.size());
}
