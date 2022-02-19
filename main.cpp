#include<bits/stdc++.h>

using namespace std;


class MyHashMap {
public:
    int bucket_size=15007;
    vector<list<pair<int,int>>>arr;
    MyHashMap() {
        list<pair<int,int>>lt;
        for(int i=0;i<bucket_size;i++)
        {
            arr.push_back(lt);
        }
        
    }
    
    int HashKey(int key)
    {
        return key%bucket_size;
    }
   
    
    void put(int key, int value) {
        int h=HashKey(key);
        for(auto itr=arr[h].begin();itr!=arr[h].end();itr++)
        {
            if(itr->first==key)
            {
                itr->second=value;
                return;
            }
        }
        arr[h].push_back({key,value});
    }
    
    int get(int key) {
        
        int h=HashKey(key);
        for(auto it:arr[h])
        {
            if(it.first==key)return it.second;
        }
        return -1;
    }
    
    void remove(int key) {
        int h=HashKey(key);
       // list<pair<int,int>>lt=arr[h];
        //list<pair<int,int>>::iterator itr;
        for(auto itr=arr[h].begin();itr!=arr[h].end();itr++)
        {
            if(itr->first==key)
            {
                //lt.erase(itr);
                //arr[h]=lt;
                arr[h].erase(itr);
                return;
            }
        }
        return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main()
{
    MyHashMap mp;
    ///Do Add,remove ,Get in object mp



    return 0;
}