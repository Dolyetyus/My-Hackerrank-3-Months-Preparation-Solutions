string timeInWords(int h, int m) {
    vector<string> hours = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "quarter", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "twenty one", "twenty two", "twenty three", "twenty four", "twenty five", "twenty six", "twenty seven", "twenty eight", "twenty nine", "half" };
    
    string ret;
    
    if (m==0) {
        ret.append(hours.at(h));
        ret.append(" o' clock");
        return ret;
    }
    
    if (m<30) {
        ret.append(hours.at(m));
        
        if (m==1) ret.append(" minute past ");
        else if (m==15) ret.append(" past ");
        else ret.append(" minutes past ");
        
        ret.append(hours.at(h));
        return ret;
    }
    else if (m==30){
        ret.append("half past ");
        ret.append(hours.at(h));
        return ret;
    }
    else{
        ret.append(hours.at(60-m));
        
        if (60-m==1) ret.append(" minute to ");
        else if (60-m==15) ret.append(" to ");
        else ret.append(" minutes to ");
        if (h==12) ret.append(hours.at(1));
        else ret.append(hours.at(h+1));
        return ret;
    }
}
