class Solution {
public:
    string addBinary(string a, string b) {
        // Complicated Logic .....................

        // int a1 = a.length();
        // int b1 = b.length();

        // if(a1 < b1){
        //     return addBinary(b,a);
        // }
        
        // string ans = "";
        // bool extra = 0;
        
        // int i = a1-1;
        // int j = b1-1;
        // while(j >= 0){
        //     if(extra){
        //         if(a[i] == '1' && b[j] == '1'){
        //            ans.append("1");
        //            extra = true;
        //         }
        //         else if(a[i] == '0' && b[j] == '0'){
        //           ans.append("1");
        //            extra = false;
        //         }
        //         else{
        //             ans.append("0");
        //            extra = true;
        //         }
        //     }
        //     else{
        //        if(a[i] == '1' && b[j] == '1'){
        //            ans.append("0");
        //            extra = true;
        //         }
        //         else if(a[i] == '0' && b[j] == '0'){
        //           ans.append("0");
        //            extra = false;
        //         }
        //         else{
        //             ans.append("1");
        //            extra = false;
        //         }
        //     }
        //     i--;j--;
        // }

        // while(i >= 0){
        //     if(extra){
        //         if(a[i] == '1'){
        //             ans.append("0");
        //             extra = true;
        //         }else{
        //             ans.append("1");
        //             extra = false;
        //         }
        //     }
        //     else{
        //         if(a[i] == '1'){
        //             ans.append("1");
        //             extra = false;
        //         }else{
        //             ans.append("0");
        //             extra = false;
        //         }
        //     }
        //     i--;
        // }

        // if(extra) ans.append("1");
        // reverse(ans.begin(),ans.end());
        // return ans;

        // more optimized............
       
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        string ans = "";

        while(i >= 0 || j >= 0 || carry){
            int sum = carry;
            if(i >= 0){
                sum += (a[i] - '0'); i--;
            }
            
            if(j >= 0){
                sum += (b[j] - '0');j--;
            }

            carry = (sum / 2);
            ans.append(to_string(sum % 2));
           
        }

        reverse(ans.begin(),ans.end());

        return ans;


    }
};