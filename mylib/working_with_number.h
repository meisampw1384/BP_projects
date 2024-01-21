int sum_of_digits(int n){
    int c=0;
    while (n!=0){
        c+=n%10;
        n/=10;
    }
    return c;
}
int sumـofـprimeـfactors(int n){
    int sum=0;
    int i=2;
    while (n>=2){
        if (n%i==0){
            sum+=i;
        }
        while (n%i==0)
           n=n/i;
        i++;   
    }
  return sum;
}
int inverse_of_the_number(int n){
    int rimender;
    int result;
    while (n!=0){
        rimender=n%10;
        result=result*10+rimender;
        n/=10;
    }
    return result;
}