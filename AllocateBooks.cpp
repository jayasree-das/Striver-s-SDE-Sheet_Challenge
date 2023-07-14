//Brute force approach(linear search)
T.C:-O(k*m) where k is the sum of time needed to study all chapters
S.C:-O(1)
  #include <bits/stdc++.h> 
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	//total time to finish all chapters
	long long sum = 0;
	//max time that can be studied in a day at minimum is the 
	//max element of the array
    int maxTime = INT_MIN;
	// We will iterate through all the chapters 
	//and calculate the sum and maximum time.
    for (int i = 0; i < m; i++)
    {
        sum += time[i];
        maxTime = max(maxTime , time[i]);
    }

    // We will iterate through all the possible values of answer.
    for (int i = maxTime; i <= sum; i++)
    {       
        long long days = 1;
		//time studied in a day
        long long currentTime = 0;
        for (int j = 0; j < m; j++)
        {
            currentTime += time[j];
			//if time studied in a day is more than max time that can be 
			//studied,move to next day
            if (currentTime > i)
            {
                days++;
                currentTime = time[j];
            }

        }
        // If the days required to study all the chaptes 
		//is less than or equal to n then answer is possible 
		//and we will return it.
        if (days <= n)
        {
            return i;
        }
    }
    return -1;
}


//optimal solution(binary search)
T.C:-O(m*log k) where k is the time needed to complete all chapters
S.C:-O(1)
#include <bits/stdc++.h> 
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	//total time to finish all chapters
	long long sum = 0;
	//max time that can be studied in a day at minimum is the 
	//max element of the array
    int maxTime = INT_MIN;
	// We will iterate through all the chapters 
	//and calculate the sum and maximum time.
    for (int i = 0; i < m; i++)
    {
        sum += time[i];
        maxTime = max(maxTime , time[i]);
    }

    long long l=maxTime,h=sum,ans=sum;
	while(l<=h){
		long long mid=(l+h)/2;
		long days=1;
		long long currTime=0;

		for(int i=0;i<m;i++){
			currTime+=time[i];
			if(currTime>mid){
				days++;
				currTime=time[i];
			}
		}
		if(days<=n){
			ans=mid;
			h=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	return ans;
}
