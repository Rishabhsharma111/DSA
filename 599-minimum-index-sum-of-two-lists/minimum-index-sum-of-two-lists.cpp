class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int sum=0;
        int mini=INT_MAX;
        vector<string>ans;
        for(int i=0;i<list1.size();i++)
{
    for(int j=0;j<list2.size();j++)
    {
        if(list1[i]==list2[j])
        {
            sum=i+j;

            if(sum<mini)
            {
                ans.clear();
                ans.push_back(list1[i]);
                mini=sum;
            }

            else if(sum==mini)
            {
                ans.push_back(list1[i]);
            }
        }
    }
}
    return ans;
    }
};