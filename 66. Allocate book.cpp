/*Problem Statement
Ayush is studying for ninjatest which will be held after 'N' days, And to score good marks he has to study 'M' chapters and the ith chapter requires TIME[i] seconds to study. The day in Ayush’s world has 100^100 seconds. There are some rules that are followed by Ayush while studying.
1. He reads the chapter in a sequential order, i.e. he studies i+1th chapter only after he studies ith chapter.
2. If he starts some chapter on a particular day he completes it that day itself.
3. He wants to distribute his workload over 'N' days, so he wants to minimize the maximum amount of time he studies in a day.
Your task is to find out the minimal value of the maximum amount of time for which Ayush studies in a day, in order to complete all the 'M' chapters in no more than 'N' days.
*/




bool isPossible(vector<int> &time , int n,int m,long long  mid){
    long long sum = 0 ; 
    int i=0;
    while( m > 0 && i<n){
        if(sum + time[i] <=  mid)sum +=time[i];
        else {
            if(time[i]> mid || m==1)return false;
            sum = time[i];
            m--;
        }
        i++;
    }
    return true;
    
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{
   long long  high = 0;
   for(int i = 0 ; i < m ; i++){
       high  += time[i];
   }

   long long low  = 0;
   long long mid;

    while(low <=  high) {
        mid = low + (high -low)/2; 

        if(isPossible(time,m,n,mid)){
            high  = mid -1;
        }
        else low = mid+1;
    }
    return low;
}