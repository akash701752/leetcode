 class Solution {
    string helper(int num)
    {
        //we always receive a three digit number bcz of %1000 means
        //a Number less than 1000
        string ones[] {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
        string teens[] {"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
        string tens[] {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

        string result="";
        if(num>99) result+=ones[num/100]+" Hundred ";
        // to make number 2 digit
        num=num%100;
        if(num<20 && num>9) result+=teens[num-10]+" ";
        else
        {
            if(num>=20) result+=tens[num/10]+" ";
            // to make it 1 digit
            num=num%10;
            if(num>0) result+=ones[num]+" ";
        }
        return result;
    }
public:
    string numberToWords(int num) {
     if(num==0) return "Zero";   
     string gg[] {"Thousand","Million","Billion"};
     string result="";
     result=helper(num%1000);
     num=num/1000;
     //we already done with 3 digits
     for(int i=0;i<3;i++)
     {
        if(num>0 && num%1000>0)
        {
            result=helper(num%1000)+gg[i]+" "+result;
        }
        num=num/1000;
     }
     //for trimming 
     return result.empty() ? result : result.substr(0, result.size() - 1);
    }
};
