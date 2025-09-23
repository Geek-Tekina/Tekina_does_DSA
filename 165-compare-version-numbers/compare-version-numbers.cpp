class Solution {
public:
    int compareVersion(string version1, string version2) {
       int i = 0, j = 0;
       int len1 = version1.size(), len2 = version2.size();
       string temp1, temp2; int num1, num2;

       while(i < len1 && j < len2) {
        temp1 = "", temp2 = "";

        while( i < len1 && version1[i] != '.') temp1 += version1[i++];
        while( j < len2 && version2[j] != '.') temp2 += version2[j++];
        
        // cout << temp1 << temp2 << "\n";
        num1 = temp1 == "" ? 0 : stoi(temp1);
        num2 = temp2 == "" ? 0 : stoi(temp2);
        if(num1 < num2) return -1;
        else if(num2 < num1) return 1;
        
        ++i; ++j;
       } 

       while(i < len1){
        temp1 = "";
        while( i < len1 && version1[i] != '.') temp1 += version1[i++];

        num1 = temp1 == "" ? 0 : stoi(temp1);
        if(num1 > 0){
            return 1;
        }
        i++;
       }

       while(j < len2){
        temp2 = "";
        while( j < len2 && version2[j] != '.') temp2 += version2[j++];

        num2 = temp2 == "" ? 0 : stoi(temp2);
        if(num2 > 0){
            return -1;
        }
        j++;
       }

        return 0;
    }
};