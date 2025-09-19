class Spreadsheet {
public:
    unordered_map<string, int> mp;

    Spreadsheet(int rows) {}

    void setCell(string cell, int value) {
        mp[cell] = value;
    }

    void resetCell(string cell) {
        mp[cell] = 0;
    }

    int getValue(string formula) {
        int pos = formula.find('+');
        string left = formula.substr(1, pos - 1);        
        string right = formula.substr(pos + 1);           

        int num1, num2;

        if (isdigit(left[0])) {
            num1 = stoi(left);
        } else {
            num1 = mp.count(left) ? mp[left] : 0;
        }

        if (isdigit(right[0])) {
            num2 = stoi(right);
        } else {
            num2 = mp.count(right) ? mp[right] : 0;
        }

        return num1 + num2;
    }
};
