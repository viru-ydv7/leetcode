class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
            int n=speed.size();
            vector<pair<int,double>>time(n);
            for(int i=0;i<position.size();i++){
                double timee=double(double(target-position[i])/speed[i]);
                time[i]={position[i],timee};
            }

            sort(time.rbegin(),time.rend());
            int fleets=0;
            double lasttime=0;
            for(auto it:time){
                int pos=it.first;
                double t=it.second;

                if(t > lasttime){
                    fleets++;
                    lasttime=t;
                }
            }

            return fleets;
    }
};