#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums;

    nums.push_back(45);
    nums.push_back(55);

    cout<<nums.size()<<endl;
    //for each loop
    for(int val: nums)
    {
        cout<<val <<endl;
    }
    //pops the last index
    nums.pop_back();
    cout<<nums.size()<<endl;
    return 0 ;
}