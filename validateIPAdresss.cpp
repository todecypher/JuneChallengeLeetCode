class Solution {
public:
    int check(string &IP){
        int i=0;
        while(i<IP.length() and (IP[i] !=':' and IP[i] !='.') )
            i++;
        if(i==IP.length())
            return -1;
        if(IP[i] =='.')
            return 0;
        if(IP[i] == ':')
            return 1;
        return -1;
    }
    bool valid(char ch){
        return ((ch>='0' and ch <='9') or (ch >='a' and ch<='f') or (ch>='A' and ch<='F') or ch ==':');
    }
    string ipv4(string &IP){
        string temp;
        int ct = 0;
        for(int i =0;i<IP.length();i++){
            if(temp.length() > 3)
                return "Neither";
            if((IP[i] < '0' or IP[i] >'9' ) and IP[i] !='.')
                return "Neither";
            if(IP[i] !='.'){
                temp+= IP[i];
            }
            else{
                if(IP[i] !='.' or temp.empty())
                    return "Neither";
                ct++;
                int x = stoi(temp);
                string g = to_string(x);
                bool ok = x>=0 and x<256 and temp.length() == g.length();
                if(!ok)
                    return "Neither";
                temp.clear();
            }
        }
        if(temp.length() >0){
            int x = stoi(temp);
            string g = to_string(x);
            bool ok = x>0 and x<256 and temp.length() == g.length();
            if(!ok or ct !=3)
                return "Neither";
            return "IPv4";
        }
        else{
            return "Neither";
        }
    }
    string ipv6(string &IP){
        string temp ;
        int ct =0;
        for(int i=0;i<IP.length();i++){
             if(temp.length() > 4)
                return "Neither";
             if(!valid(IP[i]))
                return "Neither";
            if(IP[i] !=':')
                temp +=IP[i];
            else{
                if(IP[i] != ':' or temp.empty())
                    return "Neither";
                ct++;
                bool ok =  temp.length() >0 and temp.length() <5;
                if(!ok)
                    return "Neither";
                temp.clear();
            }
        }
       if(temp.length() >0){
            bool ok =  temp.length() >0 and temp.length() <5;
            if(!ok or ct!=7)
                return "Neither";
            return "IPv6";
       }
        else{
            return "Neither";
        }
    }
    string validIPAddress(string IP) {
        int x = check(IP);
        if(x==-1)
            return "Neither";
        if(x==0){
            return ipv4(IP);
        }
        return ipv6(IP);
        
    }
};