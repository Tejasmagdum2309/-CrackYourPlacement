/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       int idx = 0;int psum = 0;int dsum = 0;
       
       for(int i = 0;i < n;i++){
           psum += p[i].petrol;
           dsum += p[i].distance;
       }
       
       if(psum < dsum) return -1;
       int s = 0;
       for(int i = 0;i < n;i++){
           s += (p[i].petrol - p[i].distance);
           if(s < 0){
               s = 0;
               idx = i+1;
           }
       }
       return idx;
    }
};
