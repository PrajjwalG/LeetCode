class LUPrefix {
public:
    vector<bool> isupdated;
    int latest;
    LUPrefix(int n) {
        isupdated.resize(n+1, 0);
        latest = 0;
    }
    
    void upload(int video) {
        isupdated[video] = 1;
        if(latest == video-1){
            while(isupdated[video] == 1 && video < isupdated.size()){
                latest = video;
                video++;
            }
        }
    }
    
    int longest() {
        return latest;
    }
};
