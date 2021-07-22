class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count = 0;
        vector< int > isOdd;
        for( int i = 0; i < nums.size(); ++i )
        {
            if( nums[i] % 2 == 1 )
                isOdd.push_back( i );
        }
        
        int numOdd = isOdd.size();
        
        int intervalStart, intervalEnd, start, end;
        int count1, count2;
        
        for ( int j = 0; j <= numOdd-k; j++ )
        {
            count++;
            intervalStart = isOdd[j];
            intervalEnd = isOdd[ j+k-1 ];
            if( j == 0 )
                start = 0;
            else
                start = isOdd[j-1] +1;
            if( j == numOdd-k )
                end = nums.size() -1;
            else
                end = isOdd[j+k] -1;
            
            if( start != intervalStart )
            {
                count1 = intervalStart - start;
                count += count1;
                count2 = end - intervalEnd;
                count += count2;
                count += count1 * count2;
            }
            else
            {
                count2 = end - intervalEnd;
                count += count2;
            }
            
        }
        
        return count;
        
    }
};
