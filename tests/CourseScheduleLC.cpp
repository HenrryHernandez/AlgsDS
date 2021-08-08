vector<int> v[100000];
        vector<set<int>> setsV(100000);
        unordered_set<int> st;
        for(int i = 0; i < numCourses; i++) st.insert(i);
        for(vector<int> pres : prerequisites){
            st.erase(pres[0]);
            v[pres[1]].push_back(pres[0]);
            setsV[pres[0]].insert(pres[1]);
        }
        
        return true;
