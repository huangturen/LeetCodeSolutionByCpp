bool isPalindrome(int x) {
        if(x<0)return 0;
        if(x/10 == 0) return 1;
        if(x%10 == 0)return 0;
        
        int start = x;
        int count = log10(x) + 1;
        int arr[count];
        int index = 0;
        while(start != 0){
            arr[index] = start%10;
            start /= 10; 
            index++;
        }
        
        for(int i=0; i< count/2; i++){
            if(arr[i] != arr[count-i-1])return 0;
        }
        return 1;
    }
